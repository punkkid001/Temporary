#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int SetupTCPServerSocket(char* port);
int AcceptTCPConnection(int server_socket);
void HandleTCPClient(int client_socket);
void DieWithError(char *error_msg);
void *ThreadMain(void *thread_args);

struct ThreadArgs
{
    int client_socket;
};

int main(int argc, char *argv[])
{
    if (argc != 2)
        DieWithError("Usage: <Server Port>");

    // Normal socket
    char *port = argv[1];
    int server_socket = SetupTCPServerSocket(port);
    if (server_socket < 0)
        DieWithError("[ERR]SetupTCPServerSocket() failed");

    while (1)
    {
        int client_socket = AcceptTCPConnection(server_socket);
        struct ThreadArgs *thread_args = (struct ThreadArgs*)malloc(sizeof(struct ThreadArgs));

        if (thread_args == NULL)
            DieWithError("[ERR]malloc() failed");
        thread_args->client_socket = client_socket;

        pthread_t tid;
        int return_val = pthread_create(&tid, NULL, ThreadMain, (void*)thread_args);
        if (return_val != 0)
            DieWithError("[ERR]pthread_create() failed");
    }

    return 0;
}

void *ThreadMain(void *thread_args)
{
    pthread_detach(pthread_self());
    int client_socket = ((struct ThreadArgs*)thread_args)->client_socket;

    HandleTCPClient(client_socket);
    free(thread_args);
    return (NULL);
}
