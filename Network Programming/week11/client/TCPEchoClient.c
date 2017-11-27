#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>

void DieWithError(char *errorMessage);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in echoServerAddr;
    unsigned short echoServerPort;
    char *serverIP;
    char echoBuffer[BUFSIZ];
    int echoStringLength;
    int byteReceived, totalByteReceived;

    if ((argc < 2) || (argc > 3))
    {
        fprintf(stderr, "Usage: %s <server IP> [<Echo Port>]\n", argv[0]);
        exit(1);
    }

    serverIP = argv[1];

    if (argc == 3)
        echoServerPort = atoi(argv[2]);
    else
        echoServerPort = 7;

    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    memset(&echoServerAddr, 0, sizeof(echoServerAddr));
    echoServerAddr.sin_family = AF_INET;
    echoServerAddr.sin_addr.s_addr = inet_addr(serverIP);
    echoServerAddr.sin_port = htons(echoServerPort);

    if (connect(sock, (struct sockaddr *)&echoServerAddr, sizeof(echoServerAddr)) < 0)
        DieWithError("connect() failed");

    while (strcmp("/quit", echoBuffer))
    {
        printf("------------------------------\n");
        printf("1. File Send\n");
        printf("2. File Download\n");
        printf("3. Save log\n");
        printf("4. Chat\n");
        printf("------------------------------\n");

        memset(echoBuffer, '\0', BUFSIZ);
        printf(">> ");
        scanf("%s", echoBuffer);

        echoStringLength = strlen(echoBuffer);
        if (send(sock, echoBuffer, strlen(echoBuffer), 0) != echoStringLength)
            DieWithError("send() sent a different number of bytes than expected");

        if (recv(sock, echoBuffer, sizeof(echoBuffer), 0) <= 0)
            DieWithError("recv() failed or connection closed prematurely");

        printf("MSG<- ");
        printf(echoBuffer);
        printf("\n");
    }

    close(sock);
    return 0;
}
