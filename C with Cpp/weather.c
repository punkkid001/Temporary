#include<stdio.h>
int main(void)
{
  int num;

  printf("input number : ");
  scanf("%d", &num);

  switch (num/3%4)
  {
    //12, 1, 2 -> winter
    case 0:
        printf("winter \n");
        break;
    //3, 4, 5 -> spring
    case 1:
        printf("spring \n");
        break;
    //6, 7, 8 -> summer
    case 2:
        printf("summer \n");
        break;
    //9, 10, 11 -> fall
    case 3:
        printf("fall \n");
        break;
   }

   return 0;
}
