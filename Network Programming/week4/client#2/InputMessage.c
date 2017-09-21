#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

#define MSGSIZE 1024

void DieWithError(char *errorMessage);

char* InputMessage(int serverSocket)
{
    int msgSize = 0;
    char *msg = (char*)malloc(sizeof(char)*MSGSIZE);
    memset(msg, '\0', MSGSIZE);

    printf("MSG-> ");
    gets(msg);

    msgSize = strlen(msg);
    if (send(serverSocket, msg, msgSize, 0) != msgSize)
        DieWithError("send() sent a different number of bytes than expected");
    return msg;
}
