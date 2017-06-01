#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(void)
{
    int sock=socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr, caddr;
    
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr =INADDR_ANY;
    addr.sin_port=htons(5101);

    if(bind(sock, (struct sockaddr*)&addr, sizeof(addr))<0||listen(sock, 5)<0)
    {
        printf("server error\n");
        return 0;
    }

    int ln=sizeof(caddr);
    int csock=accept(sock, (struct sockaddr*)&caddr, &ln);
    char buff[100];
    inet_ntop(AF_INET, &caddr.sin_addr.s_addr, buff, 100);

    printf("connect![%s]\n", buff);
    close(csock);
    close(sock);

    return 0;
}
