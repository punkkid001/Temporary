#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int tcp_connect(char *s_ip, int port)
{
    printf("connect : %s : %d\n", s_ip, port);
    struct sockaddr_in addr;

    bzero(&addr, sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr.s_addr=inet_addr(s_ip);

    int sock=socket(AF_INET, SOCK_STREAM, 0);
    
    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr))<0)
        return -1;
    else
        return sock;
}

int tcp_listen(int port)
{
    struct sockaddr_in addr;

    bzero(&addr, sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=htonl(INADDR_ANY);
    addr.sin_port=htons(port);

    int sock=socket(AF_INET, SOCK_STREAM, 0), csock;

    if(bind(sock, (struct sockaddr*)&addr, sizeof(addr))<0||listen(sock,5)<0)
        return -1;
    else
        return sock;
}
