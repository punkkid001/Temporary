#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define MAXPENDING 5

void DieWithError(char *error_msg);

int SetupTCPServerSocket(const char *port)
{
    struct addrinfo addr_criteria;
    memset(&addr_criteria, 0, sizeof(addr_criteria));

    addr_criteria.ai_family = AF_UNSPEC;
    addr_criteria.ai_flags = AI_PASSIVE;
    addr_criteria.ai_socktype = SOCK_STREAM;
    addr_criteria.ai_protocol = IPPROTO_TCP;

    struct addrinfo *server_addr;
    int return_val = getaddrinfo(NULL, port, &addr_criteria, &server_addr);
    if (return_val != 0)
        DieWithError("[ERR]getaddrinfo() failed");

    int server_socket = -1;

    for (struct addrinfo *addr = server_addr; addr != NULL; addr = addr->ai_next)
    {
        server_socket = socket(server_addr->ai_family, server_addr->ai_socktype, server_addr->ai_protocol);
        if (server_socket < 0)
            continue;

        if ((bind(server_socket, server_addr->ai_addr, server_addr->ai_addrlen) == 0) && (listen(server_socket, MAXPENDING) == 0))
        {
            struct sockaddr_storage local_addr;
            socklen_t addr_size = sizeof(local_addr);
            if (getsockname(server_socket, (struct sockaddr*)&local_addr, &addr_size) < 0)
                DieWithError("[ERR]getsockname() failed");
            break;
        }

        close(server_socket);
        server_socket = -1;
    }

    freeaddrinfo(server_addr);
    return server_socket;
}
