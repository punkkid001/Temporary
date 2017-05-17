#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
    char buf[100];
    int n, sum=0;
    while((n=read(0, buf, 100))>0)
    {
        sum += n;
        printf("%.*s", n, buf);
    }
    printf("total %d bytes\n", sum);
    //close(f);
    return 0;
}
