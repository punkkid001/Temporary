#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//중복 문자 체크를 위한 'bool'의 사용으로 어쩔 수 없이 '*.cpp'로 코딩하게 됨

bool bString[26]={0,};	//알파벳이 있었는지 체크
int iCount=0;		//현재 몇개의 문자를 저장했는지 세는 변수

int A_code_i;
int A_code_j;
int B_code_i;
int B_code_j;

//행, 열이 같은지 다른지 확인하기 위해 검사하는 함수
void code_setting(char string_A, char string_B,char table[5][5])
{
	int i, j;

	/*
	printf("string a : %c \n", string_A);
	printf("string b : %c \n", string_B);
	*/

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(string_A==table[i][j])
			{
				//printf("table %d %d : %c \n", i, j, table[i][j]);
				A_code_i=i;
				A_code_j=j;
			}
			if(string_B==table[i][j])
			{
				//printf("table %d %d : %c \n", i, j, table[i][j]);
				B_code_i=i;
				B_code_j=j;
			}
		}
	}
}


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
		printf("///Key값 없이 기본 테이블 이용시 '.'입력///\n");
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

		printf("\n");
		printf("*****Table*****\n");

		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				printf("%c ", table[i][j]);
			printf("\n");
		}
		printf("\n");

		CipherText=(char*)malloc(100*sizeof(char));

		//암호화 스타트~~~~~
		for(i=0;i<strlen(PlainText);i+=2)
		{
			code_setting(PlainText[i], PlainText[i+1], table);


			/*
			printf("a code i / j ; %d / %d \n", A_code_i, A_code_j);
			printf("b code i / j ; %d / %d \n", B_code_i, B_code_j);
			*/

			//다른 행과 다른 열에 존재하는 경우
			if((A_code_i!=B_code_i)&&(A_code_j!=B_code_j))
			{
				 CipherText[i]=table[B_code_i][A_code_j];
				 CipherText[i+1]=table[A_code_i][B_code_j];
			}

			//같은 열에 존재하는 경우
			else if((A_code_i!=B_code_i)&&(A_code_j==B_code_j))
			{
				if((A_code_i==4)&&(B_code_i==4))//보류코드
				{
					CipherText[i]=table[0][A_code_j];
					CipherText[i+1]=table[0][B_code_j];
				}
				else if(A_code_i==4)
				{
					CipherText[i]=table[0][A_code_j];
					CipherText[i+1]=table[B_code_i+1][B_code_j];
				}
				else if(B_code_i==4)
				{
					CipherText[i]=table[A_code_i+1][A_code_j];
					CipherText[i+1]=table[0][B_code_j];
				}
				else
				{
					CipherText[i]=table[A_code_i+1][A_code_j];
					CipherText[i+1]=table[B_code_i+1][B_code_j];
				}
			}

			//같은 행에 위치하는 경우
			else if((A_code_i==B_code_i)&&(A_code_j!=B_code_j))
			{
				if((A_code_j==4)&&(B_code_j==4))//보류코드
				{
					CipherText[i]=table[A_code_i][0];
					CipherText[i+1]=table[B_code_i][0];
				}
				else if(A_code_j==4)
				{
					CipherText[i]=table[A_code_i][0];
					CipherText[i+1]=table[B_code_i][B_code_j+1];
				}
				else if(B_code_j==4)
				{
					CipherText[i]=table[A_code_i][A_code_j+1];
					CipherText[i+1]=table[B_code_i][0];
				}
				else
				{
					CipherText[i]=table[A_code_i][A_code_j+1];
					CipherText[i+1]=table[B_code_i][B_code_j+1];
				}
			}

			//두 문자가 같은 경우
			else
			{
				if(A_code_i==4)
				{
					CipherText[i]=table[0][A_code_j+1];
					CipherText[i+1]=table[0][B_code_j+1];
				}
				else
				{
					CipherText[i]=table[A_code_i][A_code_j+1];
					CipherText[i+1]=table[B_code_i][B_code_j+1];
				}
			}
		}
		CipherText[i]='\0';

		//result
		printf("Result : %s \n", CipherText);
	}

	//복호화 선택
	else
	{
		CipherText=(char*)malloc(100*sizeof(char));
		key=(char*)malloc(100*sizeof(char));
		new_key=(char*)malloc(100*sizeof(char));

		printf("암호문 입력 (대문자) : ");
		scanf("%s", CipherText);
		printf("///Key값 없이 기본 테이블 이용시 '.'입력///\n");
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

		/* 복호화 과정에 해당 안 됨.
		//평문의 길이가 홀수라면 짝을 맞춰주기 위해 문자 'X'추가
		length=strlen(PlainText);
		if((length%2)!=0)
		{
			PlainText[length]='X';
			PlainText[length+1]='\0';
		}
		*/

		//J->I로 변환
		for(i=0;i<strlen(new_key);i++)
			if(new_key[i]=='J')
				new_key[i]='I';
		
		//printf("%s \n", PlainText);

		length=strlen(CipherText);

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

		printf("\n");
		printf("*****Table*****\n");

		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				printf("%c ", table[i][j]);
			printf("\n");
		}
		printf("\n");

		PlainText=(char*)malloc(100*sizeof(char));

		//복호화 스타트~~~~~
		for(i=0;i<strlen(CipherText);i+=2)
		{
			code_setting(CipherText[i], CipherText[i+1], table);


			/*
			printf("a code i / j ; %d / %d \n", A_code_i, A_code_j);
			printf("b code i / j ; %d / %d \n", B_code_i, B_code_j);
			*/

			//다른 행과 다른 열에 존재하는 경우 - 암호화 것 그대로 써도 됨..
			if((A_code_i!=B_code_i)&&(A_code_j!=B_code_j))
			{
				 PlainText[i]=table[B_code_i][A_code_j];
				 PlainText[i+1]=table[A_code_i][B_code_j];
			}

			//같은 열에 존재하는 경우
			else if((A_code_i!=B_code_i)&&(A_code_j==B_code_j))
			{
				if((A_code_i==4)&&(B_code_i==4))//보류코드
				{
					PlainText[i]=table[0][A_code_j];
					PlainText[i+1]=table[0][B_code_j];
				}
				else if(A_code_i==0)
				{
					PlainText[i]=table[4][A_code_j];
					PlainText[i+1]=table[B_code_i-1][B_code_j];
				}
				else if(B_code_i==0)
				{
					PlainText[i]=table[A_code_i-1][A_code_j];
					PlainText[i+1]=table[4][B_code_j];
				}
				else
				{
					PlainText[i]=table[A_code_i-1][A_code_j];
					PlainText[i+1]=table[B_code_i-1][B_code_j];
				}
			}

			//같은 행에 위치하는 경우
			else if((A_code_i==B_code_i)&&(A_code_j!=B_code_j))
			{
				if((A_code_j==4)&&(B_code_j==4))//보류코드
				{
					CipherText[i]=table[A_code_i][0];
					CipherText[i+1]=table[B_code_i][0];
				}
				else if(A_code_j==0)
				{
					PlainText[i]=table[A_code_i][4];
					PlainText[i+1]=table[B_code_i][B_code_j-1];
				}
				else if(B_code_j==0)
				{
					PlainText[i]=table[A_code_i][A_code_j-1];
					PlainText[i+1]=table[B_code_i][4];
				}
				else
				{
					PlainText[i]=table[A_code_i][A_code_j-1];
					PlainText[i+1]=table[B_code_i][B_code_j-1];
				}
			}

			//두 문자가 같은 경우
			else
			{
				if(A_code_i==0)
				{
					CipherText[i]=table[4][A_code_j-1];
					CipherText[i+1]=table[4][B_code_j-1];
				}
				else
				{
					PlainText[i]=table[A_code_i][A_code_j-1];
					PlainText[i+1]=table[B_code_i][B_code_j-1];
				}
			}
		}
		PlainText[i]='\0';

		//result
		printf("Result : %s \n", PlainText);
	}

	free(PlainText);
	free(CipherText);
	free(key);
	return 0;
}