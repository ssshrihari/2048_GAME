// 2048_GAME.cpp : Defines the entry point for the console application.
//Author:Shrihari shetty

//HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int moves = 0;
//FIBBONACI CHECK
int *fibonacci_check(int number)
{
	int *a=(int*)callac(2,sizeof(int));
	int fib[17]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597};
	for(i=1;i<16;i++)
	{
		if(number==fib[i])
		{
			a[0]=fib[i-1];
		         a[1]=fib[i+1];
		}
	}
	return a;
}
		
	
//BOARD VERIFICATION
int verify_board(int **board, int size_of_board)
{
	
        int zero=0,loose_var=0;
        for(i=0;i<size_of_board;i++)
         	{
	   for(j=0;j<size_of_board;j++)
		 {
		    if(size_of_board==2&&board[i][j]==13)
		        { 
			    printf("YOU WIN IN %d MOVES", moves);
	                     return 0;
		        }
		   
		    if(size_of_board==4&&board[i][j]==1597)
		        { 
			    printf("YOU WIN IN %d MOVES", moves);
	                     return 0;
		        }
		   if(board[i][j]==0)
			   zero++;
		   
	   }
			

	if(!zero)
	{
		for(i=0;i<size_of_board;i++)
		{
			for(j=0;j<size_of_board;j++)
			{
				*adjacent=fibonacci_check(a[i][j]);
				if(check_adjacent(adjacent))
					break;
				else
					loose_var++;
			}
		}
	}
		
			
		if(loose_var==(size_of_board*size_of_board))
		{
			printf("YOU LOOSE IN %d MOVES", moves);
                 	return 0;
		}
	
	return 1;
}



//BOARD MOVEMENTS
void move_board_left(int **board, int size_of_board)
{
	int flag=0,i,j;
	int *temp=(int*)calloc(size_of_board,sizeof(int))
    	for(i=0;i<size_of_board;i++)
       	{
		for(j=0;j<size_of_board;j++)
		{
			if(board[i][j]!=0)
				temp[k++]=board[i][j];
				
				
			
		}
		for(j=0;j<size_of_board;j++)
		{
			board[i][j]=temp[j];
		}
	}
      

	
	moves++;
}
void move_board_right(int **board, int size_of_board)
{
	int flag=0,i,j;
	int *temp=(int*)calloc(size_of_board,sizeof(int))
		int k;
	k=size_of_board-1;
    	for(i=0;i<size_of_board;i++)
       	{
		for(j=0;j<size_of_board;j++)
		{
			if(board[i][j]!=0)
				temp[k--]=board[i][j];
				
				
			
		}
		for(j=size_of_board-1;j>=0;j--)
		{
			board[i][j]=temp[j];
		}
	}
      

	
	moves++;
}
void move_board_top(int **board, int size_of_board)
{

	moves++;
}
void move_board_bottom(int **board, int size_of_board)
{
	moves++;

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
	int **board = (int**)calloc(sizeof(int),size_of_board);
	for (i = 0; i<size_of_board; i++)
		board[i] = (int *)calloc(size_of_board , sizeof(int));
	return board;
}




//BOARD DISPLAY
void show_board(int **board,int size_of_board)
{
	int i, j;
	char move_option;
	for (i = 0; i < size_of_board; i++)
	{
		for (j = 0; j < size_of_board; j++)
		{
			printf("\t%d ", board[i][j]);
		}
		printf("\n\n");
	}
	
//	scanf_s("%c[^\n]", &move_option);
	while(verify_board(board, size_of_board))
	{
		printf("Enter your Move W A S D:\n");
		scanf_s("%c[^\n]", &move_option);
		if (move_option == 'W' || move_option == 'w')
			move_board_top(board, size_of_board);
		else if (move_option == 'S' || move_option == 's')
			move_board_top(board, size_of_board);
		else if (move_option == 'A' || move_option == 'a')
			move_board_left(board, size_of_board);
		else if (move_option == 'D' || move_option == 'd')
			move_board_right(board, size_of_board);
	}
		
}




//INSTRUCTION
char instructions()
{
	char inst_option;
	printf("\n ||BEFORE STARTING THE GAME||\n\n");
	printf("\n INSTRUCTION");
	printf("\n The user can play by pressing, W,A,S,D for up,left,down and right.\n Enter W to continue");
	
	scanf_s("%c[^\n]", &inst_option);
	while (inst_option != 'W' && inst_option != 'w')
	{
		printf(" \nPlease enter W \n");
		scanf_s("%c[^\n]", &inst_option);
		
	}
	return inst_option;
}




//TWO BY TWO BLOCK CODE
void two_by_two(int size_of_board)
{
	char option;
	int position_1 = 0, position_2 = 0, position_3 = 0, position_4 = 0;
	int **board=generate_board(2);
	//GENERATE RANDOM POSITIONS ON BOARD
	while (position_1 == position_3 && position_2 == position_4)
	{
		position_1= random_number(0, 1);
		position_2= random_number(0, 1);
		position_3 = random_number(0, 1);
		position_4 = random_number(0, 1);
	}
	board[position_1][position_2] = 1;
	board[position_3][position_4] = 1;
	option=instructions();
	if (option == 'W'||option=='w')
		show_board(board, size_of_board);

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
	if (option == 'W' || option == 'w')
		show_board(board, size_of_board);
}



//TAKING PLAYER INPUT
void player_input()
{
	int option;
	char s[10];
	printf("\t\t\t|||Hello Welcome to 2048||||\n\n\n");
	printf("\n Enter a Username\n\n");
	gets_s(s);
	system("cls");
	printf("\n Choose");
	printf("\n 1.Play Game\n\n");
	scanf_s("%d", &option);
	while (option != 1)
	{
		printf("\n Enter correct option");
		scanf_s("%d", &option);
	}
	system("cls");
}



//TAKING PLAYER GAME OF CHOICE
void game_selection()
{
	int  board_option;

	printf(" Choose the board");
	printf("\n 1:2*2 \n 2:4*4\n\n");
	scanf_s("%d[^\n]", &board_option);

	while (board_option != 1 && board_option != 2)
	{
		printf("\nEnter correct option");
		scanf_s("%d", &board_option);
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
