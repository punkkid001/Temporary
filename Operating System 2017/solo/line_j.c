#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid<0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    else if (pid==0)
    {
        execlp("/bin/ls", "ls", NULL);
        printf("LINE J\n");
    }

    else
    {
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}
