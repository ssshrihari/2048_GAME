
//Author:Shrihari shetty

//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void show_board(int **board, int size_of_board);
int fib[17] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377,
610, 987, 1597 }, moves = 0;
//FIBBONACI CHECK
int *fibonacci_check(int number)
{
	int *a = (int*)calloc(2, sizeof(int));
	int i;
	for (i = 1; i<16; i++)
	{
		if (number == fib[i])
		{
			a[0] = fib[i - 1];
			a[1] = fib[i + 1];
		}
	}
	return a;
}
//CHECK ADJACENT ELEMENTS
int check_adjacent(int *adjacent, int **board, int i, int j, int size)
{
	if (i == 0 && j == 0)
	{
		if ((board[i + 1][j] == adjacent[0] || board[i + 1][j] == adjacent[1])
			|| (board[i][j + 1] == adjacent[0] || board[i][j + 1] == adjacent[1]))
			return 1;
		else
			return 0;
	}
	else if (i == 0 && j == size - 1)
	{
		if ((board[i][j - 1] == adjacent[0] || board[i][j - 1] == adjacent[1])
			|| (board[i + 1][j] == adjacent[0] || board[i + 1][j] == adjacent[1]))
			return 1;
		else
			return 0;
	}
	else if (i == size - 1 && j == 0)
	{
		if ((board[i - 1][j] == adjacent[0] || board[i - 1][j] == adjacent[1])
			|| (board[i][j + 1] == adjacent[0] || board[i][j + 1] == adjacent[1]))
			return 1;
		else
			return 0;
	}
	else if (i == size - 1 && j == size - 1)
	{
		if ((board[i - 1][j] == adjacent[0] || board[i - 1][j] == adjacent[1])
			|| (board[i][j - 1] == adjacent[0] || board[i][j - 1] == adjacent[1]))
			return 1;
		else
			return 0;
	}
	else if (i == 0 && j != 0)
	{
		if ((board[i][j - 1] == adjacent[0] || board[i][j - 1] == adjacent[1])
			|| (board[i + 1][j] == adjacent[0] || board[i + 1][j] == adjacent[1])
			|| (board[i][j + 1] == adjacent[0] || board[i][j + 1] == adjacent[1]))
			return 1;
		else
			return 0;
	}
	else if (i != 0 && j == 0)
	{
		if ((board[i - 1][j] = adjacent[0] || board[i - 1][j] == adjacent[1])
			|| (board[i + 1][j] == adjacent[0] || board[i + 1][j] == adjacent[1])
			|| (board[i][j + 1] == adjacent[0] || board[i][j + 1] == adjacent[1]))
			return 1;
		else
			return 0;
	}
	else if (i == 3 && j != 0)
	{
		if ((board[i][j - 1] == adjacent[0] || board[i][j - 1] == adjacent[1])
			|| (board[i][j + 1] == adjacent[0] || board[i][j + 1] == adjacent[1])
			|| (board[i - 1][j] == adjacent[0] || board[i - 1][j] == adjacent[1]))
			return 1;
		else
			return 0;
	}
	else if (i != 0 && j == 3)
	{
		if ((board[i - 1][j] == adjacent[0] || board[i - 1][j] == adjacent[1])
			|| (board[i + 1][j] == adjacent[0] || board[i + 1][j] == adjacent[1])
			|| (board[i][j - 1] == adjacent[0] || board[i][j - 1] == adjacent[1]))
			return 1;
		else
			return 0;
	}
	else
	{
		if (board[i][j - 1] == adjacent[0] || board[i][j - 1] == adjacent[1]
			|| board[i][j + 1] == adjacent[0] || board[i][j + 1] == adjacent[1] ||
			board[i - 1][j] == adjacent[0] || board[i - 1][j] == adjacent[1] ||
			board[i + 1][j] == adjacent[0] || board[i + 1][j] == adjacent[1])
			return 1;
		else
			return 0;
	}
}



//BOARD VERIFICATION
int verify_board(int **board, int size_of_board)
{
	int i, j;
	int *adjacent = (int*)calloc(size_of_board, sizeof(int));
	int zero = 0, loose_var = 0;
	for (i = 0; i < size_of_board; i++)
	{
		for (j = 0; j < size_of_board; j++)
		{
			if (size_of_board == 2 && board[i][j] == 13)
			{
				printf("YOU WIN IN %d MOVES", moves);
				getchar();
				return 0;
			}

			if (size_of_board == 4 && board[i][j] == 1597)
			{
				printf("YOU WIN IN %d MOVES", moves);
				getchar();
				return 0;
			}
			if (board[i][j] == 0)
				zero++;

		}

	}
		if (!zero)
		{
			for (i = 0; i < size_of_board; i++)
			{
				for (j = 0; j < size_of_board; j++)
				{
					adjacent = fibonacci_check(board[i][j]);
					if (check_adjacent(adjacent, board, i, j, size_of_board))
						break;
					else
						loose_var++;
				}
			}
		}


		if (loose_var == (size_of_board*size_of_board))
		{
			printf("YOU LOOSE IN %d MOVES", moves);
			getchar();
			return 0;
		}

		return 1;
	}



//RANDOM POSITION IN BOARD
void random_pos_board(int **board, int size_of_board)
{
	int z = 0,i,j;
	for (i = 0; i < size_of_board; i++)
	{
		for (j = 0; j < size_of_board; j++)
		{
			if (board[i][j] == 0)
			{
				board[i][j] = 1;
				z = 1;
				break;
			}
		}
		if (z == 1)
			break;
	}
	show_board(board, size_of_board);
}
//BOARD MOVEMENTS
void move_board_left(int **board, int size_of_board)
{
	int flag = 0, i, j, k = 0, l;
	int *temp1 = (int*)calloc(size_of_board, sizeof(int));
	int *temp = (int*)calloc(size_of_board, sizeof(int));
	for (i = 0; i < size_of_board; i++)
	{
		k = 0;
		for (j = 0; j < size_of_board; j++)
		{
			if (board[i][j] != 0)
				temp[k++] = board[i][j];

		}

		for (j = 0; j < size_of_board; j++)
		{
			for (l = 0; l < 16; l++)
				if (temp[j] + temp[j + 1] == fib[l])
				{
					temp[j] = fib[l];
					temp[j + 1] = 0;
					break;
				}
		}
		k = 0;
		for (j = 0; j < size_of_board; j++)
		{
			if (temp[j] != 0)
				temp1[k++] = temp[j];
		}
		for (j = 0; j < size_of_board; j++)
		{

			board[i][j] = temp1[j];
		}
		for (j = 0; j < size_of_board; j++)
		{

			temp1[j] = 0;
			temp[j] = 0;
		}


	}//for i end
	moves++;
	random_pos_board(board, size_of_board);
}//function end
void move_board_right(int **board, int size_of_board)
{
	int flag = 0, i, j, l;
	int *temp = (int*)calloc(size_of_board, sizeof(int));
	int *temp1 = (int*)calloc(size_of_board, sizeof(int));
	int k;
	k = size_of_board - 1;
	for (i = 0; i<size_of_board; i++)
	{
		k = size_of_board - 1;
		for (j = size_of_board - 1; j >= 0; j--)
		{
			if (board[i][j] != 0)
				temp[k--] = board[i][j];
		}

		for (j = size_of_board - 1; j >= 0; j--)
		{
			for (l = 0; l < 16; l++)
				if (temp[j] + temp[j - 1] == fib[l])
				{
					temp[j] = fib[l];
					temp[j - 1] = 0;
					break;
				}
		}
		k = size_of_board - 1;
		for (j = size_of_board - 1; j >= 0; j--)
		{
			if (temp[j] != 0)
				temp1[k--] = temp[j];
		}
		for (j = size_of_board - 1; j >= 0; j--)
		{
			board[i][j] = temp1[j];
		}
		for (j = 0; j < size_of_board; j++)
		{

			temp1[j] = 0;
			temp[j] = 0;
		}
	}

	moves++;
	random_pos_board(board, size_of_board);
	
}
void move_board_top(int **board, int size_of_board)
{
	int flag = 0, i, j, l;
	int *temp = (int*)calloc(size_of_board, sizeof(int));
	int *temp1 = (int*)calloc(size_of_board, sizeof(int));
	int k;
	k = 0;
	for (j = 0; j<size_of_board; j++)
	{
		k = 0;
		for (i = size_of_board - 1; i >= 0; i--)
		{
			if (board[i][j] != 0)
				temp[k++] = board[i][j];
		}

		for (i = 0; i <size_of_board; i ++)
		{
			for (l = 0; l < 17; l++)
				if (temp[i] + temp[i + 1] == fib[l])
				{
					temp[i] = fib[l];
					temp[i + 1] = 0;
					break;
				}
		}
		k = 0;
		for (i = size_of_board - 1; i >= 0; i--)
		{
			if (temp[i] != 0)
				temp1[k++] = temp[i];
		}
		for (i = 0; i < size_of_board; i++)
		{
			board[i][j] = temp1[i];
		}
		for (i = 0; i < size_of_board; i++)
		{

			temp1[i] = 0;
			temp[i] = 0;
		}
	}

	moves++;
	random_pos_board(board, size_of_board);
	
}
void move_board_bottom(int **board, int size_of_board)
{
	int x = 0;
	int flag = 0, i, j, k = 0, l;
	int *temp1 = (int*)calloc(size_of_board, sizeof(int));
	int *temp = (int*)calloc(size_of_board, sizeof(int));
	for (j = 0; j < size_of_board; j++)
	{
		x = 0;
		k = 0;
		for (i = 0; i < size_of_board; i++)
		{
			if (board[i][j] != 0)
				temp[k++] = board[i][j];

		}
		
		//printf("At first time %d %d\n\n", temp[0], temp[1]);
		for (i = 0; i < size_of_board; i++)
		{
			for (l = 0; l < 17; l++)
			{
				if (temp[i] + temp[i + 1] == fib[l])
				{
					temp[i] = fib[l];
					temp[i + 1] = 0;
					x++;
					break;
				}
			}
		}
		//printf("x is %d\n",x);
	//	printf("After fibo %d %d\n\n", temp[0], temp[1]);
		k = size_of_board - 1;
		for (i = size_of_board - 1; i >= 0; i--)
		{
			if (temp[i] != 0)
			{
				temp1[k] = temp[i];
				k--;
			}
		}
	//	printf("After  temp1 %d %d\n\n", temp1[0], temp1[1]);
		k = 0;
		
		for (i = 0; i <size_of_board; i++)
		{
			//printf("Finally %d ", temp1[k]);
			board[i][j] = temp1[k++];
			
		
		}
		k = size_of_board-1;
	/*	if (x == 0)
		{

			for (i = 0; i <size_of_board; i++)
			{
				printf("Finally %d ", temp1[k]);
				board[i][j] = temp1[k--];
			}

		}*/
		printf("\n");
		for (i = 0; i < size_of_board; i++)
		{

			temp1[i] = 0;
			temp[i] = 0;
		}
		
	}//for i end
	moves++;
	random_pos_board(board, size_of_board);

}




//RANDOM NUMBER GENERATION
int random_number(int min_num, int max_num)
{
	int result = 0, low_num = 0, hi_num = 0;

	if (min_num < max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1;
	}
	else {
		low_num = max_num + 1;
		hi_num = min_num;
	}

	srand(time(NULL));
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}





//GENERATION OF BOARD
int** generate_board(int size_of_board)
{
	int i;
	int **board = (int**)calloc(sizeof(int), size_of_board);
	for (i = 0; i<size_of_board; i++)
		board[i] = (int *)calloc(size_of_board, sizeof(int));
	return board;
}


//GAME CONSOLE
void game_play(int **board, int size_of_board)
{
	char move_option;
	while (verify_board(board, size_of_board))
	{
		printf("Enter your Move W A S D:\n");
		scanf_s(" %c", &move_option);
		system("cls");
		if (move_option == 'W' || move_option == 'w')
			move_board_top(board, size_of_board);
		else if (move_option == 'S' || move_option == 's')
			move_board_bottom(board, size_of_board);
		else if (move_option == 'A' || move_option == 'a')
			move_board_left(board, size_of_board);
		else if (move_option == 'D' || move_option == 'd')
			move_board_right(board, size_of_board);
	}
}

//BOARD DISPLAY
void show_board(int **board, int size_of_board)
{
	int i, j;
	printf("\n\n");
	printf("\n*********************************************************************\n\n");
	for (i = 0; i < size_of_board; i++)
	{
		printf("\t\t");
		for (j = 0; j < size_of_board; j++)
		{
			printf("\t|| %d ||", board[i][j]);
		}
		printf("\n\n");
	}
	printf("\n*********************************************************************\n");
}




//INSTRUCTION
char instructions()
{
	printf("\n ||BEFORE STARTING THE GAME||\n\n");
	printf("\n INSTRUCTION");
	printf("\n The user can play by pressing, W,A,S,D for up,left,down and right.\n");

		return 'W';
}




//TWO BY TWO BLOCK CODE
void two_by_two(int size_of_board)
{
	char option;
	int position_1 = 0, position_2 = 0, position_3 = 0, position_4 = 0;
	int **board = generate_board(2);
	//GENERATE RANDOM POSITIONS ON BOARD
	while (position_1 == position_3 && position_2 == position_4)
	{
		position_1 = random_number(0, 1);
		position_2 = random_number(0, 1);
		position_3 = random_number(0, 1);
		position_4 = random_number(0, 1);
	}
	board[position_1][position_2] = 1;
	board[position_3][position_4] = 1;
	option = instructions();
	if (option == 'W')
	{
		show_board(board, size_of_board);
		game_play(board, size_of_board);
	}
}




//FOUR BY FOUR BLOCK CODE
void four_by_four(int size_of_board)
{
	char option;
	int position_1 = 0, position_2 = 0, position_3 = 0, position_4 = 0;
	int **board = generate_board(4);
	//GENERATE RANDOM POSITIONS ON BOARD
	while (position_1 == position_3 && position_2 == position_4)
	{
		position_1 = random_number(0, 3);
		position_2 = random_number(0, 3);
		position_3 = random_number(0, 3);
		position_4 = random_number(0, 3);
	}
	board[position_1][position_2] = 1;
	board[position_3][position_4] = 1;

	option = instructions();
	if (option == 'W')
	{
		show_board(board, size_of_board);
		game_play(board, size_of_board);
	}
}



//TAKING PLAYER INPUT
void player_input()
{
	int option;
	char s[10];
	printf("\n\n\t\t\t|||Hello Welcome to 2048||||\n\n\n");
	printf("\n \t\t\t   |Enter your Username|\n\n   \t\t  \t\t");
	gets_s(s);
	system("cls");
	printf("\n\n\n \t\t\t HEY %s,hope you are doing good!!\n\n",s);
	printf("\t\t\t\t Options");
	printf("\n*******************************************************************************");
	printf("\t\t\t\t\t 1.Play Game\n");
	printf("\n*******************************************************************************");
	printf("\t\t\t\t\t 2.LeaderBoard\n");
	printf("\n*******************************************************************************");
	printf("\t\t\t\t\t 3.Load Game\n");
	printf("\n********************************************************************************\n\n\t\t\t\t\t");
	scanf_s(" %d", &option);
	while (option != 1)
	{
		printf("\n Enter correct option\n");
		scanf_s(" %d", &option);
	}
	system("cls");
}



//TAKING PLAYER GAME OF CHOICE
void game_selection()
{
	int  board_option;

	printf("\n\n\n \t\t\t||Choose the board||\n\n");
	printf("\n********************************************************************************\n");
	printf("\n\t\t\t 1:TWO-BY-TWO\n\n********************************************************************************\n\n\t\t\t 2->FOUR-BY-FOUR\n\n");
	printf("\n********************************************************************************\n\n");
	scanf_s(" %d", &board_option);

	while (board_option != 1 && board_option != 2)
	{
		printf("\nEnter correct option");
		scanf_s(" %d", &board_option);
	}

	system("cls");

	if (board_option == 1)
		two_by_two(2);
	if (board_option == 2)
		four_by_four(4);
}



//MAIN SECTION
int main()
{
	player_input();
	game_selection();
	getchar();
	return 0;
}


