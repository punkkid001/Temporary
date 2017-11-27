#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>


void DieWithError(char *errorMessage);
int SetupTCPServerSocket(char* port);
int AcceptTCPConnection(int serverSocket);
void HandleTCPClient(int clientSocket);

void *ThreadMain(void *arg);

struct ThreadArgs
{
    int clientSocket;
};

int main(int argc, char *argv[])
{
    if (argc != 2)
        DieWithError("Usage: <Server Port>");

    char *port = argv[1];
    int serverSocket = SetupTCPServerSocket(port);
    if (serverSocket < 0)
        DieWithError("SetupTCPServerSocket() failed");

    while (1)
    {
        int clientSocket = AcceptTCPConnection(serverSocket);
        struct ThreadArgs *threadArgs = (struct ThreadArgs*)malloc(sizeof(struct ThreadArgs));

        if (threadArgs == NULL)
            DieWithError("malloc() failed");
        threadArgs->clientSocket = clientSocket;

        pthread_t tid;
        int returnValue = pthread_create(&tid, NULL, ThreadMain, (void*)threadArgs);
        if (returnValue != 0)
            DieWithError("pthread_create() failed");
    }

    return 0;
}

void *ThreadMain(void *threadArgs)
{
    pthread_detach(pthread_self());
    int clientSocket = ((struct ThreadArgs*)threadArgs)->clientSocket;

    HandleTCPClient(clientSocket);
    free(threadArgs);
    return (NULL);
}
