#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define MAXPENDING 5

void DieWithError(char *errorMessage);

int SetupTCPServerSocket(const char *port)
{
    struct addrinfo addrCriteria;
    memset(&addrCriteria, 0, sizeof(addrCriteria));

    addrCriteria.ai_family = AF_UNSPEC;
    addrCriteria.ai_flags = AI_PASSIVE;
    addrCriteria.ai_socktype = SOCK_STREAM;
    addrCriteria.ai_protocol = IPPROTO_TCP;

    struct addrinfo *serverAddr;
    int returnValue = getaddrinfo(NULL, port, &addrCriteria, &serverAddr);
    if (returnValue != 0)
        DieWithError("getaddrinfo() failed");

    int serverSocket = -1;

    for (struct addrinfo *addr = serverAddr; addr != NULL; addr = addr->ai_next)
    {
        serverSocket = socket(serverAddr->ai_family, serverAddr->ai_socktype, serverAddr->ai_protocol);
        if (serverSocket < 0)
            continue;

        if ((bind(serverSocket, serverAddr->ai_addr, serverAddr->ai_addrlen) == 0) && (listen(serverSocket, MAXPENDING) == 0))
        {
            struct sockaddr_storage localAddr;
            socklen_t addrSize = sizeof(localAddr);
            if (getsockname(serverSocket, (struct sockaddr*)&localAddr, &addrSize) < 0)
                DieWithError("getsockname() failed");
            break;
        }

        close(serverSocket);
        serverSocket = -1;
    }

    freeaddrinfo(serverAddr);
    return serverSocket;
}
