#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
    int pid = fork();
    srand(time(NULL)*pid);

    for(int i=0;i<1000;i++)
        printf("%d : %d \n", pid, rand()%100);
    return 0;
}
