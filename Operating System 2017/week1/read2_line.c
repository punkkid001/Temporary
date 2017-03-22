#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUF 10

int main(void)
{
    char buf[BUF];
    int fd = open("read2_line.c", O_RDONLY), n;

    int line = 0;

    while((n=read(fd, buf, BUF))>0)
    {
        for(int i=0;i<n;i++)
        {
            printf("%c", buf[i]);
            if(buf[i]=='\n')
                line++;
        }
    }

    printf("File Line : %d\n", line);
    return 0;
}
