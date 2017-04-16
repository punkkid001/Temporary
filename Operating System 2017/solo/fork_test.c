#include<stdio.h>
#include<unistd.h>

int main(void)
{
    int i;

    for(i=0;i<4;i++)
    {
        fork();
        printf("%d\n", i);
    }

    return 0;
}
