#include<stdio.h>
#include<unistd.h>

int main(void)
{
    int id = 0;
    for(int i=0;i<3;i++)
        if(!fork())
            id+=1<<2-i;
    printf("%d\n", id);

    return 0;
}
