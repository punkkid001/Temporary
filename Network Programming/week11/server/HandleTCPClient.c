#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

void DieWithError(char *errorMessage);

void HandleTCPClient(int clientSocket)
{
    char command[BUFSIZ];
    int receiveMsgSize;

    memset(command, '\0', BUFSIZ);

    while (strcmp("/quit", echoBuffer))
    {
        memset(echoBuffer, '\0', BUFSIZ);

        if ((receiveMsgSize = recv(clientsocket, command, sizeof(command), 0)) < 0)
            DieWithError("recv() failed");

        if (strcmp(command, "download") == 0)
        {
            printf("\n");
        }
        else if (strcmp(command, "send") == 0)
        {
            printf("\n");
        }
        else if (strcmp(command, "log") == 0)
        {
            printf("\n");
        }
        else if (strcmp(command, "chat") == 0)
        {
            printf("\n");
        }
        else
        {
            printf("Invalid Command\n");
        }
        /*
        puts("MSG<- ");
        if ((receiveMsgSize = recv(clientSocket, echoBuffer, sizeof(echoBuffer), 0)) < 0)
            DieWithError("recv() failed");
        printf(echoBuffer);
        printf("\n");

        puts("MSG-> ");
        if (send(clientSocket, echoBuffer, strlen(echoBuffer), 0) != receiveMsgSize)
            DieWithError("send() failed");
        printf(echoBuffer);
        printf("\n");
        */
    }
}
