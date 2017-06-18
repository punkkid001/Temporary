#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

#define SIZE 1024

int *search_result;	//save a search result
int start=0;	//setting start pointer
int my_argc=0;	//save argc from main function
char **my_argv;	//save argv from main
pthread_mutex_t mutex;

//function define
void *keyword_finder(void* div_p);
void *final_keyword_finder(void *arg);
int lets_search(char str[], char keyword[]);	//search function
void n_strcpy(char src[], char dest[], int start, int max); //my new string copy function
void print_result(void);    //just print result..

void *keyword_finder(void *div_p)
{
	FILE *fp=fopen(my_argv[2], "r");
	int i=0, j=3, result, np;
	char buf[SIZE];
	int my_div=*(int*)div_p;

	if(fp==NULL)
	{
		perror("File open error : ");
		exit(0);
	}

	fseek(fp, start, SEEK_SET); //setting file pointer

	pthread_mutex_lock(&mutex); //let it lock!
	for(i=0;i<my_div;i++)
	{
		fgets(buf, SIZE, fp);
		//printf("%s", buf);
		j=3;
		np=0;
		while(j<my_argc)
		{
			result=lets_search(buf, my_argv[j]);	//call search function
			//printf("result : %d \n", result);
			search_result[np]+=result;
			j++;
			np++;
		}
	}
	//printf("*******************\n");

	start=ftell(fp);

	pthread_mutex_unlock(&mutex);	//let it unlock!
	fclose(fp);
}

void *final_keyword_finder(void *arg)
{
	FILE *fp=fopen(my_argv[2], "r");
	int j=3, result, np;
	char buf[SIZE];

	fseek(fp, start, SEEK_SET); //~same keyword_finder()

	while(fgets(buf, SIZE, fp)!=NULL)
	{
		//printf("%s", buf);
		j=3;
		np=0;
		while(j<my_argc)
		{
			result=lets_search(buf, my_argv[j]);
			search_result[np]+=result;
			j++;
			np++;
		}
	}

	start=ftell(fp);
	fclose(fp);
}

int lets_search(char str[], char keyword[])
{
	int key_length=strlen(keyword);
	int search_length=strlen(str)-strlen(keyword)+1;
	int i, result, find_count=0;
	char temp[key_length];

	for(i=0;i<search_length;i++)
	{
		n_strcpy(str, temp, i, key_length);
		result=strcmp(keyword, temp);

		if(result==0)
			find_count++;
	}

	return find_count;
}

void n_strcpy(char src[], char dest[], int start, int max)
{
	int i=0;
	while(i<max)
	{
		dest[i]=src[start];
		start++;
		i++;
	}
	dest[max]='\0';
}

void print_result(void)
{
	int i, np=0;

	for(i=3;i<my_argc;i++)
	{
		printf("%s : %d\n", my_argv[i], search_result[np]);
		np++;
	}
}
