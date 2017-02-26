#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ߺ� ���� üũ�� ���� 'bool'�� ������� ��¿ �� ���� '*.cpp'�� �ڵ��ϰ� ��

bool bString[26]={0,};	//���ĺ��� �־����� üũ
int iCount=0;		//���� ��� ���ڸ� �����ߴ��� ���� ����

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

		/*
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				printf("%c ", table[i][j]);
			printf("\n");
		}
		*/

		//��ȣȭ ��ŸƮ~~~~~

	}

	//��ȣȭ ����
	else
	{
		printf("��ȣ�� �Է� (�빮��) : ");
	}

	free(PlainText);
	free(key);
	return 0;
}