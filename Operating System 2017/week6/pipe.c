#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(void)
{
    char buff[100];
    int f = open("mypipe", O_RDWR);
    int n = read(f, buff, 100);
    //mkfifo("mypipe", 0666);
    printf("%.*s", n, buff);
    //write(f, "1234567", 7);
    close(f);
    return 0;
}
