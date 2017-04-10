#include<stdio.h>
#include<unistd.h>

int main(void)
{
    int id=fork();

    if(id>0)
        printf("I\'m parent \n");
    else
        printf("I\'m child\n");

    return 0;
}
