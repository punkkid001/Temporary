#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    int n=0, gen;

    for(int i=0;i<3;i++)
    {
        if(!fork())
        {
            n++;
            gen = i;
        }
    }

    printf("%d : %d \n", n, gen);
    return 0;
}
