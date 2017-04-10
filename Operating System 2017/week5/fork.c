#include<stdio.h>
#include<unistd.h>

int main(void)
{
    int a=0;
    fork();
    printf("hi %d \n", a++);
    return 0;
}
