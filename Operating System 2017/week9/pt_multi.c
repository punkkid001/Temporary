#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int a=0;

void *print(void *param)
{
    printf("go!\n");
}

int main(void)
{
    pthread_t p[10];
    for(int i=0;i<10;i++)
        ptrhead_create(&(p[i]), NULL, print, NULL);

    for(int i=0;i<10;i++)
        pthread_join(p[i], NULL);

    printf("end\n");
    return 0;
}
