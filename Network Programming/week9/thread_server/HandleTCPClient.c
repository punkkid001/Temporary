#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

void DieWithError(char *errorMessage);

void HandleTCPClient(int clientSocket)
{
    char echoBuffer[BUFSIZ];
    int receiveMsgSize;

    memset(echoBuffer, '\0', BUFSIZ);

    while (strcmp("/quit", echoBuffer))
    {
        memset(echoBuffer, '\0', BUFSIZ);

        printf("MSG<- ");
        if ((receiveMsgSize = recv(clientSocket, echoBuffer, sizeof(echoBuffer), 0)) < 0)
            DieWithError("recv() failed");
        printf(echoBuffer);
        printf("\n");

        printf("MSG-> ");
        if (send(clientSocket, echoBuffer, strlen(echoBuffer), 0) != receiveMsgSize)
            DieWithError("send() failed");
        printf(echoBuffer);
        printf("\n");
    }
}
