#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

// 조금 더 긴 메시지 수신을 위하여 buffer 크기를 늘렸습니다.
#define RCVBUFSIZE 1024
#define EchoReq 01
#define FileUpReq 02
#define EchoRes 11
#define FileAck 12
#define FileListReq 03
#define FileListRes 13
#define Exit 04


void DieWithError(char *errorMessage);
void EchoLog(char *msg);

void HandleTCPClient(int clientSocket)
{
    char msgType = 0;
    char msg[RCVBUFSIZE];
    int receiveMsgSize;

    memset(msg, '\0', RCVBUFSIZE);    // null 문자로 배열 초기화

    //if ((receiveMsgSize = recv(clientSocket, msg, RCVBUFSIZE, 0)) < 0)
    //    DieWithError("recv() failed");

    while (msgType != Exit)
    {
        //recv(clientSocket, &msgType, 1, 0);

        if (msgType == FileUpReq)
        {
            char fileName[100] = {'\0', };
            receiveMsgSize = recv(clientSocket, &fileName, sizeof(fileName), 0);
            fileName[receiveMsgSize] = '\0';

            printf("file name: %s\n", fileName);
        }

        else if (msgType == EchoReq)
        {
            char echoBuffer[RCVBUFSIZE] = {'\0', };
            receiveMsgSize = recv(clientSocket, &echoBuffer, sizeof(echoBuffer), 0);
            echoBuffer[receiveMsgSize] = '\0';

            printf("Echo Msg <- ");
            puts(echoBuffer);

            send(clientSocket, &echoBuffer, sizeof(echoBuffer), 0);

            printf("Echo Msg -> ");
            puts(echoBuffer);
        }

        msgType = '\0';
        recv(clientSocket, &msgType, 1, 0);
    }

    close(clientSocket);
    exit(0);
}
