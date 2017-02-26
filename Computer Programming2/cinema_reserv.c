#include<stdio.h>
#define size 10

int main(void)
{
	int ans1=0;
	int p1,p2,i;
	char ans4;
	int seat[size]={0};

	while(1)
	{
		printf("1. 예약\n2. 취소\n3. 종료\n");
		printf(">> ");
		scanf("%d", &ans1);

		if(ans1==1)
		{
			fflush(stdin);
			printf("두 분이서 예약 하시겠습니까? (Y/N) ");
			scanf("%c", &ans4);

			if(ans4=='Y')
			{
				printf("---------------------\n");
				printf("1 2 3 4 5 6 7 8 9 10\n");
				printf("---------------------\n");
				
				for(i=0;i<size;i++)
					printf("%d ", seat[i]);
				printf("\n");
				printf("어떤 좌석을 예약 하시겠습니까? (두 개의 좌석 번호 입력) ");
				scanf("%d %d", &p1, &p2);

				if(seat[p1-1]==0 && seat[p2-1]==0)
				{
					seat[p1-1]=1;
					seat[p2-1]=1;
					printf("예약이 완료되었습니다. \n");
				}

				else if(p1<1 || p1>10 || p2<1 || p2>10)
				{
					if(p1<1 || p1>10)
						printf("%d 좌석은 존재하는 자리가 아닙니다. \n", p1);
					else if(p2<1 || p2>10)
						printf("%d 좌석은 존재하는 자리가 아닙니다. \n", p2);
				}
				else
				{
					if(seat[p1-1]!=0)
						printf("%d 좌석은 이미 예약된 자리입니다. \n", p1);
					if(seat[p2-1]!=0)
						printf("%d 좌석은 이미 예약된 자리입니다. \n", p2);
				}
			}

			else
			{
				printf("---------------------\n");
				printf("1 2 3 4 5 6 7 8 9 10\n");
				printf("---------------------\n");
				
				for(i=0;i<size;i++)
					printf("%d ", seat[i]);
				printf("\n");
				printf("어떤 좌석을 예약 하시겠습니까? ");
				scanf("%d", &p1);

				if(seat[p1-1]==0)
				{
					seat[p1-1]=1;
					printf("예약이 완료되었습니다. \n");
				}
				else if(p1<1 || p1>10)
					printf("%d 좌석은 존재하는 자리가 아닙니다. \n", p1);
				else
					printf("%d 좌석은 이미 예약된 자리입니다. \n", p1);
			}
		}

		else if(ans1==2)
		{
			printf("---------------------\n");
			printf("1 2 3 4 5 6 7 8 9 10\n");
			printf("---------------------\n");
				
			for(i=0;i<size;i++)
				printf("%d ", seat[i]);
			printf("\n");
			printf("어떤 좌석을 취소하시겠습니까? ");
			scanf("%d", &p1);

			if(seat[p1-1]==1)
			{
				seat[p1-1]=0;
				printf("취소가 완료되었습니다. \n");
			}

			else if(p1<1 || p1>10)
				printf("%d 좌석은 존재하는 자리가 아닙니다. \n", p1);

			else
				printf("%d 좌석은 예약된 자리가 아닙니다. \n", p1);
		}

		else
		{
			printf("프로그램 종료 .. \n");
			break;
		}

		
		printf("---------------------\n");
		printf("1 2 3 4 5 6 7 8 9 10\n");
		printf("---------------------\n");
				
		for(i=0;i<size;i++)
			printf("%d ", seat[i]);
		printf("\n");
	}

	return 0;
}
