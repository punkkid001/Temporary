#include<stdio.h>
#include<stdlib.h>

void DieWitherror(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}
