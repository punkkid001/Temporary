#include<stdio.h>
#include<stdlib.h>

struct movie{
    char title[30];
    char director[20];
};

void print_movie(struct movie *d);
struct movie * fill(void);

int main(void){
    struct movie *d;
    d=fill();
    printf("====================\n");
    print_movie(d);

    free(d);

    return 0;
}

struct movie * fill(void){
    struct movie *m = malloc(3*sizeof(struct movie));
    printf("3개만 입력고고:\n");
    
    for(int i=0;i<3;i++){
        printf("%d. ",i+1);
        gets(m[i].title);
        puts(m[i].title);
    }

    return m;
}
void print_movie(struct movie *m){
    for(int i=0;i<3;i++){
        printf("%d. ", i+1);
        puts(m[i].title);
    }
}
