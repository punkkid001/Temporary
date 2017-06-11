nclude <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

int count = 0;
sem_t sem;

void *f(void *param){
        int id = *(int *)param;
        for(int i=0;i<10;i++){

                sem_wait(&sem);

                int a = count + 1;
                printf("%2d:%2d ", id, a );
                if(a % 10 == 0 ) printf("\n");
                count = a;

                sem_post(&sem);
        }
}
int main(){

        sem_init(&sem, 0,1);

        pthread_t p[10];
        int id[10];
        for(int i=0;i<10;i++){
                id[i] = i;
                pthread_create(&p[i], NULL, f, &id[i]);
        }
        for(int i=0;i<10;i++) pthread_join(p[i], NULL);

        printf("%d\n",count);
        return 0;
}
