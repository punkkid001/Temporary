#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(void)
{
    char buff[1000];
    int fd = dup(0);

    pipe(fd);
    while((n=read(f, buff, 1000))>0)
        printf("%.*s", n, buff);

    return 0;
}
