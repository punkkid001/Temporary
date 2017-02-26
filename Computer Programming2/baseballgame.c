/*
숫자 야구게임
1. 게임 시작
 1) 
 (0~9 ->7 2 1 / 스트, 볼)

 count <=10까지만!
 맞춘경우 카운트 출력

2. 종료

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int answer1, answer2, answer3;
int strike, ball;
int su=0;
int count;


void setting_numbers();
void baseball_game();
void answer_check();
void print_result();

int main(void)
{
	int input;

	printf("*****야구 게임*****\n");
	do
	{
		input=0;

		printf("1. 게임 시작\n");
		printf("2. 게임 종료\n");
		printf(">> ");
		scanf("%d", &input);

		if(input==1)
		{
			setting_numbers();
			while(count<10)
			{
				count++;
				baseball_game();
				if(strike==3)
				{
					printf("%d회 만에 답을 맞추셨습니다. \n", count);
					su=1;
					break;
				}
			}

			if(su==0)
			{
				printf("10번의 횟수를 초과하여 답을 맞추는데에 실패하였습니다! \n");
			}

			printf("다시 하시겠습니까 ? \n");
			
		}
		else
		{
			printf("게임 종료 ..\n");
			break;
		}
	}while(1);

	return 0;
}

void setting_numbers()
{
	srand((unsigned)time(NULL));
	answer1=rand()%10;
	answer2=rand()%10;
	answer3=rand()%10;
	count=0;
}

void baseball_game()
{
	int num1, num2, num3;

	printf("답 : %d %d %d \n", answer1, answer2, answer3);
	printf("시도 횟수 : %d \n", count);

	printf("숫자 입력 : ");
	scanf("%d %d %d", &num1, &num2, &num3);

	answer_check(num1, num2, num3);
	print_result();
}

void answer_check(int num1, int num2 ,int num3)
{
	strike=0;
	ball=0;

	if(answer1==answer2||answer1==answer3||answer2==answer3)
	{
		if(num1==answer1)
		strike++;
	else if(num1==answer2||num1==answer3)
			ball++;

	if(num2==answer2)
		strike++;
	else if(num2==answer1||num2==answer3)
			ball++;
	
	if(num3==answer3)
		strike++;
	else if(num3==answer1||num3==answer2)
			ball++;

	
	}
	else
	{
		if(num1==answer1)
		strike++;
	else if(num1==answer2||num1==answer3)
		if(num2!=num1&&num3!=num1)
			ball++;

	if(num2==answer2)
		strike++;
	else if(num2==answer1||num2==answer3)
		if(num1!=num2&&num3!=num2)
			ball++;
	
	if(num3==answer3)
		strike++;
	else if(num3==answer1||num3==answer2)
		if(num1!=num3&&num2!=num3)
			ball++;
		
	}
	
}

void print_result()
{
	printf("%d strike / %d ball \n", strike, ball);
}
