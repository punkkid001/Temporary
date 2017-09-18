#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>

#define RCVBUFSIZE 32

void DieWithError(char *errorMessage);

void HandleTCPClient(int clientSocket)
{
    char echoBuffer[RCVBUFSIZE];
    int receiveMsgSize;

    // client로 부터 메시지 수신
    if ((receiveMsgSize = recv(clientSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
        DieWithError("recv() failed");
    
    while (receiveMsgSize > 0)
    {
        // echo send
        if (send(clientSocket, echoBuffer, receiveMsgSize, 0) != receiveMsgSize)
            DieWithError("send() failed");

        if ((receiveMsgSize = recv(clientSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
            DieWithError("recv() failed");
    }

    close(clientSocket);    // socket close
}
