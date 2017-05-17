#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char **argv)
{
    char buf[100];
    int n, sum=0;

    int f = 0;
    if(argc>1)
        f = open(argv[1],O_RDONLY);

    while((n=read(f,buf,100))>0)
    {
        printf("%.*s", n, buf);
    }

    return 0;
}
