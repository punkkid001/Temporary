#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1024
#define LIST_SIZE 27 //A~Z + others
#define TRUE 1
#define FALSE 0

int fin_column=-1;

typedef struct _node
{
	char *string;
	int row;
	int column;
	struct _node* next;
}node;

typedef node* nptr;

typedef struct _list
{
	int count;
	nptr head;
}list;

void init(list* lptr)
{
	lptr->count = 0;
	lptr->head = NULL;
}

void makeLower(char *str)
{
	int i, length=strlen(str);

	for(i=0;i<length;i++)
	{
		if(isupper(str[i]))
			str[i]=tolower(str[i]);
	}
}

void insertSetting(list *lptr[], char *str, int row, int column)
{
	char index =toupper(str[0]) - 'A';

 	//count >=5 ; save in 'others'
	if(lptr[index]->count >= 5)
		index = 26;

	makeLower(str);

	nptr new_nptr = (node*)malloc(sizeof(node));
	new_nptr->string = (char*)malloc(strlen(str)+1);
	strcpy(new_nptr->string,str);
	new_nptr->next = lptr[index]->head;

	new_nptr->row=row;
	new_nptr->column=column;

	lptr[index]->head = new_nptr;
	lptr[index]->count++;

	free(str);
}

void insertFixBug(list* lptr[], char* str, int row, int column)
{
	char index = toupper(str[0]) - 'A';
	if(lptr[index]->count >= 5)
		index = 26;

	nptr new_nptr = (node*)malloc(sizeof(node));
	new_nptr->string = (char*)malloc(strlen(str)+1);
	strcpy(new_nptr->string,str);

	new_nptr->next = lptr[index]->head;

	new_nptr->row=row;
	new_nptr->column=column;

	lptr[index]->head = new_nptr;
	lptr[index]->count++;

	printf("INSERT: %d %d @ %d\n", new_nptr->row, new_nptr->column, lptr[index]->count);

	free(str);
}

void insert(list* lptr[], char* str)
{
	char index = toupper(str[0]) - 'A';
	if(lptr[index]->count >= 5)
		index = 26;

	nptr new_nptr = (node*)malloc(sizeof(node));
	new_nptr->string = (char*)malloc(strlen(str)+1);
	strcpy(new_nptr->string,str);

	new_nptr->next = lptr[index]->head;

	lptr[index]->head = new_nptr;
	lptr[index]->count++;

	printf("INSERT: %d %d @ %d\n", new_nptr->row, new_nptr->column, lptr[index]->count);

	free(str);
}

void PRINT(list *lptr[])
{
	int i;  //index
	nptr new_nptr;
	for(i=0;i<=26;i++)
	{
		new_nptr=lptr[i]->head;
		if(lptr[i]->count>0)
		{
			int j;
			for(j=0;j<lptr[i]->count;j++)
      		{
        		if(new_nptr!=NULL)
        		{
          			printf("list[%d] : %s \n", i, new_nptr->string);
          			new_nptr=new_nptr->next;
        		}
		        else
        		  break;
	    	}
    	}
    }
}

int search(list *lptr[], char* str, int debug)
{
	char index = toupper(str[0]) - 'A';
	int isExist = FALSE;
	if(lptr[index]->count > 0 )
	{
		int i;
		nptr tmp_nptr = lptr[index]->head;
		for(i = 0; i < lptr[index]->count; i++)
		{
			if(strcmp(tmp_nptr->string,str) == 0)
			{
				isExist = TRUE;
				break;
			}
			tmp_nptr = tmp_nptr->next;
		}

		if(lptr[index]->count==5 && lptr[26]->count>0 && isExist!=TRUE)
		{
			tmp_nptr = lptr[26]->head;
			for(i = 0; i < lptr[26]->count; i++){
				if(strcmp(tmp_nptr->string,str) == 0)
				{
					isExist = TRUE;
					break;
				}
				tmp_nptr = tmp_nptr->next;
			}
		}
		if(debug == 0)
			return isExist;

		if(isExist == TRUE)
			printf("SEARCH: %d %d \n", tmp_nptr->row, tmp_nptr->column);
		else
			printf("SEARCH: -1 -1\n");
	}

	else
	{
		if(debug == 1)
			printf("SEARCH: -1 -1\n");
	}

	return isExist;
}

int search_insert_check(list *lptr[], char* str, int debug)
{
	char index = toupper(str[0]) - 'A';
	int isExist = FALSE;
	if(lptr[index]->count > 0 )
	{
		int i;
		nptr tmp_nptr = lptr[index]->head;
		for(i = 0; i < lptr[index]->count; i++)
		{
			if(strcmp(tmp_nptr->string,str) == 0)
			{
				isExist = TRUE;
				break;
			}
			tmp_nptr = tmp_nptr->next;
		}

		if(lptr[index]->count==5 && lptr[26]->count>0 && isExist!=TRUE)
		{
			tmp_nptr = lptr[26]->head;
			for(i = 0; i < lptr[26]->count; i++){
				if(strcmp(tmp_nptr->string,str) == 0)
				{
					isExist = TRUE;
					break;
				}
				tmp_nptr = tmp_nptr->next;
			}
		}
		if(debug == 0)
			return isExist;

		if(isExist == TRUE)
			printf("INSERT: %d %d \n", tmp_nptr->row, tmp_nptr->column);
	}

	return isExist;
}

void delete(list *lptr[], char* str)
{
	char index = toupper(str[0]) - 'A';
	int isExist = FALSE;
	int level = 0;

	if(lptr[index]->count>0)
	{
		int i;
		nptr tmp_nptr = lptr[index]->head;
		nptr prev_nptr;
		for(i = 0; i< lptr[index]->count; i++)
		{
			if(strcmp(tmp_nptr->string,str) == 0)
			{
				free(tmp_nptr->string);

				isExist = TRUE;
				level = 1;
				lptr[index]->count--;

				if(i == 0)
					lptr[index]->head = tmp_nptr->next;
				else
					prev_nptr->next = tmp_nptr->next;

				break;
			}
			prev_nptr = tmp_nptr;
			tmp_nptr = tmp_nptr->next;
		}

		if(lptr[index]->count == 5 && lptr[26]->count > 0&&isExist!=TRUE)
		{
			tmp_nptr = lptr[26]->head;
			for(i = 0; i< lptr[26]->count; i++)
			{
				if(strcmp(tmp_nptr->string,str) == 0)
				{
					free(tmp_nptr->string);

					isExist = 1;
					level = 2;
					lptr[26]->count--;

					if(i == 0)
						lptr[26]->head = tmp_nptr->next;
					else
						prev_nptr->next = tmp_nptr->next;
					break;
				}
				prev_nptr = tmp_nptr;
				tmp_nptr = tmp_nptr->next;
			}
		}

		if(isExist == TRUE)
			printf("DELETE: %d %d @ %d\n", tmp_nptr->row, tmp_nptr->column, lptr[index]->count);
		else
			printf("DELETE: -1 -1 @ -1\n");
	}

	else
		printf("DELETE: -1 -1 @ -1\n");
}

char* subString (const char* input, int offset, int length, char* dst)
{
	int input_len = strlen (input);

	if (offset + length > input_len)
		return NULL;

 	strncpy (dst, input + offset, length);
	dst[length] = '\0';

	return dst;
}

char* onlyalpha(char* s)
{
	int i;
	int idx_first = -1;
	int idx_last = -1;
	int length;

	for(i = 0 ; i < strlen(s); i++)
	{
		if(idx_first == -1)
		{
			if(isalpha(s[i]))
				idx_first = i;
		}

		if(isalpha(s[i]))
			idx_last = i;
	}

	length = idx_last - idx_first + 1;

	char *dst = (char*)malloc(length);
  	subString(s,idx_first,idx_last-idx_first+1,dst);
	return dst;
}

void sort(list *lptr[], int index)
{
	list *l_temp=lptr[index];
	nptr new_nptr=lptr[index]->head;

	//nptr n_temp=NULL;
	nptr n_cmp=l_temp->head;

	char *str1;	//=n_temp1->string;
	char *str2;	//=n_temp2->string;
	char *temp;
	char *temp2;

	int temp_row, temp_column;

	int i, j;

	//printf("index %d - count : %d \n", index, lptr[index]->count);

	for(i=0;i<(lptr[index]->count);i++)
	{
		str1=new_nptr->string;
		n_cmp=new_nptr;

		for(j=i+1;j<=lptr[index]->count;j++)
		{
			str2=n_cmp->string;

			//printf("count [%d] ; str 1 : %s / str 2 : %s \n", i, str1, str2);

			//str2 is big -> dictionary back
			if(strcmp(str1, str2)>0)
			{
				temp2=str1;
				str1=str2;
				str2=temp2;

				temp=new_nptr->string;
				new_nptr->string=n_cmp->string;
				n_cmp->string=temp;

				temp_row=new_nptr->row;
				new_nptr->row=n_cmp->row;
				n_cmp->row=temp_row;

				temp_column=new_nptr->column;
				new_nptr->column=n_cmp->column;
				n_cmp->column=temp_column;
				//break;
			}
			n_cmp=n_cmp->next;
		}

		new_nptr=new_nptr->next;
	}
}

void writeASCII(FILE *fp, list *lptr[])
{
	int i;  //index
	nptr new_nptr;
	for(i=0;i<=26;i++)
	{
		new_nptr=lptr[i]->head;
		if(lptr[i]->count>0)
		{
			int j;
			for(j=0;j<lptr[i]->count;j++)
      {
        		if(new_nptr!=NULL)
        		{
								fprintf(fp, "%s ", new_nptr->string);
          			//printf("list[%d] : %s \n", i, new_nptr->string);
          			new_nptr=new_nptr->next;
        		}
		        else
        		  break;
	    	}
				//fprintf(fp, "\n", NULL);
    	}
			fprintf(fp, "\n", NULL);
    }
		fclose(fp);
}

void writeBinary(FILE *fp, list *lptr[])
{
	int i;  //index
	nptr new_nptr;
	for(i=0;i<=26;i++)
	{
		new_nptr=lptr[i]->head;
		if(lptr[i]->count>0)
		{
			int j;
			for(j=0;j<lptr[i]->count;j++)
      {
        		if(new_nptr!=NULL)
        		{
                char *str=new_nptr->string;
                str[strlen(str)]=' ';
                str[strlen(str)]='\0';
                new_nptr->string=str;
								fwrite(new_nptr->string, strlen(new_nptr->string), 1, fp);
								//fprintf(fp, "%s ", new_nptr->string);
          			//printf("list[%d] : %s \n", i, new_nptr->string);
          			new_nptr=new_nptr->next;
        		}
		        else
        		  break;
	    	}
				fwrite("\n", strlen("\n"), 1, fp);
    	}
    }
		fclose(fp);
}

int main(void)
{
	FILE *fp, *fp_b, *fp_a;
	char *lines[LIST_SIZE];
	char *line;

 	int file_size=0;

	list *mylist[LIST_SIZE];
	int row=0, column=-1, i;

	for(i = 0; i < LIST_SIZE; i++)
	{
		lines[i]=NULL;
		mylist[i] = (list*)malloc(sizeof(list));
		init(mylist[i]);
	}

	fp=fopen("myDic.bin", "r+b");
	/*
	if((fp=fopen("myDic.bin", "r+b"))==NULL)
    fp=fopen("myDic.bin", "w+b");
	*/

	//fp = fopen("voc_sample.txt", "r");

	if(fp!=NULL)
	{
		line = malloc(SIZE);

		fseek(fp, 0L, SEEK_END);
	 	file_size=ftell(fp);
	  fseek(fp, 0L, SEEK_SET);

	  int k=0, l=0;
	  fread(line, sizeof(char), file_size, fp);
		line[file_size]=0;

		lines[0]=strtok(line, "\n");
		char *temp=lines[0];

		while(temp!=NULL)
		{
			lines[++l]=strtok(NULL, "\n");
			temp=lines[l];
		}

		while (k<l)
		{
			//line_cut[strlen(line_cut)]='\0';
	    //printf("%d : %s\n", k+1, lines[k]);

			column=-1;
			row+=1;

			if (strlen(lines[k]) != 1)
			{
	            char *ptr;
	            ptr = strtok(lines[k], " ");
	            column++;

	            while (ptr != NULL)
	            {
	            	char *tmp = onlyalpha(ptr);

	            	if(strlen(tmp) > 0)
	            	{
	            		if(search(mylist,ptr,0) == 0)
	            			insertSetting(mylist,tmp, row, column);
	            	}

	            	ptr = strtok(NULL, " ");
	            	column++;
	            }
	      }
	      //line_cut=strtok(NULL, "\n");
	      //printf("2 result : %s\n", line_cut);
	      k++;
		}
		row++;

		//error
		for(i=0;i<=26;i++)
		{
			if(mylist[i]->head!=NULL)
				sort(mylist, i);
		}
	}
	//printf("hello\n");

	//PRINT(mylist);

	//sorting check
	/*
	printf("--------------Before sorting\n");
	PRINT(mylist);

	for(i=0;i<=26;i++)
	{
		if(mylist[i]->head!=NULL)
			sort(mylist, i);
	}
	printf("--------------After sorting\n");
	PRINT(mylist);
	*/

	while(1)
	{
		printf("기능을 선택하세요\n");
		printf("[1] Search [2] Insert\n");
		printf("[3] Delete [4] Write in ASCII\n");
		printf("[5] Write in binary [6] Quit\n");
		printf(": ");
		int select;
		scanf("%d",&select);
		char *input=(char*)malloc(sizeof(char*));
		switch(select){
			case 1:
			{
				printf("찾을 단어를 입력하세요: ");
				scanf("%s",input);
				search(mylist,input,1);
				break;
			}
			case 2:
			{
				printf("추가할 단어를 입력하세요: ");
				scanf("%s",input);
				input=onlyalpha(input);
				if(search(mylist,input,0)==0)
				{
					char index=toupper(input[0])-'A';
					insertFixBug(mylist,input, row, ++fin_column);
					if(mylist[index]->count<5)
						sort(mylist, index);
					else
						sort(mylist, 26);
					//PRINT(mylist);
				}
				else
					search_insert_check(mylist, input, 1);
				break;
			}
			case 3:
			{
				printf("삭제할 단어를 입력하세요: ");
				scanf("%s",input);
				delete(mylist,input);
				break;
			}
			//write in ascii
			case 4:
			{
				fp_a=fopen("myDic.txt","w+");
				writeASCII(fp_a, mylist);
				break;
			}
			//write in binary
			case 5:
			{
				fp_b=fopen("myDic.bin", "w+b");
				writeBinary(fp_b, mylist);
				break;
			}
			case 6:
			{
				printf("Quit...\n");
				free(line);
				fclose(fp_b);
				return 0;
				break;
			}
			default:
			{
				printf("잘못입력하셨습니다!\n");
				break;
			}
		}
	}

	free(line);
	fclose(fp_b);

	return 0;
}
