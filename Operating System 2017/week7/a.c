#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(void)
{
    char buff[1000];
    int p = mkfifo("./ppp", 0666);
    int f = open("./ppp", O_RDWR);
    write(f, "abc", 3);

    close(f);
    return 0;
}
