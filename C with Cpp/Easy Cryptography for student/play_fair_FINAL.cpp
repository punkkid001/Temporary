#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ߺ� ���� üũ�� ���� 'bool'�� ������� ��¿ �� ���� '*.cpp'�� �ڵ��ϰ� ��

bool bString[26]={0,};	//���ĺ��� �־����� üũ
int iCount=0;		//���� ��� ���ڸ� �����ߴ��� ���� ����

int A_code_i;
int A_code_j;
int B_code_i;
int B_code_j;

//��, ���� ������ �ٸ��� Ȯ���ϱ� ���� �˻��ϴ� �Լ�
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
	printf("******���� ��ȣ****** \n");
	printf("1. ��ȣȭ \n");
	printf("2. ��ȣȭ \n");
	printf(">> ");
	scanf("%d", &select);


	//��ȣȭ ����
	if(select==1)
	{
		PlainText=(char*)malloc(100*sizeof(char));
		key=(char*)malloc(100*sizeof(char));
		new_key=(char*)malloc(100*sizeof(char));

		printf("�� �Է� (�빮��) : ");
		scanf("%s", PlainText);
		printf("///Key�� ���� �⺻ ���̺� �̿�� '.'�Է�///\n");
		printf("Key �� �Է� (�빮��) : ");
		scanf("%s", key);

		//printf("%s \n", key);

		//Key�� �ߺ����� ���� (���̹����� �ۿ� �ڵ�+����)
		for(i=0;i<26;i++)
		{
			if(key[i]>='A'&&key[i]<='Z')	//�빮��
			{
				if(bString[key[i]-'A']==false)		//������ ���� ���ڸ�
				{
					new_key[iCount++]=key[i];	//new_key�� �߰�
					bString[key[i]-'A']=true;	//bString�� �ִ� ���ڶ�� ǥ��
				}
			}

			else
				continue;
		}

		new_key[iCount]='\0';	//NULL�� �־������μ� ������ �� �˸� -> ���� ����

		//���� ���̰� Ȧ����� ¦�� �����ֱ� ���� ���� 'X'�߰�
		length=strlen(PlainText);
		if((length%2)!=0)
		{
			PlainText[length]='X';
			PlainText[length+1]='\0';
		}

		//J->I�� ��ȯ
		for(i=0;i<strlen(new_key);i++)
			if(new_key[i]=='J')
				new_key[i]='I';
		
		//printf("%s \n", PlainText);

		length=strlen(PlainText);

		//���̺� Ű ���� ä��� ����
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

		//������ ���ĺ� ä���
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

		//��ȣȭ ��ŸƮ~~~~~
		for(i=0;i<strlen(PlainText);i+=2)
		{
			code_setting(PlainText[i], PlainText[i+1], table);


			/*
			printf("a code i / j ; %d / %d \n", A_code_i, A_code_j);
			printf("b code i / j ; %d / %d \n", B_code_i, B_code_j);
			*/

			//�ٸ� ��� �ٸ� ���� �����ϴ� ���
			if((A_code_i!=B_code_i)&&(A_code_j!=B_code_j))
			{
				 CipherText[i]=table[B_code_i][A_code_j];
				 CipherText[i+1]=table[A_code_i][B_code_j];
			}

			//���� ���� �����ϴ� ���
			else if((A_code_i!=B_code_i)&&(A_code_j==B_code_j))
			{
				if((A_code_i==4)&&(B_code_i==4))//�����ڵ�
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

			//���� �࿡ ��ġ�ϴ� ���
			else if((A_code_i==B_code_i)&&(A_code_j!=B_code_j))
			{
				if((A_code_j==4)&&(B_code_j==4))//�����ڵ�
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

			//�� ���ڰ� ���� ���
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

	//��ȣȭ ����
	else
	{
		CipherText=(char*)malloc(100*sizeof(char));
		key=(char*)malloc(100*sizeof(char));
		new_key=(char*)malloc(100*sizeof(char));

		printf("��ȣ�� �Է� (�빮��) : ");
		scanf("%s", CipherText);
		printf("///Key�� ���� �⺻ ���̺� �̿�� '.'�Է�///\n");
		printf("Key �� �Է� (�빮��) : ");
		scanf("%s", key);

		//printf("%s \n", key);

		//Key�� �ߺ����� ���� (���̹����� �ۿ� �ڵ�+����)
		for(i=0;i<26;i++)
		{
			if(key[i]>='A'&&key[i]<='Z')	//�빮��
			{
				if(bString[key[i]-'A']==false)		//������ ���� ���ڸ�
				{
					new_key[iCount++]=key[i];	//new_key�� �߰�
					bString[key[i]-'A']=true;	//bString�� �ִ� ���ڶ�� ǥ��
				}
			}

			else
				continue;
		}

		new_key[iCount]='\0';	//NULL�� �־������μ� ������ �� �˸� -> ���� ����

		/* ��ȣȭ ������ �ش� �� ��.
		//���� ���̰� Ȧ����� ¦�� �����ֱ� ���� ���� 'X'�߰�
		length=strlen(PlainText);
		if((length%2)!=0)
		{
			PlainText[length]='X';
			PlainText[length+1]='\0';
		}
		*/

		//J->I�� ��ȯ
		for(i=0;i<strlen(new_key);i++)
			if(new_key[i]=='J')
				new_key[i]='I';
		
		//printf("%s \n", PlainText);

		length=strlen(CipherText);

		//���̺� Ű ���� ä��� ����
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

		//������ ���ĺ� ä���
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

		//��ȣȭ ��ŸƮ~~~~~
		for(i=0;i<strlen(CipherText);i+=2)
		{
			code_setting(CipherText[i], CipherText[i+1], table);


			/*
			printf("a code i / j ; %d / %d \n", A_code_i, A_code_j);
			printf("b code i / j ; %d / %d \n", B_code_i, B_code_j);
			*/

			//�ٸ� ��� �ٸ� ���� �����ϴ� ��� - ��ȣȭ �� �״�� �ᵵ ��..
			if((A_code_i!=B_code_i)&&(A_code_j!=B_code_j))
			{
				 PlainText[i]=table[B_code_i][A_code_j];
				 PlainText[i+1]=table[A_code_i][B_code_j];
			}

			//���� ���� �����ϴ� ���
			else if((A_code_i!=B_code_i)&&(A_code_j==B_code_j))
			{
				if((A_code_i==4)&&(B_code_i==4))//�����ڵ�
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

			//���� �࿡ ��ġ�ϴ� ���
			else if((A_code_i==B_code_i)&&(A_code_j!=B_code_j))
			{
				if((A_code_j==4)&&(B_code_j==4))//�����ڵ�
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

			//�� ���ڰ� ���� ���
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