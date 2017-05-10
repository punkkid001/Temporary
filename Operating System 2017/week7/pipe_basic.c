#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(void)
{
    if(mkfifo("./fifo", 0666)<0)
        printf("already exist\n");

    char buff[100];
    int size = 10, n;

    if(!fork())
    {
        int f = open("./fifo", O_WRONLY);
        write(f, "12345", 5);
        close(f);
    }
    else
    {
        int f = open("./fifo", O_RDONLY);
        if((n=read(f, buff, size))>0)
            printf("%.*s", n, buff);
        close(f);
    }

    int stat;
    while(wait(&stat)>0);
    return 0;
}
