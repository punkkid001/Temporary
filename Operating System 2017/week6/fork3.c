#include<stdio.h>
#include<unistd.h>

int main(void)
{
    int id=0, g=1;
    for(int i=0;i<4;i++)
        if(!fork())
            id+=1<<i;
    printf("%d\n", id);
    return 0;
}
