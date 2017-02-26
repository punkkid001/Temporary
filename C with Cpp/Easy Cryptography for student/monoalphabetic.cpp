#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//중복 문자 체크를 위한 'bool'의 사용으로 어쩔 수 없이 '*.cpp'로 코딩하게 됨

bool bString[26]={0,};	//알파벳이 있었는지 체크
int iCount=0;		//현재 몇개의 문자를 저장했는지 세는 변수

int main(void)
{
	char *string, *new_string;	//평문, 암호문(복호문)
	char *key, *new_key;	//key 값 입력
	char abc[26], new_abc[26];	//알파벳 테이블 (기본, key값 추가된 테이블)
	int i, j, num=65,num2=65, point;
	int select;	//암호화, 복호화 모드 선택

	string=(char*)malloc(sizeof(char)*100);	//문자열 입력위한 동적 메모리 할당
	new_string=(char*)malloc(sizeof(char)*100);
	key=(char*)malloc(sizeof(char)*100);
	new_key=(char*)malloc(sizeof(char)*100);

	//기본 알파벳 테이블 채우기
	for(i=0;i<26;i++)
	{
		abc[i]=num;
		num++;
	}

	printf("******단일 치환 암호*******\n");
	printf("1. 암호화 \n");
	printf("2. 복호화 \n");
	printf(">> ");
	scanf("%d", &select);

	if(select==1)
	{
		printf("Key 입력 (영문 대문자) : ");
		scanf("%s", key);
		printf("PlainText 입력 (영문 대문자) : ");
		scanf("%s", string);
		//printf("%s \n", key);

		//Key의 중복문자 제거 (네이버에서 퍼온 코드+수정)
		for(i=0;i<26;i++)
		{
			if(key[i]>='A'&&key[i]<='Z')	//대문자
			{
				if(bString[key[i]-'A']==false)		//이전에 없던 문자면
				{
					new_key[iCount++]=key[i];	//new_key에 추가
					bString[key[i]-'A']=true;	//bString에 있는 문자라고 표시
				}
			}

			else
				continue;
		}
		new_key[iCount]='\0';	//NULL을 넣어줌으로서 문자의 끝 알림 -> 오류 방지

		//printf("%s \n", new_key);

		//Key값을 테이블에 넣기
		for(i=0;i<strlen(new_key);i++)
			new_abc[i]=new_key[i];

		num=new_key[iCount-1]+1;
		//printf("num = %c, iCount=%d \n", num,iCount);
		
		//나머지 알파벳 채우기
		for(i;i<26;i++)
		{
			point=0;	//중복 체크 용도

			//중복 체크 과정
			for(j=0;j<strlen(new_key);j++)
			{
				if(num==new_key[j])
					point++;
			}
			
			if(point>0)	//key와 중복되는 문자라면
			{
					num++;	//테이블에 넣지 않고, 다음 알파벳을 넣을 준비를 한다.
					i-=1;	//오류발생 제거 ..
			}
			else
			{
				//Z까지 테이블에 다 넣었다면
				if(num>90)
				{
					new_abc[i]=num2;	//다시 A부터 차례대로 테이블에 넣기
					num2++;
				}

				else
				{
					new_abc[i]=num;
					num++;
				}
			}
		}

		/*
		for(i=0;i<26;i++)
			printf("%c \n", new_abc[i]);
		*/

		//암호화 과정
		for(i=0;i<strlen(string);i++)
		{
			for(j=0;j<26;j++)
			{
				if(string[i]==abc[j])
					new_string[i]=new_abc[j];
			}
		}
		new_string[i]='\0';	//문자열의 끝에 NULL문자 삽입 -> 오류 제거

		//결과 출력
		printf("Result : %s \n", new_string);
	}

	else if(select==2)
	{
		printf("Key 입력 (영문 대문자) : ");
		scanf("%s", key);
		printf("CipherText 입력 (영문 대문자) : ");
		scanf("%s", string);
		//printf("%s \n", key);

		//Key의 중복문자 제거 (네이버에서 퍼온 코드+수정)
		for(i=0;i<26;i++)
		{
			if(key[i]>='A'&&key[i]<='Z')	//대문자
			{
				if(bString[key[i]-'A']==false)		//이전에 없던 문자면
				{
					new_key[iCount++]=key[i];	//new_key에 추가
					bString[key[i]-'A']=true;	//bString에 있는 문자라고 표시
				}
			}

			else
				continue;
		}
		new_key[iCount]='\0';	//NULL을 넣어줌으로서 문자의 끝 알림 -> 오류 방지

		//printf("%s \n", new_key);

		//Key값을 테이블에 넣기
		for(i=0;i<strlen(new_key);i++)
			new_abc[i]=new_key[i];

		num=new_key[iCount-1]+1;
		//printf("num = %c, iCount=%d \n", num,iCount);
		
		//나머지 알파벳 채우기
		for(i;i<26;i++)
		{
			point=0;	//중복 체크 용도

			//중복 체크 과정
			for(j=0;j<strlen(new_key);j++)
			{
				if(num==new_key[j])
					point++;
			}
			
			if(point>0)	//key와 중복되는 문자라면
			{
					num++;	//테이블에 넣지 않고, 다음 알파벳을 넣을 준비를 한다.
					i-=1;	//오류발생 제거 ..
			}
			else
			{
				//Z까지 테이블에 다 넣었다면
				if(num>90)
				{
					new_abc[i]=num2;	//다시 A부터 차례대로 테이블에 넣기
					num2++;
				}

				else
				{
					new_abc[i]=num;
					num++;
				}
			}
		}

		/*
		for(i=0;i<26;i++)
			printf("%c \n", new_abc[i]);
		*/

		//복호화 과정
		for(i=0;i<strlen(string);i++)
		{
			for(j=0;j<26;j++)
			{
				if(string[i]==new_abc[j])
					new_string[i]=abc[j];
			}
		}
		new_string[i]='\0';	//문자열의 끝에 NULL문자 삽입 -> 오류 제거

		//결과 출력
		printf("Result : %s \n", new_string);
	}

	else
		printf("Wrong number! \n");

	free(string);
	free(new_string);
	free(key);
	free(new_key);

	return 0;
}