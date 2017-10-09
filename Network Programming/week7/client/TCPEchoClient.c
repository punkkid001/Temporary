#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>

#define RCVBUFSIZE 1024
#define EchoReq 01
#define FileUpReq 02
#define EchoRes 11
#define FileAck 12
#define FileListReq 03
#define FileListRes 13
#define Exit 04


void DieWithError(char *errorMessage);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serverAddr;
    unsigned short serverPort;
    char *serverIP;
    char msgType, command = 0;
    int bytesReceived;

    if ((argc < 3) || (argc > 3))
    {
        fprintf(stderr, "Usage: %s <Server IP> <Echo Port>\n", argv[0]);
        exit(1);
    }

    serverIP = argv[1];
    serverPort = atoi(argv[2]);

    // Init Socket
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);
    serverAddr.sin_port = htons(serverPort);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
        DieWithError("connect() failed");

    printf("Welcome to Socket FT client!\n");

    // Input Operations
    while (1)
    {
        fseek(stdin, 0, SEEK_END);
        printf("FTP command [p)ut g)et l)s r)ls e)xit] -> ");
        scanf(" %c", &command);
        
        if (command == 'p')
        {
            msgType = FileUpReq;
            send(sock, &msgType, 1, 0);
            // put file (upload file)
            char file_name[100] = {'\0', };
            printf("Filename to put to server -> ");
            scanf("%s", file_name);

            send(sock, file_name, strlen(file_name), 0);
            //upload file function
        }

        else if (command == 'g')
        {
            msgType = FileAck;
            send(sock, &msgType, 1, 0);
            // get file (download file)
            char file_name[100] = {'\0', };
            printf("Filename to get from server -> ");
            scanf("%s", file_name);

            send(sock, file_name, strlen(file_name), 0);
            
            //download file function
        }
    
        else if (command == 'l')
        {
            msgType = FileListReq;
            //send(sock, &msgType, 1, 0);
            // ls (get list of files)
            //receive file list from server
        }

        else if (command == 'r')
        {
            msgType = EchoReq;
            send(sock, &msgType, 1, 0);

            char echoBuffer[RCVBUFSIZE] = {'\0', };
            printf("Echo Msg -> ");
            scanf("%s", echoBuffer);
            
            send(sock, &echoBuffer, strlen(echoBuffer), 0);
            bytesReceived = recv(sock, &echoBuffer, strlen(echoBuffer), 0);
            
            echoBuffer[bytesReceived] = '\0';
            printf("Echo Msg <- ");
            puts(echoBuffer);
            printf("\n");
            // rls
        }

        else if (command == 'e')
        {
            msgType = Exit;
            send(sock, &msgType, 1, 0);
            close(sock);
            return 0;
        }
    }
}
