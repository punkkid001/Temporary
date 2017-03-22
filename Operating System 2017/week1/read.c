#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUF 1024

int main(void)
{
    char buf[BUF];
    int fd = open("read.c", O_RDONLY), n;

    while((n=read(fd, buf, BUF))>0)
    {
        printf("%.*s", n, buf);
    }
    
    return 0;
}
