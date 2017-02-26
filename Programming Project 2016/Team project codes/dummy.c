#include"TeamModule_J.h"

int main(void)
{
	char inFix[100];
	char *postFix=(char*)malloc(sizeof(char)*100);
	char *postFix1=(char*)malloc(sizeof(char)*100);
	char *postFix2=(char*)malloc(sizeof(char)*100);
	char *postFix3=(char*)malloc(sizeof(char)*100);
	char test;
	//Test IsNumber
	printf("#Test IsNumber()\n");
	printf("Input : 1 / result : %d\n", IsNumber('1'));
	printf("Input : 2 / result : %d\n", IsNumber('2'));
	printf("Input : 3 / result : %d\n", IsNumber('3'));
	printf("Input : 0 / result : %d\n", IsNumber('0'));
	printf("Input : . / result : %d\n", IsNumber('.'));
	printf("Input : C / result : %d\n", IsNumber('C'));
	printf("Input : + / result : %d\n", IsNumber('+'));
	printf("Input : * / result : %d\n", IsNumber('*'));
	printf("Input : - / result : %d\n", IsNumber('-'));

	printf("Enter >> ");
	scanf("%c", &test);

/*
	//Test GetNextToken
	printf("#Test GetNextToken()\n");
	printf("Input : 4*23.21-123/11 / result : %s\n", t);
*/
	/*
	//Test getPriority
	printf("#Test getPriority()\n");
	printf("Input : * / result : %d\n", GetPriority('*', 0));
	printf("Input : / / result : %d\n", GetPriority('/', 0));
	printf("Input : + / result : %d\n", GetPriority('+', 0));
	printf("Input : ( (instack=1) / result : %d\n", GetPriority('(', 1));
	printf("Input : ( (instack=0) / result : %d\n", GetPriority('(', 0));
	printf("Input : ) / result : %d\n", GetPriority(')', 0));

	printf("Enter >> ");
	scanf("%c", &test);
	*/
	//Test IsPrior
	/*
	printf("#Test IsPrior()\n");
	printf("Input : *, + / result : %d\n", IsPrior(GetPriority('*', 1), GetPriority('+', 0)));
	printf("Input : (, * / result : %d\n", IsPrior(GetPriority('(', 1), GetPriority('*', 0)));
	printf("Input : /, ( / result : %d\n", IsPrior(GetPriority('/', 1), GetPriority('(', 0)));
	printf("Input : -, / / result : %d\n", IsPrior(GetPriority('-', 1), GetPriority('/', 0)));

	printf("Enter >> ");
	scanf("%c", &test);
	*/
	//Test addZero
	printf("#Test addZero()\n");
	strcpy(inFix, "(-3)");
	addZero(inFix);
	printf("Input : (-3) / result : %s\n", inFix);
	strcpy(inFix, "0-25");
	addZero(inFix);
	printf("Input : 0-25 / result : %s\n", inFix);
	strcpy(inFix, "1-2235");
	addZero(inFix);
	printf("Input : 1-2235 / result : %s\n", inFix);
	strcpy(inFix, "(-(+3235))");
	addZero(inFix);
	printf("Input : (-(+3235)) / result : %s\n", inFix);
	strcpy(inFix, "(+23)");
	addZero(inFix);
	printf("Input : (+23) / result : %s\n", inFix);
	strcpy(inFix, "(-(-121))");
	addZero(inFix);
	printf("Input : (-(-121)) / result : %s\n", inFix);

	printf("Enter >> ");
	scanf("%c", &test);
	//Test eqErrorChk
	printf("#Test eqErrorChk()\n");
	strcpy(inFix, "-32");
	printf("Input : -32 / result : %d\n", eqErrorChk(inFix));
	strcpy(inFix, "+34");
	printf("Input : +34 / result : %d\n", eqErrorChk(inFix));
	strcpy(inFix, "(+235)");
	printf("Input : (+235) / result : %d\n", eqErrorChk(inFix));
	strcpy(inFix, "(-211)");
	printf("Input : (-211) / result : %d\n", eqErrorChk(inFix));
	strcpy(inFix, "42-1");
	printf("Input : 42-1 / result : %d\n", eqErrorChk(inFix));
	strcpy(inFix, "41+(+13+1)");
	printf("Input : 41+(+13+1) / result : %d\n", eqErrorChk(inFix));
	strcpy(inFix, "3*(*25+4)");
	printf("Input : 3*(*25+4) / result : %d\n", eqErrorChk(inFix));

	printf("Enter >> ");
	scanf("%c", &test);
	//Test GetPostfix
	printf("#Test GetPostfix()\n");
	strcpy(inFix, "(-21)+((-3)+252)");
	addZero(inFix);
	GetPostfix(inFix, postFix);
	printf("Input : (-21)+((-3)+252) / result : %s\n", postFix);
	strcpy(inFix, "345*21/120");
	addZero(inFix);
	GetPostfix(inFix, postFix1);
	printf("Input : 345*21/120 / result : %s\n", postFix1);
	strcpy(inFix, "3.14*(11-2)/2");
	addZero(inFix);
	GetPostfix(inFix, postFix2);
	printf("Input : 3.14*(11-2)/2 / result : %s\n", postFix2);
	strcpy(inFix, "(6*(7+2)-1*4)/3.1");
	addZero(inFix);
	GetPostfix(inFix, postFix3);
	printf("Input : (6*(7+2)-1*4)/3.1 / result : %s\n", postFix3);
	free(postFix);
	postFix=(char*)malloc(sizeof(char)*100);

	printf("Enter >> ");
	scanf("%c", &test);
	//Test Caculate
	printf("#Test Caculate()\n");
	strcpy(postFix,"0 0 30 - - 20 /");
	printf("Input : %s / result : %.8lf\n", postFix, Calculate(postFix));
	free(postFix);
	postFix=(char*)malloc(sizeof(char)*100);
	strcpy(postFix, "1 0 2 - 2 * -");
	printf("Input : %s / result : %.8lf\n", postFix, Calculate(postFix));
	free(postFix);
	postFix=(char*)malloc(sizeof(char)*100);
	strcpy(postFix, "234 0 251 - 242 * - 12.0 +");
	printf("Input : %s / result : %.8lf\n", postFix, Calculate(postFix));
	free(postFix);
	postFix=(char*)malloc(sizeof(char)*100);
	strcpy(postFix,"3 1234 * 2 /");
	printf("Input : %s / result : %.8lf\n", postFix, Calculate(postFix));
	free(postFix);
	postFix=(char*)malloc(sizeof(char)*100);
	strcpy(postFix, "14 43.15 * 0 /");
	printf("Input : %s / result : %.8lf\n", postFix, Calculate(postFix));

	return 0;
}
