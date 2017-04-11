#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
    srand(time(NULL));

    for(int i=0;i<10;i++)
    {
        int r = rand()%3;
        printf("I\'ll sleep %d sec \n", r);
        fflush(stdout);
        sleep(r);
    }
    return 0;
}
