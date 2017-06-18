//#include<stdio.h>
//#include<stdlib.h>
//#include<unistd.h>
//#include<pthread.h>
#include"kusearch_thread.h"

//#define SIZE 1024

int main(int argc, char *argv[])
{
	FILE *file_p;

	int count, count_size;

	char buffer[SIZE];
	int file_n=0, i=0, j, result;
	int div_p;

	if(argc<3)
		exit(0);

	count=atoi(argv[1]);
	count_size=argc-3;

	pthread_t thread[count];
	void *t_return=NULL;
	pthread_mutex_init(&mutex, NULL);   //mutex setting

	my_argv=argv;
	my_argc=argc;

	file_p=fopen(argv[2], "r");
	if(file_p==NULL)
	{
	    perror("Error : Can't open file.\n");
	    exit(0);
	}

	//total file line..
	for(buffer[SIZE-2]=0;fgets(buffer, SIZE, file_p);buffer[SIZE-2]=0)
	    (buffer[SIZE-2]&&buffer[SIZE-2]!='\n')? : (file_n++) ;

	fseek(file_p, 0l, SEEK_SET);
	fclose(file_p);

	div_p=file_n/count;	//divide file line
	search_result=(int*)malloc(sizeof(int)*count_size); //memory allocation

	//setting memory value (0)
	for(i=0;i<count_size;i++)
		search_result[i]=0;

	//making thread
	for(i=0;i<count-1;i++ )
	{
		pthread_create(&thread[i], NULL, keyword_finder, (void*)&div_p);
		pthread_join(thread[i], &t_return);
	}

	//final thread..
	pthread_create(&thread[i+1], NULL, final_keyword_finder, NULL);
	pthread_join(thread[i+1], &t_return);

	pthread_mutex_destroy(&mutex);	//del mutex

	print_result();

	free(search_result);
	return 0;
}
