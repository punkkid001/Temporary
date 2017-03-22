#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
    int fd = open("write.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    char *buf = "Hi Nice to see you";
    int n = write(fd, buf, strlen(buf));

    printf("%d bytes written\n", n);

    return 0;
}
