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
	unsigned char user1[30], user2[30], winner;
	int ival, jval;


	// print statement in quotation 
	printf("\nEnter name of user1 : ");
	// get user input 
	gets(user1);
	fflush(stdin);

	
	// print statement in quotation
	printf("Enter name of user2 :");
	// get user input
	gets(user2);
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
	// execute isover function
	winner = isOver();

	if (winner)
	{
		// print the statement
		printf("\n *** Congratulations dear %s, \n You have won the game!!!!", ((winner == 'X') ? user1 : user2));
		goto end;

	}

	if (!isFull())
	{
		// print the statement
		printf("\n *** Game over!!!");
		goto end;
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


end:
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


unsigned char isOver(void)
{

	unsigned char i, j, user;
	unsigned char storeChar = 0, flag;
	int sum = 0;
	// case 1
	// sum of x+x+x = 264 and sum of o+o+o = 237
	flag = 0;
	for (i = 0; i < 3; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			if (mat[i][j] == '_')
				break;
			sum += mat[i][j];
			storeChar = mat[i][j];
		}

		if (sum == 237 || sum == 264)
		{
			return storeChar;
		}
	}


	// case 2
	for (i = 0; i < 3; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			if (mat[j][i] == '_')
				break;
			sum += mat[j][i];
			storeChar = mat[j][i];
		}

		if (sum == 237 || sum == 264)
		{
			return storeChar;
		}
	}

	//case 3 
	for (i = 0; i < 3; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			if (i == j)
			{
				if (mat[i][j] == '_')
					break;
				sum += mat[i][j];
				storeChar = mat[i][j];
			}
		}
		if (sum == 237 || sum == 264)
		{
			return storeChar;
		}
	}

	return 0;
}

unsigned char isFull(void)
{
	unsigned char i, j, count = 0;
	;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (mat[i][j] == '_')
				++count;
		}
	return count;
				
}