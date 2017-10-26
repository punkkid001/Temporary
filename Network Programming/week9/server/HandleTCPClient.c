#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>

void DieWithError(char *errorMessage);

void HandleTCPClient(int clinetSocket)
{
    char echoBuffer[BUFSIZ];
    int receiveMsgSize;

    if ((receiveMsgSize = recv(clientSocket, echoBuffer, BUFSIZ, 0)) < 0)
        DieWithError("recv() failed");

    while (receiveMsgSize > 0)
    {
        if (send(clientSocket, echoBuffer, receiveMsgSize, 0) != receiveMsgSize)
            DieWithError("send() failed");

        if ((receiveMsgSize = recv(clientSocket, echoBuffer, BUFSIZ, 0)) < 0)
            DieWithError("recv() failed");
    }

    close(clientSocket);
}
