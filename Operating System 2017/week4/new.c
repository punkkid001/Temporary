#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(void)
{
    int fd=open("test.txt", O_WRONLY|O_TRUNC|O_CREAT, S_IRUSR|S_IWUSR);
    //char buf[1024];
    char *buf="qwertyuiopasdfghjkklzxcvbnmm";
    /*
    int n=0;
    int i=0;
    while(1)
    {
        if(i>=1024)
            break;
        n=write(fd, buf, strlen(buf));
        i+=n;
    }
    */
    //int n=write(fd, buf, 1024);
    //printf("%d byte written\n", i);

    int size=0, l=strlen(buf);
    while(size<1024)
    {
        if(size+l>1024)
            l=1024-size;
        size+=write(fd, buf, l);
    }
    return 0;
}
