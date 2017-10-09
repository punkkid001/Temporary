#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>

#define MAXPENDING 5

void DieWithError(char *errorMessage);
void HandelTCPClient(int clinetSocket);

int main(int argc, char *argv[])
{
    int serverSocket;
    int clientSocket;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    
    unsigned short serverPort;
    unsigned int clientLength;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }

    serverPort = atoi(argv[1]);

    // Init Socket
    if ((serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() falied");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(serverPort);

    if (bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
        DieWithError("bind() falied");

    if (listen(serverSocket, MAXPENDING) < 0)
        DieWithError("listen() falied");

    while(1)
    {
        clientLength = sizeof(clientAddr);

        if((clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &clientLength)) < 0)
            DieWithError("accept() falied()");

        printf("[Server]Handling client %s\n", inet_ntoa(clientAddr.sin_addr));

        HandleTCPClient(clientSocket);
    }
}
