// creating a tic tac toe game in c

#include <stdio.h>
#include <stdlib.h>

// print matrix
void printMatrix(char val);
unsigned char mat[3][3] = { '_', '_', '_', '_', '_', '_', '_', '_', '_' };
unsigned char onlyOnce = 0;


int main()
{
	unsigned char user1[35], user2[35], winner;
	int ival, jval;

	printf("\n Enter name of user1 :");
	scanf_s(user1);
	fflush(stdin);
	
	
	printf(" Enter name of user2 :");
	scanf_s(user2);
	fflush(stdin);


	system("clear");
	printf("\n\n\n\n");
	if (!onlyOnce)
	{
		printMatrix(0);
		onlyOnce = 1;
	}
	else
	{
		printMatrix(1);
	}
	
	printf("\n");
	return 0;
}

void printMatrix(char val)
{

	unsigned char i, j;
	if (!val)
	{

		for (i = 0; i < 3; i++)
		{
			printf("\t\t\t");
			for (j = 0; j < 3; j++)
			{
				printf("[%3c ] ", mat[i][j]);
			}

		}

		return;
	}
	for (i = 0; i < 3; i++)
	{
		printf("\t\t\t");
		for (j = 0; j < 3; j++)
		{
			printf("[%3c ] ", mat[i][j]);
		}
		printf("\n");
	}
	return;
}