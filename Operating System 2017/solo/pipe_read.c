#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(void)
{
    char buf[1000];
    int p = mkfifo("./pipe", 0666);
    int f = open("./pipe", O_RDONLY);
    int n = read(p, buf, 1000);

    printf("%.*s", n, buf);

    close(f);

    return 0;
}
