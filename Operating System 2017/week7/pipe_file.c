#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<wait.h>

typedef int bool ;
#define true 1
#define false 0

int main(int argc, char **argv)
{
    bool isparent = true;
    mkfifo("./words", 0666);
    char buff[1024];
    int n, cnt = 0;

    if(argc<2)
    {
        printf("need filename\n");
        return 0;
    }

    for(int i=0;i<3;i++)
        if(!fork())
            isparent = false;

    if(isparent)
    {
        int readf = open(argv[1], O_RDONLY), pf = open("./words", O_WRONLY);
        int p = 0;

        while((n=read(readf, buff+p, 1))>0)
        {
            cnt += n;
            if(buff[p++]=='\n')
            {
                write(pf, buff, p);
                printf("wrote %d bytes\n", p);
                p = 0;
            }
        }
        write(pf, buff, p);
        buff[0] = 0;
        
        for(int i=0;i<10000;i++)
            write(pf, buff, 1);
        close(readf);
        close(pf);
    }
    else
    {
        int pid = getpid();
        int pf = open("./words", O_RDONLY);
        while((n=read(pf, buff, 256))>0)
        {
            cnt += n;
            if(buff[0]==0)
                break;
            if(n>0)
                printf("%d: %d bytes\n%.*s\n", pid, n, n, buff);
        }
        close(pf);
    }

    int stat;
    //while(wait(&stat)>0);
    printf("%d: processed %d bytes\n", getpid(), cnt);
    return 0;
}
