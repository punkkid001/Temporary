#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/wait.h>

#define MAXPENDING 5

void DieWithError(char *errorMessage);
int SetupTCPServerSocket(char* port);
int AcceptTCPConnection(int serverSocket);
void HandleTCPClient(int clientSocket);

int main(int argc, char *argv[])
{
    if (argc != 2)
        DieWithError("Usage: <Server Port>");

    char *port = argv[1];
    int serverSocket = SetupTCPServerSocket(port);
    if (serverSocket < 0)
        DieWithError("SetupTCPServerSocket() failed");

    unsigned int childProcessCount = 0;
    while (1)
    {
        int clientSocket = AcceptTCPConnection(serverSocket);
        pid_t pid = fork();
        if (pid < 0)
            DieWithError("fork() failed");
        else if (pid == 0)
        {
            close(serverSocket);
            HandleTCPClient(clientSocket);
            exit(0);
        }

        close(clientSocket);
        childProcessCount++;

        while (childProcessCount)
        {
            pid = waitpid((pid_t)-1, NULL, WNOHANG);
            if (pid < 0)
                DieWithError("waitpid() failed");
            else if (pid == 0)
                break;
            else
                childProcessCount--;
        }
    }

    return 0;
}
