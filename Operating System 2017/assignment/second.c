#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef int bool;
#define TRUE 1
#define FALSE 0
#define SIZE 100

int main(void)
{
    // make pipe
    if (mkfifo("./words", 0666)<0)
        printf("Already exist!\n");
    
    char buff[SIZE];
    bool isparent = TRUE;
    int count = 0;
    
    // create child process
    for(int i=0;i<3;i++)
        if(!fork())
            isparent = FALSE;
    
    // check parent or not
    if(isparent)
    {
        int wf = open("./words",O_WRONLY);  // open pipe - write only
        int n;
        char *word, ch; // save word
        memset(buff, 0, SIZE);
        while(n=read(0, buff, SIZE))
        {
            ch = buff[0];
            word = strtok(buff, " ");   // get word
            write(wf, word, SIZE);
            //write(wf, buff, n);
            // get word (cont`)
            while(word=strtok(NULL, " "))
                write(wf, word, SIZE);  // write word to pipe
            memset(buff, 0, SIZE);  // clear buffer
            
            // counting terminated process
            if(ch=='!')
                ++count;
            if(count==7)
                break;
        }
        close(wf);
    }
    else
    {
        int rf = open("./words", O_RDONLY|O_NONBLOCK);  // open pipe - readonly, nonblock
        int m;
        printf("[Ready]PID : %d\n", getpid());

        while(TRUE)
        {
            if((m=read(rf, buff, SIZE))>0)
            {
                // check termination
                if(buff[0]=='!')
                {
                    printf("[Terminated]PID : %d\n", getpid());
                    break;
                }
                printf("[%d]%.*s\n", getpid(), m, buff);
                //usleep(5);
            }
        }
        close(rf);
    }
    return 0;
}
