#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <pthread.h>
#include "tcp_lib.h"
#include <semaphore.h>

int client[100];
int cc=0;
sem_t sem;

char log_buff[100000];
int log_p = 0;


void broadcast(char *msg, int sender){
        char buff[1000];
        sprintf(buff,"user%d:%s", sender, msg);

        for(int i=0;i<cc;i++)
                if(client[i] > 0 && i != sender ) write( client[i], buff, strlen(buff) );
}

void *serve(void *param) {

        int id = *(int*)param, n,
                sock = client[id];

        printf("connect! user%d\n",id);
        char buff[1024];

        while( ( n = read(sock, buff, 1024) ) > 0 ) {
                buff[n] = 0;
                char line[100];
                sprintf(line, "user%d:%s",id, buff);

                if(buff[0] != '/'){
                        printf("%s",line);
                        broadcast(line, id);
                        strcpy(log_buff+log_p, line);
                        log_p += strlen(line);

                }else {
                        if( !strcmp(buff, "/quit\n") ) break;
                        if( !strcmp(buff, "/history\n") ) {
                                char msg[100];
                                sprintf(msg, "------history size: %d -----\n",log_p);

                                write(sock,msg,strlen(msg));
                                write(sock,log_buff,log_p);
                        }
                }

        }
        close(sock);
}



int  main(int argc, char **argv){
        struct sockaddr caddr;
        int port = 5101;
        if( argc > 1 ) port = atoi(argv[1]);
        printf("listen at port:%d\n", port);

        int server = tcp_listen(port), len, csock;

        pthread_t p[100];
        while( (client[cc] = accept(server, &caddr, &len)) > 0 ){
                int id = cc++;
                pthread_create(&p[id], NULL, serve, &id);

        }
        close(server);

        return 0;
}
