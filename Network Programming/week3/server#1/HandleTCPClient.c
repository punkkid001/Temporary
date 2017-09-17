#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

#define RCVBUFSIZE 1024

void DieWithError(char *errorMessage);
void EchoLog(char *msg);

void HandleTCPClient(int clientSocket)
{
    char echoBuffer[RCVBUFSIZE];
    int receiveMsgSize;

    memset(echoBuffer, '\0', RCVBUFSIZE);

    if ((receiveMsgSize = recv(clientSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
        DieWithError("recv() failed");
   
    while (receiveMsgSize > 0)
    {
        if (send(clientSocket, echoBuffer, receiveMsgSize, 0) != receiveMsgSize)
            DieWithError("send() failed");

        if ((receiveMsgSize = recv(clientSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
            DieWithError("recv() failed");
    }
    
    EchoLog(echoBuffer);
    close(clientSocket);
}
