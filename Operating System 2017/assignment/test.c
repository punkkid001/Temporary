#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include <unistd.h>
#include <string.h>

#define SIZE 100

void exec(char cmd[])
{
    int i=0;
    printf("[%d] execute %s\n",getpid(),cmd);
    char *argv[10] = {0,};
    char *t = strtok(cmd, " ");
    while(t != NULL)
    {
        argv[i++] = t;
        t = strtok(NULL, " ");
    }

    execvp(argv[0], argv);
}

int main(void)
{
    char buff[SIZE], *argv[100];
    char *token;
    int index=0, child;
    int n = read(0,buff,SIZE);

    buff[n]='\0';

    token = strtok(buff,"+\n");
    //token = strtok(buff, "+");
    while(token!=NULL)
    {
        argv[index++] = token;
        //token = strtok(NULL, "+");
        token = strtok(NULL,"+\n");
    }
    
    for(int i=0;i<index;i++)
    {
        if(!(child=fork()))
        {
            char *cmd = argv[i];
            exec(cmd);
        }
        waitpid(child, NULL, 0);
    }

    return 0;
}
