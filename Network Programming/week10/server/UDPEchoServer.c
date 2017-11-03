#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>


void DieWithError(char *errorMessage);
void HandelTCPClient(int clinetSocket);

int main(int argc, char *argv[])
{
    // argument 형식 확인 - 형식에 맞지 않으면 사용 방법 메시지 출력
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }

    char *echoServerPort = argv[1];    // argument에서 port 추출

    struct addrinfo addrCriteria;
    struct addrinfo *serverAddr;

    memset(&addrCriteria, 0, sizeof(addrCriteria));
    addrCriteria.ai_family = AF_UNSPEC;
    addrCriteria.ai_flags = AI_PASSIVE;
    addrCriteria.ai_socktype = SOCK_DGRAM;
    addrCriteria.ai_protocol = IPPROTO_UDP;
    
    int returnValue = getaddrinfo(NULL, echoServerPort, &addrCriteria, &serverAddr);
    if (returnValue != 0)
        DieWithError("getaddrinfo() failed");

    int sock = socket(serverAddr->ai_family, serverAddr->ai_socktype, serverAddr->ai_protocol);
    if (sock < 0)
        DieWithError("socket() failed");

    if (bind(sock, serverAddr->ai_addr, serverAddr->ai_addrlen) < 0)
        DieWithError("bind() failed");

    freeaddrinfo(serverAddr);

    char buffer[BUFSIZ];
    memset(buffer, '\0', BUFSIZ);
    while (strcmp(buffer, "/quit"))
    {
        struct sockaddr_storage clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        ssize_t numByteRcvd = recvfrom(sock, buffer, BUFSIZ, 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (numByteRcvd < 0)
            DieWithError("recvfrom() failed");

        buffer[numByteRcvd] = '\0';
        printf("<- %s\n", buffer);

        ssize_t numByteSent = sendto(sock, buffer, numByteRcvd, 0, (struct sockaddr*)&clientAddr, sizeof(clientAddr));
        if (numByteSent < 0)
            DieWithError("sendto() failed");
        else if (numByteSent != numByteRcvd)
            DieWithError("sentto() sent unexpected number of bytes");
        
        buffer[numByteSent] = '\0';
        printf("-> %s\n", buffer);
    }

    close(sock);
    return 0;
}
