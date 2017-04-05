#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
    int fd=open("write.txt", O_TRUNC|O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    char *buf="hi nice to meet you";
    int n = 0, i = 0;
    for(i=0;i<10;i++)
        n += write(fd, buf, strlen(buf));
    printf("%d byte written\n", n);
    return 0;
}
