#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/stat.h>

#define RCVBUFSIZE 1024
#define EchoReq 01
#define FileUpReq 02
#define EchoRes 11
#define FileAck 12
#define FileListReq 03
#define FileListRes 13
#define Exit 04
#define FileDownReq 05
#define FileDownRes 06


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
        printf("FTP command [p)ut g)et l)s r)ls e)xit] -> ");
        scanf(" %c", &command);
        
        if (command == 'p')
        {
            msgType = FileUpReq;
            send(sock, &msgType, 1, 0);
            // put file (upload file)
            char file_name[BUFSIZ] = {'\0', };
            char file_size[BUFSIZ];
            unsigned char ack;
            printf("Filename to put to server -> ");
            scanf("%s", file_name);

            send(sock, file_name, strlen(file_name), 0);
            bytesReceived = recv(sock, &msgType, 1, 0);

            struct stat fStat;
            FILE *fp = fopen(file_name, "rb");
            fstat(fileno(fp), &fStat);
            sprintf(file_size, "%ld", fStat.st_size);
            send(sock, file_size, strlen(file_size), 0);

            recv(sock, &ack, 1, 0);

            while(!feof(fp))
            {
                unsigned char buf[BUFSIZ];
                size_t bufLen = fread(buf, 1, sizeof(buf), fp);
                send(sock, buf, bufLen, 0);
                recv(sock, &ack, 1, 0);
                printf("#");
            }
        }

        else if (command == 'g')
        {
            msgType = FileDownReq;
            send(sock, &msgType, 1, 0);
            // get file (download file)
            char file_name[BUFSIZ] = {'\0', };
            char file_size[BUFSIZ];
            unsigned char buf[BUFSIZ];
            printf("Filename to get from server -> ");
            scanf("%s", file_name);
            send(sock, file_name, strlen(file_name), 0);

            bytesReceived = recv(sock, file_size, sizeof(file_size), 0);
            file_size[bytesReceived] = '\0';
            bytesReceived = atoi(file_size);
            bytesReceived = bytesReceived / BUFSIZ + (bytesReceived % BUFSIZ ? 1 : 0);

            // ACK
            buf[0] = 1;
            send(sock, buf, 1, 0);
            FILE *fp = fopen(file_name, "wb");

            while(bytesReceived--)
            {
                printf("RECV(%04d)\n", bytesReceived);
                int bufLen = 0;
                bufLen = recv(sock, buf, sizeof(buf), 0);
                printf("RECV DONE(%04d)\n", bytesReceived);
                fwrite(buf, 1, bufLen, fp);

                // ACK
                buf[0] = 1;
                send(sock, buf, 1, 0);
            }

            //download file function
        }
    
        else if (command == 'l')
        {
            msgType = FileListReq;
            send(sock, &msgType, 1, 0);

            char fileList[RCVBUFSIZE] = {'\0', };

            // Receive file name
            bytesReceived = recv(sock, fileList, sizeof(fileList), 0);
            printf("%d\n", bytesReceived);
            fileList[bytesReceived] = '\0';
            printf("**** Server File List ****\n");
            puts(fileList);
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
            bytesReceived = recv(sock, &echoBuffer, sizeof(echoBuffer), 0);
            
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
