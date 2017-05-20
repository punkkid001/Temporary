#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define SIZE 100

void exec(char cmd[])
{
    char *argv[10] = {0, }, *t;
    int i = 0;
    printf("[%d]token : %s\n", getpid(), cmd);
    t = strtok(cmd, " ");
    while(t!=NULL)
    {
        argv[i++] = t;
        t = strtok(NULL, " ");
    }
    execvp(argv[0], argv);
}

int main(void)
{
    pid_t parent = getpid();
    char cmd[SIZE], *token;
    int n = read(0, cmd, SIZE), child;
    
    cmd[n] = '\0';

    token = strtok(cmd, "+\n");
    while(token!=NULL)
    {
        child = fork();
        if(parent!=getpid())
            exec(token);
        waitpid(child, NULL, 0);
        token = strtok(NULL, "+\n");
    }

    return 0;
}
