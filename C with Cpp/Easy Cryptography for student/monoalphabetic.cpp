#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ߺ� ���� üũ�� ���� 'bool'�� ������� ��¿ �� ���� '*.cpp'�� �ڵ��ϰ� ��

bool bString[26]={0,};	//���ĺ��� �־����� üũ
int iCount=0;		//���� ��� ���ڸ� �����ߴ��� ���� ����

int main(void)
{
	char *string, *new_string;	//��, ��ȣ��(��ȣ��)
	char *key, *new_key;	//key �� �Է�
	char abc[26], new_abc[26];	//���ĺ� ���̺� (�⺻, key�� �߰��� ���̺�)
	int i, j, num=65,num2=65, point;
	int select;	//��ȣȭ, ��ȣȭ ��� ����

	string=(char*)malloc(sizeof(char)*100);	//���ڿ� �Է����� ���� �޸� �Ҵ�
	new_string=(char*)malloc(sizeof(char)*100);
	key=(char*)malloc(sizeof(char)*100);
	new_key=(char*)malloc(sizeof(char)*100);

	//�⺻ ���ĺ� ���̺� ä���
	for(i=0;i<26;i++)
	{
		abc[i]=num;
		num++;
	}

	printf("******���� ġȯ ��ȣ*******\n");
	printf("1. ��ȣȭ \n");
	printf("2. ��ȣȭ \n");
	printf(">> ");
	scanf("%d", &select);

	if(select==1)
	{
		printf("Key �Է� (���� �빮��) : ");
		scanf("%s", key);
		printf("PlainText �Է� (���� �빮��) : ");
		scanf("%s", string);
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

		//printf("%s \n", new_key);

		//Key���� ���̺� �ֱ�
		for(i=0;i<strlen(new_key);i++)
			new_abc[i]=new_key[i];

		num=new_key[iCount-1]+1;
		//printf("num = %c, iCount=%d \n", num,iCount);
		
		//������ ���ĺ� ä���
		for(i;i<26;i++)
		{
			point=0;	//�ߺ� üũ �뵵

			//�ߺ� üũ ����
			for(j=0;j<strlen(new_key);j++)
			{
				if(num==new_key[j])
					point++;
			}
			
			if(point>0)	//key�� �ߺ��Ǵ� ���ڶ��
			{
					num++;	//���̺� ���� �ʰ�, ���� ���ĺ��� ���� �غ� �Ѵ�.
					i-=1;	//�����߻� ���� ..
			}
			else
			{
				//Z���� ���̺� �� �־��ٸ�
				if(num>90)
				{
					new_abc[i]=num2;	//�ٽ� A���� ���ʴ�� ���̺� �ֱ�
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

		//��ȣȭ ����
		for(i=0;i<strlen(string);i++)
		{
			for(j=0;j<26;j++)
			{
				if(string[i]==abc[j])
					new_string[i]=new_abc[j];
			}
		}
		new_string[i]='\0';	//���ڿ��� ���� NULL���� ���� -> ���� ����

		//��� ���
		printf("Result : %s \n", new_string);
	}

	else if(select==2)
	{
		printf("Key �Է� (���� �빮��) : ");
		scanf("%s", key);
		printf("CipherText �Է� (���� �빮��) : ");
		scanf("%s", string);
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

		//printf("%s \n", new_key);

		//Key���� ���̺� �ֱ�
		for(i=0;i<strlen(new_key);i++)
			new_abc[i]=new_key[i];

		num=new_key[iCount-1]+1;
		//printf("num = %c, iCount=%d \n", num,iCount);
		
		//������ ���ĺ� ä���
		for(i;i<26;i++)
		{
			point=0;	//�ߺ� üũ �뵵

			//�ߺ� üũ ����
			for(j=0;j<strlen(new_key);j++)
			{
				if(num==new_key[j])
					point++;
			}
			
			if(point>0)	//key�� �ߺ��Ǵ� ���ڶ��
			{
					num++;	//���̺� ���� �ʰ�, ���� ���ĺ��� ���� �غ� �Ѵ�.
					i-=1;	//�����߻� ���� ..
			}
			else
			{
				//Z���� ���̺� �� �־��ٸ�
				if(num>90)
				{
					new_abc[i]=num2;	//�ٽ� A���� ���ʴ�� ���̺� �ֱ�
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

		//��ȣȭ ����
		for(i=0;i<strlen(string);i++)
		{
			for(j=0;j<26;j++)
			{
				if(string[i]==new_abc[j])
					new_string[i]=abc[j];
			}
		}
		new_string[i]='\0';	//���ڿ��� ���� NULL���� ���� -> ���� ����

		//��� ���
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