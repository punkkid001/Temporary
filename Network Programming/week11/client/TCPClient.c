#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<arpa/inet.h>
#include<sys/stat.h>
#include<sys/socket.h>

void DieWithError(char *error_msg);

int main(int argc, char *argv[])
{
    int sock;
    char *server_ip;
    char command[BUFSIZ] = {'\0', };
    struct sockaddr_in server_addr;
    unsigned short server_port;

    if ((argc < 2) || (argc > 3))
    {
        fprintf(stderr, "[Usage] %s <server IP>\n", argv[0]);
        exit(1);
    }

    server_ip = argv[1];
    server_port = 8888;

    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("[ERR]socket() failed");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        DieWithError("[ERR]connect() failed");

    while (strcmp("/quit", command))
    {
        // Show menu
        printf("------------------------------\n");
        printf("1. /send: File Send\n");
        printf("2. /download: File Download\n");
        printf("3. /chat: Chat\n");
        printf("4. /log: Get log\n");
        printf("5. /quit: Quit\n");
        printf("------------------------------\n");

        memset(command, '\0', sizeof(command));
        printf(">> ");
        scanf("%s", command);

        // Send a command
        send(sock, command, strlen(command), 0);

        if (!strcmp(command, "/send"))
        {
            char file_name[BUFSIZ] = {'\0', };
            char file_size[BUFSIZ] = {'\0', };
            char ack_sign[4] = {'\0', };

            recv(sock, ack_sign, sizeof(ack_sign), 0);

            printf("File Name > ");
            scanf("%s", file_name);

            // Send a file name
            send(sock, file_name, strlen(file_name), 0);
            // Get ok sign (ACK)
            recv(sock, ack_sign, sizeof(ack_sign), 0);

            FILE *fp = fopen(file_name, "rb");
            struct stat f_stat;
            fstat(fileno(fp), &f_stat);
            sprintf(file_size, "%ld", f_stat.st_size);

            // Send a file size
            send(sock, file_size, strlen(file_size), 0); 
            // Get ok sign (ACK)
            recv(sock, &ack_sign, sizeof(ack_sign), 0);

            while (!feof(fp))
            {
                unsigned char file_data[BUFSIZ];
                size_t size = fread(file_data, 1, sizeof(file_data), fp);
                
                send(sock, file_data, size, 0);
                recv(sock, &ack_sign, sizeof(ack_sign), 0);
            }
            printf("[MSG]File send (%s) done\n", file_name);
        }

        else if (!strcmp(command, "/download"))
        {
            char file_list[BUFSIZ] = {'\0', };
            char file_name[BUFSIZ] = {'\0', };
            char file_size[BUFSIZ] = {'\0', };

            // Get file list
            recv(sock, file_list, sizeof(file_list), 0);
            printf("%s\n", file_list);

            printf("File name > ");
            scanf("%s", file_name);

            // Send file name
            send(sock, file_name, strlen(file_name), 0);
            
            // Get file size
            recv(sock, file_size, sizeof(file_size), 0);

            // File doesn't exist
            if (!strcmp(file_size, "ERR"))
                break;

            int size = atoi(file_size);
            size = size / BUFSIZ + (size % BUFSIZ ? 1 : 0);
            unsigned char file_data[BUFSIZ] = {'\0', };

            // Send ok sign (ACK)
            send(sock, "ACK", 4, 0);

            FILE *fp = fopen(file_name, "wb");
            while (size--)
            {
                int buf_len = 0;
                buf_len = recv(sock, file_data, sizeof(file_data), 0);
                fwrite(file_data, 1, buf_len, fp);

                // Send ok sign (ACK)
                send(sock, "ACK", 4, 0);
            }
            printf("[MSG]%s (%s bytes) downloading success\n", file_name, file_size);
            fclose(fp);
        }

        else if (!strcmp(command, "/chat"))
        {
            char chat_msg[BUFSIZ] = {'\0', };
            char my_msg[BUFSIZ] = {'\0', };
            char ack_sign[4] = {'\0', };

            recv(sock, ack_sign, sizeof(ack_sign), 0);
            printf("log file name >> ");
            scanf("%s", my_msg);

            // Send log file name
            send(sock, my_msg, strlen(my_msg), 0);
            recv(sock, ack_sign, sizeof(ack_sign), 0);

            // Start chat
            while (strcmp(my_msg, "/quit"))
            {
                memset(my_msg, '\0', sizeof(my_msg));
                printf(">> ");
                scanf("%s", my_msg);

                send(sock, my_msg, strlen(my_msg), 0);
                memset(chat_msg, '\0', sizeof(chat_msg));
                recv(sock, chat_msg, sizeof(chat_msg), 0);
                printf("<< %s\n", chat_msg);
            }
        }

        else if (!strcmp(command, "/log"))
        {
            char ack_sign[BUFSIZ] = {'\0', };
            char file_name[BUFSIZ] = {'\0', };
            char file_size[BUFSIZ] = {'\0', };

            recv(sock, ack_sign, sizeof(ack_sign), 0);

            printf("log file name >> ");
            scanf("%s", file_name);
            send(sock, file_name, strlen(file_name), 0);

            recv(sock, file_size, sizeof(file_size), 0);
            int size = atoi(file_size);
            size = size / BUFSIZ + (size % BUFSIZ ? 1 : 0);
            unsigned char file_data[BUFSIZ] = {'\0', };
            send(sock, "ACK", 4, 0);

            FILE *fp = fopen(file_name, "wb");
            while (size--)
            {
                int buf_len = 0;
                buf_len = recv(sock, file_data, sizeof(file_data), 0);
                fwrite(file_data, 1, buf_len, fp);
                send(sock, "ACK", 4, 0);
            }
            fclose(fp);
        }

        else if (!strcmp(command, "/quit"))
            printf("[MSG]Quit...\n");

        else
        {
            char temp[BUFSIZ] = {'\0', };
            recv(sock, temp, sizeof(temp), 0);
            printf("[ERR]Invalid command\n");
        }
    }

    close(sock);
    return 0;
}
