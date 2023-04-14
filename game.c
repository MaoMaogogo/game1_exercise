#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//打印空白格
void  Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘格
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1) 
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j< col- 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) 
{
	int x = 0;
	int y = 0;
	while (1) 
	{
		printf("玩家下棋:>");
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断格子是否已经被占用
			if (board[x-1][y-1]==' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
			printf("输入坐标有误，请重新输入\n");

	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	printf("\n");
}


int IsFulle(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


char IsWin(char board[ROW][COL], int row, int col)
{

	int i = 0;
	int j = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 1] != ' ')
				return board[i][j + 1];
		}
	}
	//判断三列
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] && board[j + 1][i] != ' ')
				return board[j + 1][i];
		}
	}

	//判断对角
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i+1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] != ' ')
				return board[i + 1][j + 1];
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 2; j < col; j++)
		{
			if (board[i + 2][j + 2] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i][j] && board[i + 1][j + 1] != ' ')
				return board[i + 1][j + 1];
		}
	}

	//判断平局
	int ret = IsFulle(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	else
		return'C';
}