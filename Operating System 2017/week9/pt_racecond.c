#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int a=0;
void *print(void *param)
{
    printf("go!\n");
    for(int i=0;i<1000;i++)
        a++;
    return 0;
}

int main(void)
{
    int psz=10;
    pthread_t p[psz];

    for(int i=0;i<psz;i++)
        pthread_create(&(p[i]), NULL, print, &(p[i]));

    for(int i=0;i<psz;i++)
        pthread_join(p[i], NULL);
    
    printf("a count: %d\n", a);
    return 0;
}
