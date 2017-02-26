#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void strCPY(char *start, char *stop)
{
	int i;

	for(i=0;i<strlen(start);i++)
		stop[i]=start[i];
	stop[i]='\0';
}

int main(void)
{
	char *one;
	char *two;

	one=(char*)malloc(sizeof(char));
	two=(char*)malloc(sizeof(char));

	printf("input string : ");
	scanf("%s", one);

	strCPY(one, two);
	printf("my result : %s \n", two);

	strcpy(two, one);
	printf("function result : %s \n", two);

	return 0;
}
