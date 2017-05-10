#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>

#define SIZE 1024

int main(void)
{
    int size = 100;
    char buff[SIZE];
    
    printf("hi");
    mkfifo("./fifo", 0666);
    if(!fork())
    {
        int f = open("./fifo", O_WRONLY);
        write(f, "12345", 5);
        close(f);
    }
    else
    {
        int f = open("./fifo", O_RDONLY), n;
        if((n=read(f, buff, SIZE,))>0)
            printf("%.*s", n, buff);
        close(f);
    }

    int stat;
    while(wait(&stat)>0);
    return 0;
}
