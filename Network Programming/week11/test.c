#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[BUFSIZ];

    printf(">> ");
    scanf("%s", str);

    if (strcmp(str, "google") == 0)
        printf("google!\n");
    else
        printf("none\n");

    return 0;
}
