#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    int fd = open("read.c", O_RDONLY);
    char buf[10];
    int n, size=0, lcount=0;
    while((n=read(fd, buf, 10))>0)
    {
        printf("%.*s", n, buf);
        lcount++;
        size+=n;
    }

    printf("read file %d lines %d bytes\n", lcount, size);
    return 0;
}
