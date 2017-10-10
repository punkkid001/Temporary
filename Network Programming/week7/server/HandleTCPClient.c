#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>

// 조금 더 긴 메시지 수신을 위하여 buffer 크기를 늘렸습니다.
#define RCVBUFSIZE 1024
#define EchoReq 01
#define FileUpReq 02
#define EchoRes 11
#define FileAck 12
#define FileListReq 03
#define FileListRes 13
#define Exit 04
#define FileDownReq 05
#define FileDownRes 06


void DieWithError(char *errorMessage);
int FileList(char *fileList);

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
            char fileName[BUFSIZ] = {'\0', };
            char fileSize[BUFSIZ];
            unsigned char buf[BUFSIZ];

            receiveMsgSize = recv(clientSocket, fileName, sizeof(fileName), 0);
            fileName[receiveMsgSize] = '\0';

            printf("file name: %s\n", fileName);
            
            msgType = FileAck;
            send(clientSocket, &msgType, 1, 0);

            receiveMsgSize = recv(clientSocket, fileSize, sizeof(fileSize), 0);
            fileSize[receiveMsgSize] = '\0';

            receiveMsgSize = atoi(fileSize);
            receiveMsgSize = receiveMsgSize / BUFSIZ + (receiveMsgSize % BUFSIZ ? 1 : 0);

            send(clientSocket, &msgType, 1, 0);
            
            FILE *fp = fopen(fileName, "wb");

            while(receiveMsgSize--)
            {
                int bufLen = 0;
                bufLen = recv(clientSocket, buf, sizeof(buf), 0);
                fwrite(buf, 1, bufLen, fp);

                send(clientSocket, &msgType, 1, 0);
            }
        }

        else if (msgType == FileDownReq)
        {
            char fileName[BUFSIZ];
            char fileSize[BUFSIZ];
            unsigned char ack;
            struct stat fStat;
            FILE *fp;

            receiveMsgSize = recv(clientSocket, fileName, sizeof(fileName), 0);
            fileName[receiveMsgSize] = '\0';
            printf("RECV(%s)\n", fileName);

            fp = fopen(fileName, "rb");
            fstat(fileno(fp), &fStat);
            sprintf(fileSize, "%ld", fStat.st_size);
            send(clientSocket, fileSize, strlen(fileSize), 0);

            // ACK get
            recv(clientSocket, &ack, 1, 0);

            while(!feof(fp)) {
                unsigned char buf[BUFSIZ];
                size_t bufLen = fread(buf, 1, sizeof(buf), fp);
                printf("SEND %lu bytes\n", bufLen);
                send(clientSocket, buf, bufLen, 0);

                // ACK get
                recv(clientSocket, &ack, 1, 0);
            }
        }

        else if (msgType == EchoReq)
        {
            char echoBuffer[RCVBUFSIZE];// = {'\0', };
            receiveMsgSize = recv(clientSocket, echoBuffer, sizeof(echoBuffer), 0);
            echoBuffer[receiveMsgSize] = '\0';

            printf("Echo Msg <- ");
            puts(echoBuffer);

            send(clientSocket, echoBuffer, strlen(echoBuffer), 0);

            printf("Echo Msg -> ");
            puts(echoBuffer);
        }

        else if (msgType == FileListReq)
        {
            char fileList[RCVBUFSIZE] = {'\0', };
            FileList(fileList);

            // Send file List
            send(clientSocket, fileList, strlen(fileList), 0);
            printf("send file list\n");
        }

        msgType = '\0';
        recv(clientSocket, &msgType, 1, 0);
    }

    close(clientSocket);
    exit(0);
}

int FileList(char *fileList)
{
    DIR *dir = opendir("./");
    struct dirent *ent;

    if (dir != NULL)
    {
        while((ent=readdir(dir)) != NULL)
        {
            strcat(fileList, ent->d_name);
            strcat(fileList, "\n");
        }
        strcat(fileList, "\0");
        closedir(dir);
    }

    else
    {
        printf("Cannot open directory!\n");
        exit(-1);
    }

    return strlen(fileList);
}
