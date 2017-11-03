#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX 100
#define POSNAME 0
#define MAXNAME 20
#define POSAGE 20
#define MAXAGE 3
#define POXSCORE 23
#define MAXSCORE 3
#define POSID 26
#define MAXID 8
/*
  1 nhap
  2 xoa
  3 in
  4 tim
  5 ket thuc
*/
void inputData(char array[MAX][MAX], short *n);
void outputData(char array[MAX][MAX], short top, short bottom);
void menu();
void find(char array[MAX][MAX], short n);
void removeStudent(char array[MAX][MAX], short *n);
short checkId(char id[MAXID], char array[MAX][MAX], short n);
int main()
{
	char classroom[MAX][MAX] = {' '};
	short a = 0;
	short n = 0;
	do
	{
		menu();
		scanf("%d",&a);
		getchar();
		switch(a)
		{
			case 1:
			{
				inputData(classroom,&n);
				break;
			}
			case 2:
			{
				removeStudent(classroom, &n);
				break;
			}
			case 3:
			{
				outputData(classroom,1,n);
				printf("\n");
				printf("End!");
				break;
			}
			case 4:
			{
				find(classroom, n);
				break;
			}
			case 5:
			{
				break;
			}
			default:
			{
				printf("Invalid input, try again!\n");
			}
		}
	}while(a != 5);
	return 0;
}
void inputData(char array[MAX][MAX], short *n)
{
	short i;
	char *temp = (char *) calloc(20, sizeof(char));
	short count = 0;
	(*n)++;
	printf("Input student's name: ");
	gets(temp);
	for (i = 0; i < MAXNAME; i++)
	{
		array[*n][i] = temp[count];
		count++;
	}
	count = 0;

	printf("Input student's age: ");
	gets(temp);
	for (i = 20; i < 20 + MAXAGE; i++)
	{
		array[*n][i] = temp[count];
		count++;
	}
	count = 0;

	printf("Input student's score: ");
	gets(temp);
	for (i = 30 ; i < 30 + MAXSCORE; i++)
	{
		array[*n][i] = temp[count];
		count++;
	}
	count = 0;

	printf("Input student's ID: ");
	gets(temp);
	for (i = 40; i < 40 + MAXID; i++)
	{
		array[*n][i] = temp[count];
		count++;
	}
	free(temp);
}
void outputData(char array[MAX][MAX], short top, short bottom)
{
	if(top != 0)
	{
		short i;
		for(i = top; i <= bottom; i++)
		{
			short j;
			for (j = 0; j < MAX; j++)
			{
				printf("%c", array[i][j]);
			}
			printf("\n");
		}
	}
}
void menu()
{
	printf("\n\tClass A\n");
	printf("\tPress 1 to add 1 student\n");
	printf("\tPress 2 to remove a student (use student's id)\n");
	printf("\tPress 3 to see class information\n");
	printf("\tPress 4 to find a strudent (use student's id)\n");
	printf("\tPress 5 to exit\n");
	printf("********************************************************************************\n");
	printf("Your option (1:5):");
}
void find(char array[MAX][MAX], short n)
{
	char id[MAXID] ={' '};
	printf("\nInput student's id: ");
	gets(id);
	short i = checkId(id, array, n);
	printf("i = %d\n", i);
	if( i > 0)
	{
		outputData(array, i, i);
	}
	else
	{
		printf("Invalid ID!");
	}
}
void removeStudent(char array[MAX][MAX], short *n)
{
	short i, j;
	char id[MAXID];
	printf("\nInput student's ID: ");
	gets(id);
	i = checkId(id, array, *n);
	if(i > 0)
	{
		for(j = 0;j <= MAX; j++)
		{
			array[i][j] = ' ';
		}
		for(i ; i <= *n; i++)
		{
			for(j=0; j < MAX; j++)
			{
				array[i][j] = array[i+1][j];
			}
		}
		(*n)--;
	}
	else
	{
		printf("Invalid ID!");
	}
}
short checkId(char id[MAXID], char array[MAX][MAX], short n)
{
	short i, j, k = 0, count = 0;
	printf("\n");
	for(i = 1; i <= n; i++)
	{
		for(j = POSID; j < POSID + MAXID; j++)
		{
			if(id[k] != array[i][j])
			{
				break;
			}
			k++;
			//count++;
		}
		if(k == 8) 
		{
			return i;
		}
		//count = 0;
		k = 0;
	}
	printf("-3\n");
	return 0;
}
