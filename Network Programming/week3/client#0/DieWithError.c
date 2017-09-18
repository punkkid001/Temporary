#include<stdio.h>
#include<stdlib.h>

void DieWithError(char * errorMessage)
{
    perror(errorMessage);    // 에러 메시지 출력
    exit(1);    // 종료
}
