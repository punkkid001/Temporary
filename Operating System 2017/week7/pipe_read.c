#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#inlcude<sys/stat.h>

int main(void)
{
    char buff[1000];
    int p = mkfifo("/.ppp", 0666);
    int f = open("./ppp", O_RDONLY);

    int n = read(f, buff, 1000);
    printf("%.*s", n, buff);
    close(f);
    return 0;
}
