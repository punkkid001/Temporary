#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strCMP(char *one, char *two)
{
	int i, cnt=0;
	int result;

	for(i=0;i<strlen(one)+1;i++)
		if(two[i]==one[i])
			cnt++;

	if(cnt==strlen(one)+1)
		result=0;
	else
		result=3;

	return result;
}

int main(void)
{
	char *str1, *str2;

	str1=(char*)malloc(sizeof(char));
	str2=(char*)malloc(sizeof(char));

	printf("input str1 : ");
	scanf("%s", str1);
	printf("input str2 : ");
	scanf("%s", str2);

	if(strCMP(str1, str2)==0)
		printf("Same \n");
	else
		printf("Not same \n");

	/*
	if(strcmp(str1, str2)==0)
		printf("same \n");
	else
		printf("not same \n");
	*/

	return 0;
}
