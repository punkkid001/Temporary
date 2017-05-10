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
    int gen = 0;
    
    for(int i=0;i<3;i++)
        if(!fork())
            gen++;

    if(!gen)
    {
        int f = open("./fifo", O_WRONLY);
        while(1)
        {
            int n = read(0, buff, 100);
            write(f, buff, n);
            if(buff[0]=='!')
                break;
        }

        for(int i=0;i<10;i++)
            write(f, "!", 1);
        close(f);
    }
    else
    {
        int f = open("./fifo", O_RDONLY);
        int n, bc = 0;
        printf("%d is ready\n", getpid());
        while(n=read(f, buff+bc, 1))
        {
            if(buff[bc]=='!')
                break;
            printf("%d: [%d] %.*s\n", getpid(), n, n, buff+bc);
            if(buff[bc]!='\n')
                bc++;
        }
        printf("%d total: [%d] %.*s\n", getpid(), bc, bc, buff);
        close(f);
    }

    int stat;
    while(wait(&stat)>0);
    return 0;
}
