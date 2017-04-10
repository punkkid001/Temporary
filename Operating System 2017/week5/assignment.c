#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    int pid = getpid();
    
    fork();
    srand(getpid());    // using seed value

    if (pid == getpid())
        printf("I\'m parent (pid : %d)\n", getpid());
    else
        printf("I\'m child (pid : %d)\n", getpid());

    printf("generated random number : %d\n", rand());

    return 0;
}
