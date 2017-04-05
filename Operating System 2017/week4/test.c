#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char **argv)
{
    if(argc!=3)
    {
        printf("error argument read2\n");
        return 0;
    }
    int fd_src=open(argv[1], O_RDONLY);

    int fd_dst=open(argv[2], O_TRUNC|O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
    char buf[10];
    int n, size=0, lcount=0;
    while((n=read(fd_src, buff, 10))>0)
    {
        write(fd_dst, buff, n);
        size+=n;
    }
    printf("readfile %dlines / %d bytes\n", lcount ,size);
    close(fd_src);
    close(fd_dst);
    return 0;
}
