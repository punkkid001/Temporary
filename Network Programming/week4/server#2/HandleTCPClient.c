#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

// 조금 더 긴 메시지 수신을 위하여 buffer 크기를 늘렸습니다.
#define RCVBUFSIZE 1024

char* ReceiveEcho(int clientSocket);
void SendEcho(int clientSocket, char *msg);
void DieWithError(char *errorMessage);

int HandleTCPClient(int clientSocket)
{
    char *echoBuffer = (char*)malloc(sizeof(char)*RCVBUFSIZE);
    //char echoBuffer[RCVBUFSIZE];
    int receiveMsgSize;

    memset(echoBuffer, '\0', RCVBUFSIZE);    // null 문자로 배열 초기화

    printf("MSG<- ");
    if ((receiveMsgSize = recv(clientSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
        DieWithError("recv() failed");
    printf(echoBuffer);
    printf("\n");

    while (strcmp("/quit", echoBuffer))
    {
        SendEcho(clientSocket, echoBuffer);
        memset(echoBuffer, '\0', RCVBUFSIZE);

        strcpy(echoBuffer, ReceiveEcho(clientSocket));
    }

    SendEcho(clientSocket, echoBuffer);

    close(clientSocket);
}

void SendEcho(int clientSocket, char* msg)
{
    int msgSize = strlen(msg);

    printf("MSG-> ");
    if (send(clientSocket, msg, msgSize, 0) != msgSize)
        DieWithError("send() failed");
    printf(msg);
    printf("\n");
}


char* ReceiveEcho(int clientSocket)
{
    char *msg = (char*)malloc(sizeof(char)*RCVBUFSIZE);
    memset(msg, '\0', RCVBUFSIZE);

    printf("MSG<- ");
    if (recv(clientSocket, msg, RCVBUFSIZE, 0) < 0)
        DieWithError("recv() failed");
    printf(msg);
    printf("\n");

    return msg;
}
