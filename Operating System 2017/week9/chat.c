#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<pthread.h>
#include"tcp_lib.h"

int client[100];
int cc=0;

int tcp_listen(int port)
{
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr=htonl(INADDR_ANY);
    addr.sin_port=htons(port);

    int sock=socket(AF_INET, SOCK_STREAM, 0), csock;

    if(bind(sock, (struct sockaddr*)&addr, sizeof(addr))<0||listen(sock,5)<0)
        return -1;
    else
        return sock;
}

void broadcast(char *msg)
{
    for(int i=0;i<cc;i++)
        if(client[i]>0)
            write(client[i], msg, strlen(msg));
}

void *serve(void *param)
{
    printf("connect!\n");
    int client=*(int*)param, n;
    char buff[1024];
    
    while((n=read(client, buff, 1024))>0)
    {
        buff[n]=0;
        printf("%s\n", buff);
        broadcast(buff);
        if(!strcmp(buff, "quit"))
            break;
    }
    close(client);
}

int main()
{
    struct sockaddr caddr;
    int server=tcp_listen(5101), len, n;
    pthread_t p[100];

    while((cleint[cc]=accept(server, &cadder, &len))>0)
    {
        pthread_create(&p[cc], NULL, serve, &client[cc]);
        cc++;
    }
    close(server);

    return 0;
}
