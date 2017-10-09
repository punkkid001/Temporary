#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>

#define SIZE 1024

void socketInit(int *sock, struct sockaddr_in )
{
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < )
        DieWithError("socket() failed");

    memset(&serverIP, 0, sizeof(serverIP));

