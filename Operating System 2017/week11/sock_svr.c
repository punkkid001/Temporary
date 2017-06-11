nclude <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
int  main(){

        struct sockaddr_in addr, caddr;

        int ssock = socket(AF_INET,  SOCK_STREAM, 0), csock;
        int port = 5101;

        bzero(&addr,  sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr.sin_port = htons(port);

        if( bind(ssock, (struct  sockaddr*) &addr, sizeof(addr)) < 0 ||
                listen(ssock ,5) < 0 ){
                printf("try listen error");
                return 0;
        }

        int len,n;
        csock = accept(ssock,(struct sockaddr*) &caddr, &len);
        printf("connect!\n");

        char buff[1024];
        n = read(csock, buff, 1024) ;

        if(n > 0) {
                buff[n-1] = 0;
                printf("%s\n", buff );
                write(csock, "welcome", 7);
        }

        close(csock);
        close(ssock);
        return 0;
}
