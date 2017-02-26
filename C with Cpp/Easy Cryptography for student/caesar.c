#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char abc[26], new_abc[26];	//���ĺ� a~z���� �����ϱ� ���� �迭 (�⺻, ��ȣȭ&��ȣȭ ����)
	char *string;	//��
	char *new_string;	//��ȣ��or��ȣȭ �� ����
	int i, j, num=65,num2=65;	//num, num2 -> �⺻ ���ĺ� ����, shift�� ���ĺ� ���忡 ���
	int select, key;	//select�� ��ȣȭ/��ȣȭ ��� ���ÿ� ���, key�� ��ȣȭ/��ȣȭ�� ���Ǵ� Ű ��, 

	string=(char*)malloc(sizeof(char)*100);		//���ڿ� ���� �Է¹ޱ� ���� ���� �޸� �Ҵ�
	new_string=(char*)malloc(sizeof(char)*100);

	//ASCII���� A�� 65.. -> abc[0]~abc[25] => A~Z
	for(i=0;i<26;i++)
	{
		abc[i]=num;
		num++;
	}

	/*
	for(i=0;i<26;i++)
		printf("%c \n", abc[i]);
	*/

	printf("*********���� ��ȣ**********\n");
	printf("1. ��ȣȭ \n");
	printf("2. ��ȣȭ \n");
	printf(">> ");
	scanf("%d", &select);

	if(select==1)
	{
		printf("Key �� �Է� (���� ����) : ");
		scanf("%d", &key);
		printf("PlainText �Է� (���� - �빮��) : ");
		scanf("%s", string);

		//printf("%s \n", string);

		key%=26;	//key�� ����
		num=65;

		//SHIFT�� ���̺� �����
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
		
		//��ȣȭ
		for(i=0;i<strlen(string);i++)
		{
			for(j=0;j<26;j++)
			{
				if(string[i]==abc[j])
					new_string[i]=new_abc[j];
			}
		}
		new_string[strlen(string)]='\0';	//Null ���� �־������μ� ERROR�ذ� (���ڿ��� ���� ǥ������..)

		printf("Encryption result : %s \n", new_string);	//��ȣȭ ��� ���
	}
	else if(select==2)
	{
		printf("Key �� �Է� (���� ����) : ");
		scanf("%d", &key);
		printf("CipherText �Է� (���� - �빮��) : ");
		scanf("%s", string);

		key%=26;	//key�� ����
		num=65;

		//SHIFT�� ���̺� �����
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
		
		//��ȣȭ
		for(i=0;i<strlen(string);i++)
		{
			for(j=0;j<26;j++)
			{
				if(string[i]==new_abc[j])
					new_string[i]=abc[j];
			}
		}
		new_string[strlen(string)]='\0';	//Null ���� �־������μ� ERROR�ذ� (���ڿ��� ���� ǥ������..)

		printf("Decryption result : %s \n", new_string);	//��ȣȭ ��� ���
	}

	else
		printf("Wrong number! \n");

	free(string);
	free(new_string);

	return 0;
}