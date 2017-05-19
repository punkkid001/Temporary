#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(void)
{
    if(mkfifo("./fifo", 0666)<0)
        printf("already exist\n");

    char buff[100], size = 10;
    int n;
    if(!fork())
    {
        int f = open("./fifo", O_WRONLY);
        while(n=read(0, buff, size))
        {
            printf("parent: %.*s\n", n, buff);
            write(f, buff, n);
            if(buff[0]=='!')
                break;
        }
        close(f);
        printf("close p\n");
    }
    else
    {
        int f = open("./fifo", O_RDONLY);
        while(1)
        {
            if(n=read(f, buff, size))
            {
                printf("child: %.*s\n", n, buff);
                if(buff[0]=='!')
                    break;
            }
        }
        close(f);
        printf("close c\n");
    }

    int stat;
    while(wait(&stat)>0);
    return 0;
}
