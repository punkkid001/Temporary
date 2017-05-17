#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void exec(char cmd[])
{
    printf("%s\n", cmd);
    int i=0;
    char *argv[100]={0,};
    char *t = strtok(cmd, " ");

    while(t!=NULL)
    {
        argv[i++]=t;
    	strtok(NULL, " ");
    }
    printf("%s\n", *argv);
    execvp(argv[0], argv);
}

int main(void)
{
    char cmd[100] = "ls -s /etc";
    exec(cmd);
    /*
    char *argv[3] = {"ls", "-l", NULL}
    execvp(argv[0], argv);
    //execlp("ls", "ls", "-l", "/etc", NULL);
    */
    return 0;
}
