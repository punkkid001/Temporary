#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <pthread.h>
#include "tcp_lib.h"

int client[100];
int cc=0;

void *serve(void *param) ;
void broadcast(char *msg);

int  main(int argc, char **argv){
        struct sockaddr caddr;
        int port = 5101;
        if( argc > 1 ) port = atoi(argv[1]);


        int server = tcp_listen(port), len, csock;

        pthread_t p[100];
        while( (client[cc] = accept(server, &caddr, &len)) > 0 ){
                pthread_create(&p[cc], NULL, serve, &client[cc++]);

        }
        close(server);

        return 0;
}


void *serve(void *param) {

        int sock = *(int*)param, n;
        printf("connect! user\n");

        char buff[1024];
        while( ( n = read(sock, buff, 1024) ) > 0 ) {
                buff[n] = 0;
                printf("%s", buff);
                broadcast(buff);
                if( !strcmp(buff, "quit\n") ) break;
        }
        close(sock);
}

void broadcast(char *msg){

        for(int i=0;i<cc;i++)
                write( client[i], msg, strlen(msg) );
}
