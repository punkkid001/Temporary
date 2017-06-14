#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(void)
{
    char buf[1000];
    int p = mkfifo("./pipe", 0666);
    int f = open("./pipe", O_RDWR);

    write(f, "abc", 3);

    close(f);
    return 0;
}
