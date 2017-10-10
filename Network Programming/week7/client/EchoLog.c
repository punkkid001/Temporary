#include<stdio.h>

// Echo log 출력 및 저장
void EchoLog(char *msg)
{
    FILE *fp = fopen("echo_history.log", "a");
    printf("[Server]Received: %s\n", msg);    // echo msg 출력

    // echo msg 저장
    fputs(msg, fp);
    fputc('\n', fp);

    fclose(fp);
}
