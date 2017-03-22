#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUF 10

int main(void)
{
    char buf[BUF];
    int fd = open("read2.c", O_RDONLY), n;

    while((n=read(fd, buf, BUF))>0)
    {
        for(int i=0;i<n;i++)
            printf("%c", buf[i]);
    }

    return 0;
}
