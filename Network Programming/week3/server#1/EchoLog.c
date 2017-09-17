#include<stdio.h>

void EchoLog(char *msg)
{
    FILE *fp = fopen("echo_history.log", "a");
    printf("[Server]Received: %s\n", msg);

    fputs(msg, fp);
    fputc('\n', fp);

    fclose(fp);
}
