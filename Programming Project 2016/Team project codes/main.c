//#include "calculate.h"
#include"TeamModule_J.h"
//#include"another.h"

int main(void)
{
  char *str=(char*)malloc(sizeof(char)*100);
  //memset(str, 0, sizeof(str)*100);
  printf("Input : ");
  scanf("%s", str);
  printf("result : %.8lf \n", ConstCalculation(str));

  return 0;
}
