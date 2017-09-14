#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>

#define RCVBUFSIZE 32

void DieWithError(char *errorMessage);

void HandleTCPClient(int clientSocket)
{
    char echoBuffer[RCVBUFSIZE];
    int receiveMsgSize;

    if ((receiveMsgSize = recv(clientSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
        DieWithError("recv() failed");
    
    while (receiveMsgSize > 0)
    {
        if (send(clientSocket, echoBuffer, receiveMsgSize, 0) != receiveMsgSize)
            DieWithError("send() failed");

        if ((receiveMsgSize = recv(clientSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
            DieWithError("recv() failed");
    }

    close(clientSocket);
}
