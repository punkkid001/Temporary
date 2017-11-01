#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<arpa/inet.h>

void DieWithError(char *errorMessage);

int AcceptTCPConnection(int serverSocket)
{
    //struct sockaddr_storage clientAddr;
    struct sockaddr clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket < 0)
        DieWithError("accept() failed");

    return clientSocket;
}
