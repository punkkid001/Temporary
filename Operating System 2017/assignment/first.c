#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

// How to Use
// ./a.out 5 google facebook kakao naver github test
// [1]google
// [2]facebook
// [3]kakao
// [4]naver
// [5]github test

int main(int argc, char *argv[])
{
    int i, count, value;

    if (argc<3)
    {
        printf("Error!\n");
        exit(0);
    }

    count = atoi(argv[1]);
    int child[count];

    value = (argc-2) / count;

    for(i=0; i<count-1; i++)
    {
        child[i] = fork();
        if (0<child[i])
            break;
    }

    printf("[%d] ", i);

    // last process
    if (i==(count-1))
    {
        int v = i * value;
        while(v<argc-2)
        {
            printf("%s ", argv[v+2]);
            v++;
        }
        printf("\n");
    }

    // not a last process
    else
    {
        int v = i * value;
        int v2 = v + value;
        while (v<v2)
        {
            printf("%s ", argv[v+2]);
            v++;
        }
        printf("\n");
    }

    return 0;
}
