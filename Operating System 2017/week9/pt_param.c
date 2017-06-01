#include<stdio.h>
#include<unistd.h>
#include<ptrhead.h>

void *print(void *param)
{
    int *x=param;
    printf("go!%d\n", *x);
}

int main(void)
{
    ptrhead_t p;
    int x=10;
    pthread_create(&p, NULL, print, &x);
    pthread_join(p, NULL);

    return 0;
}
