nclude <stdio.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;

void *f(void *param){
        for(int i=0;i<10;i++){
                int a = count + 1;
                printf("%d\n", a);
                count = a;
        }
}

int main(){
        pthread_t p[10];
        for(int i=0;i<10;i++)
                pthread_create(&p[i], NULL, f, NULL);
        for(int i=0;i<10;i++)
                pthread_join(p[i], NULL);
        printf("total count;%d\n",count);
        return 0;
}
