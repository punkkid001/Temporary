#include<stdio.h>
#include<stdlib.h>

void DieWithError(char *error_msg)
{
    perror(error_msg);
    exit(1);
}
