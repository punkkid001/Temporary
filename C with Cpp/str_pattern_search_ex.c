#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void new_strcpy(char src[], char dest[], int start, int end)
{
	int i=0;
	while(i<end)
	{
		dest[i]=src[start];
		start++;
		i++;
	}
	dest[end]='\0';
}

int new_strcmp(char src[], char dest[], int start, int end)
{
	int i=0;
	int count=0;
	int limit=end-start+1;

	while(i<limit)
	{
		if(dest[i]==src[start])
			count++;
		else
			break;
		start++;
		i++;
	}

	if(count==limit)	//0 is success
		count=0;
	else
		count=-1;	//-1 is fail
	return count;
}

int main(void)
{
	char str[]="Hello it is my world Hello. hello";
	char key[]="ello";
	char temp[5];
	int i, result;
	int count=0;

	int length_p=strlen(str)-strlen(key);

	int start=0;

	for(i=0;i<length_p+1;i++)
	{
		new_strcpy(str, temp, i, strlen(key));
		result=strcmp(key, temp);

		if(result==0)
			count++;
		start+=1;
	}

	printf("result count : %d \n", count);

	return 0;
}
