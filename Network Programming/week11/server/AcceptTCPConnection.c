#include<stdio.h>
#include<stdlib.h>

#include<arpa/inet.h>
#include<sys/socket.h>

void DieWithError(char *error_msg);

int AcceptTCPConnection(int server_socket)
{
    //struct sockaddr_storage clientAddr;
    struct sockaddr client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_socket < 0)
        DieWithError("[ERR]accept() failed");

    return client_socket;
}
