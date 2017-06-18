//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include"kusearch_process.h"

int main(int argc, char *argv[])
{ 
	key_t key=(key_t)1234;	//hard coding key value..
	int is_child,state, id;

	FILE *file_p;

	char buffer[SIZE];
	int file_n=0, i=0, j, result;	//fine_n is file line / i and j are counter for loop / result is for checking error
	int div_p, n_count=0;	//divide file line

	if(argc<3)
		exit(0);

	int count=atoi(argv[1]);    //the number of child
	int count_size=argc-3;	//the number of keywords
	int child[count+1];

	struct
	{
	    long type;
	    char text[10];
	    int start_p;
	    int call_count;
	    int search_count[count_size];	//result count
	}msg;

	file_p=fopen(argv[2], "r");
	if(file_p==NULL)
	{
	    printf("Error : Can't open file.\n");
	    exit(0);
	}

	child[count]=1234;	//checking final child..
	id=msgget(key, IPC_CREAT|0666);

	//total line..
	for(buffer[SIZE-2]=0;fgets(buffer, SIZE, file_p);buffer[SIZE-2]=0)
	    (buffer[SIZE-2]&&buffer[SIZE-2]!='\n')? : (file_n++) ;
	fseek(file_p, 0l, SEEK_SET);

	fclose(file_p);

	div_p=file_n/count;	//divide line

	msg.call_count=0;
	msg.start_p=0;	//start point of file

	//setting search count all 0
	for(j=0;j<count_size;j++)
		msg.search_count[j]=0;

	//making child process
	for(j=0;j<count;j++)
	{
		//printf("caller is %d \n", getpid());
		child[j]=fork();
		if(0<child[j])
			break;
	}	

	/*
	printf("my j is %d \n", j);
	printf("my pid is : %d \n", getpid());
	printf("my child value is : %d \n", child[j-1]);

	(except for main mother process..)
	mother process pid is child[j-1]
	child process pid is child[j]

	=> final child's child[j]=1234!
	*/

	waitpid(child[j], &state, 0);

	if(child[j]!=1234&&child[j-1]==0&&j!=0)
	{
		//receive
		result=msgrcv(id, &msg, sizeof(msg)-sizeof(long),0,0);

		if(result==-1)
		{
			perror("msgrcv fail\n");
		   	exit(1);
		}

		//printf("received data is : %s \n", msg.text);

		//send
		msg.type=1;

		//last finding
		if(msg.call_count==count-1)
		{
			final_keyword_finder(argc, argv, key, id, &msg.start_p, msg.search_count);
			++msg.call_count;
		}

		//just finding
		else
		{
			keyword_finder(argc,argv,key,id, &msg.start_p, div_p, msg.search_count);
			++msg.call_count;
		}

		sprintf(msg.text, "%d", getpid());
		//printf("snd ipc : %d \n", getpid());
		result=msgsnd(id, &msg, sizeof(msg)-sizeof(long),0);
		if(result==-1)
		{
		   	perror("msgsnd fail\n");
		   	exit(1);
		}
		exit(0);
	}

	else if(child[j]==1234)	//final child -> send a message O / receive a message X
	{
		//send
		msg.type=1;
		keyword_finder(argc,argv,key,id, &msg.start_p, div_p, msg.search_count);
		++msg.call_count;

		sprintf(msg.text, "%d", getpid());
		//printf("snd ipc : %d \n", getpid());
		result=msgsnd(id, &msg, sizeof(msg)-sizeof(long),0);
		if(result==-1)
		{
		   	perror("msgsnd fail\n");
		   	exit(1);
		}
		exit(0);
	}

	else	//main mother -> receive a message O / send a message X
	{
		//receive
		result=msgrcv(id, &msg, sizeof(msg)-sizeof(long),0,0);
		if(result==-1)
		{
			perror("msgrcv fail\n");
		   	exit(1);
		}

		//printf("received data is : %s \n", msg.text);
		print_result(argc, argv, msg.search_count);
	}

	msgctl(id, IPC_RMID, 0);	//DELETE MESSAGE QUEUE!!
	return 0;
}
