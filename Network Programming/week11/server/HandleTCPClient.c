#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

#include<arpa/inet.h>

#include<sys/stat.h>
#include<sys/socket.h>

void DieWithError(char *error_msg);
void FileList(char *file_list);

void HandleTCPClient(int client_socket)
{
    char command[BUFSIZ] = {'\0', };
    int receive_msg_size;


    while (strcmp("/quit", command))
    {
        memset(command, '\0', sizeof(command));
        if ((receive_msg_size = recv(client_socket, command, sizeof(command), 0)) < 0)
            DieWithError("recv() failed");

        if (!strcmp(command, "/download"))
        {
            char ack_sign[4] = {'\0', };

            char file_name[BUFSIZ] = {'\0', };
            char file_list[BUFSIZ] = {'\0', };
            char file_size[BUFSIZ] = {'\0', };

            FileList(file_list);

            // Send file list
            send(client_socket, file_list, strlen(file_list), 0);
            printf("Send file list\n");

            // Get file name
            if ((receive_msg_size = recv(client_socket, file_name, sizeof(file_name), 0)) < 0)
                DieWithError("recv() failed");

            if (access(file_name, F_OK) != -1)
            {
                // File exists
                FILE *fp = fopen(file_name, "rb");
                struct stat f_stat;
                fstat(fileno(fp), &f_stat);
                sprintf(file_size, "%ld", f_stat.st_size);
                
                // Send file size
                send(client_socket, file_size, strlen(file_size), 0);

                // Get ok sign (ACK)
                recv(client_socket, &ack_sign, sizeof(ack_sign), 0);

                // Send file data
                while(!feof(fp))
                {
                    unsigned char file_data[BUFSIZ];
                    size_t size = fread(file_data, 1, sizeof(file_data), fp);
                    send(client_socket, file_data, size, 0);

                    // Get ok sign (ACK)
                    recv(client_socket, &ack_sign, sizeof(ack_sign), 0);
                }
                printf("[MSG]File send (%s) done\n", file_name);
                fclose(fp);
            }
            else
            {
                // File doesn't exist
                printf("[MSG]File send error\n");
                send(client_socket, "ERR", 4, 0);
                break;
            }
        }
        else if (!strcmp(command, "/send"))
        {
            char file_name[BUFSIZ] = {'\0', };
            char file_size[BUFSIZ] = {'\0', };

            // Send ok sign (ACK)
            send(client_socket, "ACK", 4, 0); 

            // Get file name
            if ((receive_msg_size = recv(client_socket, file_name, sizeof(file_name), 0)) < 0)
                DieWithError("[MSG]recv() failed");

            // Send ok sign (ACK)
            send(client_socket, "ACK", 4, 0);

            // Get file size
            if ((receive_msg_size = recv(client_socket, file_size, sizeof(file_size), 0)) < 0)
                DieWithError("[MSG]recv() failed");

            // Send ok sign (ACK)
            send(client_socket, "ACK", 4, 0);

            int size = atoi(file_size);
            size = size / BUFSIZ + (size % BUFSIZ ? 1 : 0);
            unsigned char file_data[BUFSIZ] = {'\0', };

            // Get file data
             FILE *fp = fopen(file_name, "wb");
             while (size--)
             {
                 int buf_len = 0;
                 buf_len = recv(client_socket, file_data, sizeof(file_data), 0);
                 fwrite(file_data, 1, buf_len, fp);

                 // Send ok sign (ACK)
                 send(client_socket, "ACK", 4, 0);
             }
             printf("[MSG]%s (%s bytes) downloading success\n", file_name, file_size);
             fclose(fp);
        }
        else if (!strcmp(command, "/chat"))
        {
            char chat_msg[BUFSIZ] = {'\0', };
            char my_msg[BUFSIZ] = {'\0', };
            char file_name[BUFSIZ] = {'\0', };

            // Send a request for file name
            send(client_socket, "REQ", 4, 0);
             // Get file name
            if ((receive_msg_size = recv(client_socket, file_name, sizeof(file_name), 0)) < 0)
                DieWithError("recv() failed");

            FILE *fp = fopen(file_name, "wb");

            // Send ok sign (ACK)
            send(client_socket, "ACK", 4, 0);

            while (strcmp(chat_msg, "/quit"))
            {
                // Get client chat message
                memset(chat_msg, '\0', sizeof(chat_msg));
                recv(client_socket, chat_msg, sizeof(chat_msg), 0);

                // Write log
                fwrite(chat_msg, 1, strlen(chat_msg), fp);

                if (!strcmp(chat_msg, "/log"))
                {
                    printf("[MSG]Sending log...");

                    char ack_sign[4] = {'\0', };
                    char file_size[BUFSIZ] = {'\0', };
                    struct stat f_stat;
                    fclose(fp);
                    fp = fopen(file_name, "rb");

                    fstat(fileno(fp), &f_stat);
                    sprintf(file_size, "%ld", f_stat.st_size);
                    
                    // Send a file size
                    send(client_socket, file_size, strlen(file_size), 0);

                    // Get ok sign (ACK)
                    recv(client_socket, &ack_sign, 4, 0); 

                    // Send a log file
                    while (!feof(fp))
                    {
                        unsigned char file_data[BUFSIZ];
                        size_t len = fread(file_data, 1, sizeof(file_data), fp);
                        
                        send(client_socket, file_data, len, 0);
                        recv(client_socket, &ack_sign, 4, 0);
                    }
                    fclose(fp);
                    fp = fopen(file_name, "wb");

                    send(client_socket, "ACK", 4, 0);
                }

                else
                {
                    printf("<< %s\n", chat_msg);

                    memset(my_msg, '\0', sizeof(my_msg));
                    printf(">> ");
                    scanf("%s", my_msg);

                    send(client_socket, my_msg, strlen(my_msg), 0);
                    fwrite(my_msg, 1, strlen(my_msg), fp);
                }
            }
            fclose(fp);
        }

        else if (!strcmp(command, "/quit"))
            printf("[MSG]Client quit\n");

        else
        {
            printf("[ERR]Invalid Command: %s\n", command);
            send(client_socket, "ERR", 4, 0);
        }
    }
}

void FileList(char *file_list)
{
    DIR *dir = opendir("./");
    struct dirent *ent;

    if (dir != NULL)
    {
        while ((ent=readdir(dir)) != NULL)
        {
            strcat(file_list, ent->d_name);
            strcat(file_list, "\n");
        }
        strcat(file_list, "\0");
        closedir(dir);
    }
    else
    {
        printf("Cannot open directory\n");
        exit(-1);
    }
}
