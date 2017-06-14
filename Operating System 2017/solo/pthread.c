#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int a = 0;

void *print(void *param)
{
    int x = (int*)param - &a;
    printf("go %d\n", x);
}

int main(void)
{
    pthread_t p[10];

    for(int i=0;i<10;i++)
        pthread_create(&p[i], NULL, print, &a+i);

    for(int i=0;i<10;i++)
        pthread_join(p[i], NULL);

    printf("end\n");
    return 0;
}
