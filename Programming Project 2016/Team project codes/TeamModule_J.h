#include "LinkedListStack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum
{
    LEFT_PAR  = '(', RIGHT_PAR = ')',
    PLUS     = '+', MINUS    = '-',
    MULTIPLY = '*', DIVIDE   = '/',
    SPACE    = ' ', OPERAND
} SYMBOL;

double ConstCalculation(char* exp);
int	IsNumber(char word);
unsigned int GetNextToken(char *exp, char *token, int *type);
int	IsPrior(char operInStack, char operInToken);
void GetPostfix(char* inFix, char* postFix);
double Calculate(char* postFix);

int eqErrorChk(char *inFix);
void addZero(char *inFix);

int IsNumber(char word)
{
    if(word=='0'||word=='1'||word=='2'||word=='3'||word=='4'||word=='5'||word=='6'||word=='7'||word=='8'||word=='9'||word=='.')
    	return 1;
  	else
    	return 0;
}

unsigned int GetNextToken(char *exp, char *token, int *type)
{
    unsigned int i = 0;

    for(i=0;0!=exp[i];i++)
    {
        token[i]=exp[i];

        if(IsNumber(exp[i])==1)
        {
            *type = OPERAND;
            if (IsNumber(exp[i+1])!=1)
                break;
        }
        else
        {
            *type = exp[i];
            break;
        }
    }

    token[++i] = '\0';
    return i;
}

int GetPriority(char oper, int InStack)
{
	if(oper=='(')
	{
		if(InStack==1)
    		return 3;
    	else
    		return 0;
  	}

  	else if(oper=='*'||oper=='/')
    	return 1;
  	else if(oper=='+'||oper=='-')
    	return 2;
	else
    	return -1;
}

int IsPrior(char operInStack, char operInToken)
{
    if(GetPriority(operInStack, 1)>GetPriority(operInToken, 0))
        return 1;
    else
        return 0;
}

void GetPostfix(char* inFix, char* postFix)
{
    LinkedListStack* stack;

    char token[32];	//a~z(=26)+ (+, -, *, /, ), ( )(=6) = 32
    int  type = -1;
    unsigned int position = 0;
    unsigned int len = strlen(inFix);

    LLS_CreateStack(&stack);

    while(position<len)
    {
        position+=GetNextToken(&inFix[position], token, &type );

        if(type==OPERAND)
        {
            strcat(postFix, token );
            strcat(postFix, " " );
        }

        else if(type==')')
        {
            while(!LLS_IsEmpty(stack))
            {
                Node* popData = LLS_Pop(stack);

                if(popData->Data[0]=='(')
                {
                    LLS_DestroyNode(popData);
                    break;
                }
                else
                {
                    strcat(postFix, popData->Data);
                    strcat(postFix, " ");
                    LLS_DestroyNode(popData);
                }
            }
        }
        else
        {   //stack not empty and top>data -> all pop.. after push
            while(!LLS_IsEmpty(stack)&&!IsPrior(LLS_Top(stack)->Data[0], token[0]))
            {
                Node* popData = LLS_Pop(stack);

                if(popData->Data[0]!='(')
                {
                    strcat(postFix, popData->Data);
                    strcat(postFix, " ");
                }

                LLS_DestroyNode(popData);
            }

            LLS_Push(stack,LLS_CreateNode(token));
        }
    }

    while(!LLS_IsEmpty(stack))
    {
        Node* popData = LLS_Pop(stack);

        if(popData->Data[0]!='(')
        {
            strcat(postFix, popData->Data);
            strcat(postFix, " ");
        }

        LLS_DestroyNode(popData);
    }

    LLS_DestroyStack(stack);
}

double Calculate(char* postFix)
{
    LinkedListStack* stack;
    Node*  nodeResult;

    double result;
    char token[32];
    int  type = -1;
    unsigned int position = 0;
    unsigned int len = strlen(postFix);

    LLS_CreateStack(&stack);

    while(position<len)
    {
        position+=GetNextToken(&postFix[position], token, &type);

        if(type==' ')
            continue;

        if(type==OPERAND)
        {
            Node* newNode = LLS_CreateNode(token);
            LLS_Push(stack, newNode);
        }
        else
        {
            char str[32];
            double op1, op2, temp;
            Node* opNode;

            opNode = LLS_Pop(stack);
            op2 = atof(opNode->Data);
            LLS_DestroyNode(opNode);

            opNode = LLS_Pop(stack);
            op1 = atof(opNode->Data);
            LLS_DestroyNode(opNode);

            switch(type)
            {
	            case '+':
	                temp = op1 + op2;
	                break;
	            case '-':
	                temp = op1 - op2;
	                break;
	            case '*':
	           		temp = op1 * op2;
	           		break;
	            case '/':
	            	if(op2==0)
	            	{
	            		printf("Error : Can't divide 0 (NaN). \n");
	            		exit(0);
	            	}
	            	temp = op1 / op2;
	            	break;
            }

            //gcvt(temp, 10, str);
            sprintf(str, "%0.08f", temp);
            LLS_Push(stack, LLS_CreateNode(str));
        }
    }

    nodeResult = LLS_Pop(stack);
    result = atof(nodeResult->Data);
    //printf("result?????: %s\n", nodeResult->Data);
    LLS_DestroyNode(nodeResult);
    LLS_DestroyStack(stack);

    return result;
}

int eqErrorChk(char *inFix)
{
  char *chkStr=inFix;
  int flag=0;
  int isError=0;

  int i;

  if(chkStr[0]=='+'||chkStr[0]=='-')
    flag=2;

  for(i=0;i<strlen(inFix);i++)
  {
    if(chkStr[i]==' ')
      continue;
	/*
    if(chkStr[i-1]=='('&&flag==1)
      continue;
	  */
    if(chkStr[i]=='-'||chkStr[i]=='*'||chkStr[i]=='/'||chkStr[i]=='^'||chkStr[i]=='+')
    {
      if(flag==1)
        isError=1;
    }
    if(chkStr[i]=='(')
    {
      if(flag==2)
        isError=1;
      if(chkStr[i+1]=='+'||chkStr[i+1]=='-')
        flag=1;
      if(chkStr[i+1]=='*'||chkStr[i+1]=='/')
        isError=1;
	  if((flag==1||flag==2)&&isError==1)
	  {
		  isError=0;
		  flag=0;
	  }
    }
    if(chkStr[i]==')')
    {
      if(flag==1&&isError==0)
        flag=0;
    }

    if(chkStr[i+1]=='\0') //ex. +1, +3, ..
    {
      if(flag==2)
        isError=1;
    }
  }
  
  return isError;
}

void addZero(char *inFix)
{
  int i=0;

  if(inFix[0]=='-')
   {
  	 	memmove(inFix+1, inFix, strlen(inFix)+1);
   		inFix[0]='0';
   }

  for(i=0;i<strlen(inFix);i++)
  {
    if(inFix[i]=='('&&(inFix[i+1]=='-'||inFix[i+1]=='+'))
    {
      i+=1;
      memmove(inFix+i+1, inFix+i, strlen(inFix)-i+1);
      inFix[i]='0';
    }
  }
}

double ConstCalculation(char* exp)
{
	char *postFix=(char*)malloc(sizeof(char)*100);
    double result;
	
	if(eqErrorChk(exp))
	{
		printf("inFix Error!\n");
		exit(0);
	}
	else
	{
		addZero(exp);
		GetPostfix(exp, postFix);
        result=Calculate(postFix);
        free(postFix);
		return result;
	}
}