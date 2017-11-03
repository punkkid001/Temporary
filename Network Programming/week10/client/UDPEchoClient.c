#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>

#include<sys/socket.h>
#include<arpa/inet.h>


void DieWithError(char *errorMessage);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <Server IP> <Echo Port>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *serverPort = argv[2];

    struct addrinfo addrCriteria;
    memset(&addrCriteria, 0, sizeof(addrCriteria));
    addrCriteria.ai_family = AF_UNSPEC;
    addrCriteria.ai_socktype = SOCK_DGRAM;
    addrCriteria.ai_protocol = IPPROTO_UDP;

    struct addrinfo *serverAddr;
    int returnValue = getaddrinfo(server, serverPort, &addrCriteria, &serverAddr);
    if (returnValue != 0)
        DieWithError("getaddrinfo() failed");

    int sock = socket(serverAddr->ai_family, serverAddr->ai_socktype, serverAddr->ai_protocol);
    if (sock < 0)
        DieWithError("socket() failed");

    struct sockaddr_storage fromAddr;
    socklen_t fromAddrLen = sizeof(fromAddr);

    char buffer[BUFSIZ];
    memset(buffer, '\0', BUFSIZ);
    while (strcmp(buffer, "/quit"))
    {
        printf("-> ");
        scanf("%s", buffer);

        ssize_t numByte = sendto(sock, buffer, strlen(buffer), 0, serverAddr->ai_addr, serverAddr->ai_addrlen);
        if (numByte < 0)
            DieWithError("sendto() failed");
        else if (numByte != strlen(buffer))
            DieWithError("sendto() error - sent unexpected number of bytes");
        
        numByte = recvfrom(sock, buffer, BUFSIZ, 0, (struct sockaddr*)&fromAddr, &fromAddrLen);
        if (numByte < 0)
            DieWithError("recv() failed");
        else if (numByte != strlen(buffer))
            DieWithError("recvfrom() received a packet from unknown source");

        buffer[numByte] = '\0';
        printf("<- %s\n", buffer);
    }

    freeaddrinfo(serverAddr);
    close(sock);
    return 0;
}
