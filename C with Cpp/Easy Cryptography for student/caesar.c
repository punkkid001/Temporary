#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char abc[26], new_abc[26];	//알파벳 a~z까지 저장하기 위한 배열 (기본, 암호화&복호화 전용)
	char *string;	//평문
	char *new_string;	//암호문or복호화 된 문장
	int i, j, num=65,num2=65;	//num, num2 -> 기본 알파벳 저장, shift된 알파벳 저장에 사용
	int select, key;	//select는 암호화/복호화 모드 선택에 사용, key는 암호화/복호화에 사용되는 키 값, 

	string=(char*)malloc(sizeof(char)*100);		//문자열 값을 입력받기 위한 동적 메모리 할당
	new_string=(char*)malloc(sizeof(char)*100);

	//ASCII에서 A는 65.. -> abc[0]~abc[25] => A~Z
	for(i=0;i<26;i++)
	{
		abc[i]=num;
		num++;
	}

	/*
	for(i=0;i<26;i++)
		printf("%c \n", abc[i]);
	*/

	printf("*********시저 암호**********\n");
	printf("1. 암호화 \n");
	printf("2. 복호화 \n");
	printf(">> ");
	scanf("%d", &select);

	if(select==1)
	{
		printf("Key 값 입력 (양의 정수) : ");
		scanf("%d", &key);
		printf("PlainText 입력 (영문 - 대문자) : ");
		scanf("%s", string);

		//printf("%s \n", string);

		key%=26;	//key값 정리
		num=65;

		//SHIFT된 테이블 만들기
		for(i=0;i<26;i++)
		{
			if((num+key)>90)
			{
				new_abc[i]=num2;
				num2++;
			}
			else
			{
				new_abc[i]=num+key;
				num++;
			}
		}
		/*
		for(i=0;i<26;i++)
			printf("%c \n", new_abc[i]);
		*/
		
		//암호화
		for(i=0;i<strlen(string);i++)
		{
			for(j=0;j<26;j++)
			{
				if(string[i]==abc[j])
					new_string[i]=new_abc[j];
			}
		}
		new_string[strlen(string)]='\0';	//Null 값을 넣어줌으로서 ERROR해결 (문자열의 끝을 표시해줌..)

		printf("Encryption result : %s \n", new_string);	//암호화 결과 출력
	}
	else if(select==2)
	{
		printf("Key 값 입력 (양의 정수) : ");
		scanf("%d", &key);
		printf("CipherText 입력 (영문 - 대문자) : ");
		scanf("%s", string);

		key%=26;	//key값 정리
		num=65;

		//SHIFT된 테이블 만들기
		for(i=0;i<26;i++)
		{
			if((num+key)>90)
			{
				new_abc[i]=num2;
				num2++;
			}
			else
			{
				new_abc[i]=num+key;
				num++;
			}
		}
		/*
		for(i=0;i<26;i++)
			printf("%c \n", new_abc[i]);
		*/
		
		//복호화
		for(i=0;i<strlen(string);i++)
		{
			for(j=0;j<26;j++)
			{
				if(string[i]==new_abc[j])
					new_string[i]=abc[j];
			}
		}
		new_string[strlen(string)]='\0';	//Null 값을 넣어줌으로서 ERROR해결 (문자열의 끝을 표시해줌..)

		printf("Decryption result : %s \n", new_string);	//암호화 결과 출력
	}

	else
		printf("Wrong number! \n");

	free(string);
	free(new_string);

	return 0;
}