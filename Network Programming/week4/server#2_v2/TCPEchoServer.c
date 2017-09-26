#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>

#define MAXPENDING 5

int DieWithError(char *errorMessage);
void HandelTCPClient(int clinetSocket);

int main(int argc, char *argv[])
{
    int serverSocket;
    int clientSocket;

    struct sockaddr_in echoServerAddr;
    struct sockaddr_in echoClientAddr;
    
    unsigned short echoServerPort = 1080;
    unsigned int clientLength;

    char msgBuffer[1024];
    int receiveMsgSize;

    if ((serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() falied");

    memset(&echoServerAddr, 0, sizeof(echoServerAddr));
    echoServerAddr.sin_family = AF_INET;
    echoServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    echoServerAddr.sin_port = htons(echoServerPort);

    if (bind(serverSocket, (struct sockaddr *) &echoServerAddr, sizeof(echoServerAddr)) < 0)
        DieWithError("bind() falied");

    if (listen(serverSocket, MAXPENDING) < 0)
        DieWithError("listen() falied");

    while(1)
    {
        clientLength = sizeof(echoClientAddr);

        if((clientSocket = accept(serverSocket, (struct sockaddr *) &echoClientAddr, &clientLength)) < 0)
            DieWithError("accept() falied()");

        printf("Client IP: %s\n", inet_ntoa(echoClientAddr.sin_addr));
        printf("Port: %u\n", echoServerPort);

        if ((receiveMsgSize = recv(clientSocket, msgBuffer, 1024, 0)) < 0)
            DieWithError("recv() failed");

        printf("first hello\n");
        if (!strcmp("hello", msgBuffer))
        {
            printf("second hello\n");
            printf("MSG<- %s\n", msgBuffer);
            if (send(clientSocket, "hi", 3, 0) != 3)
                DieWithError("send() failed");
            printf("MSG-> %s\n", "hi");
            printf("last hello\n");
        }

        HandleTCPClient(clientSocket);
	break;
    }
}
