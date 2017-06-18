#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>

#define SIZE 1024

//function define
void keyword_finder(int argc, char **argv, key_t key, int id, int *start, int div_p, int search_count[]);   //just find
void final_keyword_finder(int argc, char **argv, key_t key, int id, int *start, int search_count[]);	//last find
int lets_search(char str[], char keyword[]);	//core of search
void n_strcpy(char src[], char dest[], int start, int max); //my new strcpy
void print_result(int argc, char **argv, int result[]);	//just print result

void keyword_finder(int argc, char **argv, key_t key, int id, int *start, int div_p, int search_count[])
{
	FILE *fp=fopen(argv[2], "r");
	int i=0, j=3, result, np;   //i is loop counter, j is keyword pointer, np is search result count pointer, result is strcmp result
	char buf[SIZE];

	if(fp==NULL)
	{
	    printf("Error : Can't open file.\n");
	    exit(0);
	}

	fseek(fp, *start, SEEK_SET);	//setting file pointer

	//call search funCtion
	for(i=0;i<div_p;i++)
	{
		fgets(buf, SIZE, fp);
		//printf("%s", buf);
		j=3;
		np=0;
		while(j<argc)
		{
			result=lets_search(buf, argv[j]);
			search_count[np]+=result;
			j++;
			np++;
		}
	}

	*start=ftell(fp);   //save final file pointer
	fclose(fp);
}

void final_keyword_finder(int argc, char **argv, key_t key, int id, int *start, int search_count[])
{
	FILE *fp=fopen(argv[2], "r");
	int j=3, result, np;	//same keyword_finder()..
	char buf[SIZE];

	fseek(fp, *start, SEEK_SET);	//setting file pointer

	//call search function
	while(fgets(buf, SIZE, fp)!=NULL)
	{
		j=3;
		np=0;
		while(j<argc)
		{
			result=lets_search(buf, argv[j]);
			search_count[np]+=result;
			j++;
			np++;
		}
	}
	*start=ftell(fp);   //save final file pointer
	fclose(fp);
}

int lets_search(char str[], char keyword[])
{
	int key_length=strlen(keyword);	    //it's keyword length
	int search_length=strlen(str)-strlen(keyword)+1;    //search_length is maximum pointer
	int i, result, find_count=0;	//i is loop counter, result is strcmp result
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

void print_result(int argc, char **argv, int result[])
{
	int i, np=0;

	for(i=3;i<argc;i++)
	{
		printf("%s : %d\n", argv[i], result[np]);
		np++;
	}
}
