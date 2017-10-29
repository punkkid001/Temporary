#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<arpa/inet.h>

void DieWithError(char *errorMessage);

int AcceptTCPConnection(int serverSocket)
{
    struct sockaddr_storage clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket < 0)
        DieWithError("accept() failed");

    //printf("[Server]Handling Client %s\n", inet_ntoa(clientAddr.sin_addr));
    
    return clientSocket;
}
