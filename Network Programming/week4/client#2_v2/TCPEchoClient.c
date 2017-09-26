#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>

#define RCVBUFSIZE 1024

void DieWithError(char *errorMessage);
char* InputMessage(int serverSocket);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in echoServerAddr;
    unsigned short echoServerPort;
    char serverIP[21];
    char *echoString;
    char echoBuffer[RCVBUFSIZE];
    unsigned int echoStringLength;
    int bytesReceived, totalBytesReceived;

    printf("Server IP: ");
    scanf("%s", serverIP);
    printf("Port: ");
    scanf("%u", &echoServerPort);

    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    echoString = (char*)malloc(sizeof(char)*RCVBUFSIZE);

    memset(&echoBuffer, '\0', RCVBUFSIZE);
    memset(&echoServerAddr, 0, sizeof(echoServerAddr));
    echoServerAddr.sin_family = AF_INET;
    echoServerAddr.sin_addr.s_addr = inet_addr(serverIP);
    echoServerAddr.sin_port = htons(echoServerPort);

    if (connect(sock, (struct sockaddr *) &echoServerAddr, sizeof(echoServerAddr)) < 0)
        DieWithError("connect() failed");

    printf("MSG-> hello\n");
    if (send(sock, "hello", 6, 0) != 6)
        DieWithError("send() sent a different number of bytes than expected");

    totalBytesReceived = 0;

    printf("MSG<- ");
    if ((bytesReceived = recv(sock, echoBuffer, RCVBUFSIZE, 0)) <= 0)
        DieWithError("recv() falied or connection closed prematurely");
    totalBytesReceived += bytesReceived;
    printf(echoBuffer);
    printf("\n");

    while (strcmp("/quit", echoBuffer))
    {
        memset(echoBuffer, '\0', RCVBUFSIZE);
        strcpy(echoBuffer, InputMessage(sock));

        echoStringLength = strlen(echoBuffer);
        totalBytesReceived = 0;
        
        //printf("MSG<- ");
        while (totalBytesReceived < echoStringLength)
        {
            memset(echoBuffer, '\0', RCVBUFSIZE);
            if ((bytesReceived = recv(sock, echoBuffer, RCVBUFSIZE, 0)) <= 0)
                DieWithError("recv() failed or connection closed prematurely");
            totalBytesReceived += bytesReceived;
            //printf(echoBuffer);
        }
        printf("MSG<- ");
        printf(echoBuffer);
        printf("\n");
    }
    close(sock);
    exit(0);
}
