#include<stdio.h>
#define SIZE 10

int result;
int g, h;

int main(void)
{
    int i=0;
    int state = 1;
    FILE *fp=fopen("input.txt", "r");
    int L[SIZE];

    while((state=fscanf(fp, "%d", &L[i]))!=EOF)
    {
        printf("%d\n", L[i]);
        i++;
    }
    fclose(fp);
    return 0;
}
