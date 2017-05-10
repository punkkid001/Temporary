#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char **argv)
{
    char buff[1000];
    int fdin, fdout, n, p=0, c=0, loop=0;

    fdout = dup(1);

    if(argc>1)
        loop = argc -1;
    else
        fdin = dup(0), loop = 1, loop = 1;

    for(int i=0;i<loop;i++)
    {
        if(argc>1)
            fdin = open(argv[i+1], O_RDONLY);
        while((n=read(fdin, buff+p, 1))>0)
        {
            if(buff[p]=='\n'||buff[p]==' '||buff[p]=='\t')
            {
                char str[1000];
                sprintf(str, "%.*s\n", p, buff);
                if(p>0)
                    write(fdout, str, strlen(str));
                p = 0;
            }
            else
                p++;
        }
        close(fdin);
    }
    return 0;
}
