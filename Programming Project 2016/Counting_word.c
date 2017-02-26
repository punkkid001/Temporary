/*
  2016.5.2
  for Linux/MacOS (not Windows)
  Jiyoon, Ha
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024 //setting buffer size
#define TRUE 1
#define FALSE 0

//checking regular expression
int isRegex(char *str)
{
  int length=strlen(str);
  int i, count=0;

  for(i=0;i<length;i++)
  {
    if(str[i]=='*')
      count++;
  }

  if(count!=0)
    return TRUE;
  else
    return FALSE;
}

//remove consecutive star
void removeStar(char *str)
{
	int length=strlen(str);
	int i, j, k;

	for(i=0;i<length;i++)
	{
		if(str[i]=='*'&&i+1!=length)
		{
			if(str[i+1]=='*')
			{
				j=i+1;
				while(str[j+1]=='*')
					j++;
				k=i+1;
				while(str[j]!='\0')
				{
					str[k]=str[j+1];
					j++;
					k++;
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
    FILE *fp=NULL;  //file pointer
    char *regex=argv[1];  //save regular expression
    char *line; //reading line

    int line_num = 0; //save line number
    int count = 0;  //result counting..

    if(!isRegex(regex)) //if not regular expression
        printf("User's value is not regular expression..\n");
    else
    {
      fp = fopen("sample.txt", "r"); //loading text file
      if(fp==NULL)
      {
        printf("Can't load sample.txt file.\n");
        return 0;
      }
      line = malloc(SIZE);  //dynamic memory allocation for loading line

      removeStar(regex);

      //printf("****Load file : %s\n", argv[1]);
      //printf("argument regex text : %s\n", argv[2]);

      while (fgets(line, SIZE, fp)) //loading line
      {
          line[strlen(line)-1]='\0';  //remove '\n'
          count=0;

          if (strlen(line) != 1)
          {
              char *ptr;  //save work
              ptr = strtok(line, " ");  //split word and save

              while (ptr != NULL)
              {
                  int i = 0;
                  int result = TRUE;
                  int regex_index = 0;

                  //printf("%s \n", ptr);
                  //printf("length : %d\n", strlen(ptr));

                  for (i = 0; i <=strlen(ptr); i++)
                  {
                      if (regex[regex_index] == '*')  //if regular expression
                      {
                          if ((regex_index + 1) == strlen(regex)) //* is last character in regex
                          {
                              regex_index++;
                              break;
                          }
                          else
                          {
                              result = FALSE;
                              if (regex[regex_index + 1] == ptr[i])
                              {
                                  regex_index++;
                                  result = TRUE;
                              }
                          }

                      }

                      if (regex[regex_index] != '*' && i < strlen(ptr))
                      {
                          if (regex[regex_index] == ptr[i])
                          {
                              result = TRUE;
                              regex_index++;
                          }
                          else
                          {
                              result = FALSE;
                              break;
                          }
                      }
                  }

                  if (regex_index != strlen(regex))
                      result = FALSE;

                  if (result)
                      count++;
                  ptr = strtok(NULL, " ");
              }

              printf("%d ", count);
          }
      }

      fclose(fp);
    }

    printf("\n");

    return 0;
}
