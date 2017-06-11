nclude <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



int main(int argc , char **argv){

        char *s_ip = "127.0.0.1";
        int port = 5101;

        struct sockaddr_in addr;

        bzero(&addr, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(s_ip);

        int sock = socket(AF_INET,  SOCK_STREAM, 0);

        if( connect( sock, (struct sockaddr*) &addr, sizeof(addr)) < 0 )
                return -1;

        char buff[100];
        write(sock, "hi ", 3 );
        int n = read(sock, buff, 100);
        printf("%.*s\n",n,buff);

        return 0;
}
