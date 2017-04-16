#include<stdio.h>
#include<unistd.h>

int value=5;

int main(void)
{
    pid_t pid, pid1=0;

    pid=fork();

    if(pid==0)
    {
        value+=10;
        pid1=fork();

        if(pid1==0)
        {
            value+=3;
            printf("[3]pid : %d / pid1 : %d / value : %d\n", pid, pid1, value);
            return 0;
        }

        wait(NULL);
        printf("[2]pid : %d / pid1 : %d / value : %d\n", pid, pid1, value);
        return 0;
    }

    else if(pid>0)
    {
        wait(NULL);
        printf("[1]pid : %d / pid1 : %d / value : %d\n", pid, pid1, value);
        return 0;
    }

    return 0;
}
