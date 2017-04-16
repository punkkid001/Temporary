#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(void)
{
    pid_t pid = fork();

    //error
    if (pid<0)
    {
        printf("Fork Failed");
        return 1;
    }

    //child
    else if (pid==0)
        execlp("/bin/ls", "ls", NULL);

    //parent
    else
    {
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}
