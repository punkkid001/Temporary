#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

// 조금 더 긴 메시지 수신을 위하여 buffer 크기를 늘렸습니다.
#define RCVBUFSIZE 1024

void DieWithError(char *errorMessage);
void EchoLog(char *msg);

void HandleTCPClient(int clientSocket)
{
    char echoBuffer[RCVBUFSIZE];
    int receiveMsgSize;

    memset(echoBuffer, '\0', RCVBUFSIZE);    // null 문자로 배열 초기화

    if ((receiveMsgSize = recv(clientSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
        DieWithError("recv() failed");
   
    while (receiveMsgSize > 0)
    {
        if (send(clientSocket, echoBuffer, receiveMsgSize, 0) != receiveMsgSize)
            DieWithError("send() failed");

        if ((receiveMsgSize = recv(clientSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
            DieWithError("recv() failed");
    }
    
    EchoLog(echoBuffer);    // Echo log 출력 및 저장
    close(clientSocket);
}
