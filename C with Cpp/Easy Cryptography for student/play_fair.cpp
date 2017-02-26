#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//중복 문자 체크를 위한 'bool'의 사용으로 어쩔 수 없이 '*.cpp'로 코딩하게 됨

bool bString[26]={0,};	//알파벳이 있었는지 체크
int iCount=0;		//현재 몇개의 문자를 저장했는지 세는 변수

int main(void)
{
	char table[5][5];

	char *PlainText;
	char *CipherText;
	char *key, *new_key;

	int abc=65;

	int select;
	int length;
	int i, j, k;
	int abc_check=0;
	int check_code=0;
	int move_code=2;

	printf("# I=J version # \n");
	printf("******쌍자 암호****** \n");
	printf("1. 암호화 \n");
	printf("2. 복호화 \n");
	printf(">> ");
	scanf("%d", &select);


	//암호화 선택
	if(select==1)
	{
		PlainText=(char*)malloc(100*sizeof(char));
		key=(char*)malloc(100*sizeof(char));
		new_key=(char*)malloc(100*sizeof(char));

		printf("평문 입력 (대문자) : ");
		scanf("%s", PlainText);
		printf("Key 값 입력 (대문자) : ");
		scanf("%s", key);

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

		//평문의 길이가 홀수라면 짝을 맞춰주기 위해 문자 'X'추가
		length=strlen(PlainText);
		if((length%2)!=0)
		{
			PlainText[length]='X';
			PlainText[length+1]='\0';
		}

		//J->I로 변환
		for(i=0;i<strlen(new_key);i++)
			if(new_key[i]=='J')
				new_key[i]='I';
		
		//printf("%s \n", PlainText);

		length=strlen(PlainText);

		//테이블에 키 값을 채우는 과정
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(new_key[check_code]!='\0')
				{
					table[i][j]=new_key[check_code];
					check_code++;
				}
				else
				{
					table[i][j]='?';
				}
			}
		}

		length=strlen(new_key);

		//나머지 알파벳 채우기
		for(i=check_code/5;i<5;i++)
		{
			if(move_code==2)
			{
				move_code--;
				for(j=(check_code%5);j<5;j++)
				{
					for(k=0;k<length;k++)
					{
						if(new_key[k]==(char)abc)
							abc++;
					}
					
					if(abc==74)
						abc++;

					table[i][j]=abc;
					abc++;
				}
			}

			else
			{
				for(j=0;j<5;j++)
				{
					//move_code=0;
					for(k=0;k<length;k++)
					{
						if(new_key[k]==(char)abc)
							abc++;
					}
					if(abc==74)
						abc++;

					table[i][j]=abc;
					abc++;
				}
			}
		}

		/*
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				printf("%c ", table[i][j]);
			printf("\n");
		}
		*/

		//암호화 스타트~~~~~

	}

	//복호화 선택
	else
	{
		printf("암호문 입력 (대문자) : ");
	}

	free(PlainText);
	free(key);
	return 0;
}