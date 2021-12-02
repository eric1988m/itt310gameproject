// creating a tic tac toe game in c

#include <stdio.h>
#include <stdlib.h>

// print matrix
void printMatrix(char val);
// update value in matrix
void inserValue(int i, int j, unsigned char user);



unsigned char mat[3][3] = { '_', '_', '_', '_', '_', '_', '_', '_', '_' };
unsigned char onlyOnce = 0;
unsigned char usertern = 0;

int main()
{
	// unsigned char for users 1 and users
	unsigned char user1[35], user2[35], winner;
	int ival, jval;


	// print statement in quotation 
	printf("\nEnter name of user1 : ");
	// get user input 
	gets(user1);

	
	// print statement in quotation
	printf("Enter name of user2 :");
	// get user input
	gets(user2);
	
	
	

again:
	// print 4 new lines
	printf("\n\n\n\n");
	// start of if statement
	if (!onlyOnce)
	{
		// print matrix and line up
		printMatrix(1);
		// onlyonce equals 1
		onlyOnce = 1;
	}
	// else 
	else
	{
		//printMatrix 
		printMatrix(1);
	}
	winner = isOver();

	if (winner)
	{
		pr
	}
	
}
// print matrix parameters
void printMatrix(char val)
{
	// unsigned char i and j 
	unsigned char i, j;
	if (!val)
	{
		/* for blank matridx*/

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