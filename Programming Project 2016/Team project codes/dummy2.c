#include"TeamModule_J.h"

int main(void)
{
	char *exp=(char*)malloc(sizeof(char)*100);
	printf("Input exp : ");
	scanf("%s", exp);
	printf("result : %.8lf \n", ConstCalculation(exp));
	free(exp);

	return 0;
}
