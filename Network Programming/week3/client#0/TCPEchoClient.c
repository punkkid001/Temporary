#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>

#define RCVBUFSIZE 32

void DieWithError(char *errorMessage);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in echoServerAddr;
    unsigned short echoServerPort;
    char *serverIP;
    char *echoString;
    char echoBuffer[RCVBUFSIZE];
    unsigned int echoStringLength;
    int bytesReceived, totalBytesReceived;

    // argument 확인 - 형식에 맞지 않는 경우 사용 방법 메시지 출력
    if ((argc < 3) || (argc > 4))
    {
        fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
        exit(1);
    }

    // argument 저장
    serverIP = argv[1];
    echoString = argv[2];

    // port에 관한 argument 확인
    if (argc == 4)
        echoServerPort = atoi(argv[3]);    // 10진 정수 문자열 -> 정수 변환(port)
    else
        echoServerPort = 7;    // default port = 7
    
    // socket 생성
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    memset(&echoServerAddr, 0, sizeof(echoServerAddr));    // 0으로 배열 초기화
    echoServerAddr.sin_family = AF_INET;
    echoServerAddr.sin_addr.s_addr = inet_addr(serverIP);
    echoServerAddr.sin_port = htons(echoServerPort);

    // connect
    if (connect(sock, (struct sockaddr *) &echoServerAddr, sizeof(echoServerAddr)) < 0)
        DieWithError("connect() failed");

    echoStringLength = strlen(echoString);

    // send
    if (send(sock, echoString, echoStringLength, 0) != echoStringLength)
        DieWithError("send() sent a different number of bytes than expected");

    totalBytesReceived = 0;
    printf("[Client]Received: ");
    while (totalBytesReceived < echoStringLength)
    {
        // server로 부터 메시지 수신 및 출력
        if ((bytesReceived = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0)
            DieWithError("recv() failed or connection closed prematurely");
        totalBytesReceived += bytesReceived;
        echoBuffer[bytesReceived] = '\0';
        printf(echoBuffer);
    }

    printf("\n");
    close(sock);
    exit(0);
}
