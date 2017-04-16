#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(void)
{
    pid_t pid = fork();
    pid_t pid1;

    if (pid<0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid==0)
    {
        pid1 = getpid();
        printf("(A) Child - pid : %d\n", pid);
        printf("(B) Child - pid1 : %d\n", pid1);
    }
    else
    {
        pid1 = getpid();
        printf("(C) Parent - pid : %d\n", pid);
        printf("(D) Parent - pid1 : %d\n", pid1);
    }

    return 0;
}
