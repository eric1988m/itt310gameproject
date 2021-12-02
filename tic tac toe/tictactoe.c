// creating a tic tac toe game in c

#include <stdio.h>
#include <stdlib.h>

// print matrix
void printMatrix(char val);
// update value in matrix
void insertValue(int i, int j, unsigned char user);
// check matrix is full or not
unsigned char isFull(void);
//check game is completed or not
unsigned char isOver(void);



unsigned char mat[3][3] = { '_', '_', '_', '_', '_', '_', '_', '_', '_' };
unsigned char onlyOnce = 0;
unsigned char usertern = 0;

int main()
{
	// unsigned char for users 1 and users
	unsigned char user1[35], user2[35];
	int ival, jval;


	// print statement in quotation 
	printf("\nEnter name of user1 : ");
	// get user input 
	scanf_s(user1);
	fflush(stdin);

	
	// print statement in quotation
	printf("Enter name of user2 :");
	// get user input
	scanf_s(user2);
	fflush(stdin);

	
	
	

again:
	system("clear");
	// print 4 new lines
	printf("\n\n\n\n");
	// start of if statement
	if (!onlyOnce)
	{
		// print matrix and line up
		printMatrix(0);
		// onlyonce equals 1
		onlyOnce = 1;
	}
	// else 
	else
	{
		//printMatrix 
		printMatrix(1);
	}
	
	
repeat:
	fflush(stdin);
	printf("\n *** %s , Enter value (00-22) seperated by space :", (usertern == 0x00 ? user1 : user2));
	scanf_s("%d%d", &ival, &jval);
	if ((ival > 2 || ival < 0) || (jval > 2 || jval < 0))
	{
		printf("\n *** Error : invalid index, try again !!!");
		goto repeat;
	}
	if (mat[ival][jval] != '_')
	{
		printf("\n *** error : Already filled, try again !!!");
		goto repeat;
	}
	insertValue(ival, jval, usertern);
	usertern = !usertern;
	goto again;

	printf("\n");
	return 0;
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

void insertValue(int i, int j, unsigned char user)
{
	// printf("\n #### %d, %d ###\n",i,j);
	mat[i][j] = ((user == 0x00) ? 'X' : 'O');
}