#include<stdio.h>
#include<unistd.h>

int main(void)
{
    int gen = 0;
    for(int i=0;i<3;i++)
        if(!fork())
            gen++;
    printf("gen%d : %d\n", gen, getpid());

    return 0;
}
