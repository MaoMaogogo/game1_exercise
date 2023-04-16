
#include"game.h"


void welcome()
{
	printf("*******************************************\n");
	printf("*************     1.play       ************\n");
	printf("*************     2.exit       ************\n");
	printf("*******************************************\n");
}

void game()
{
	char board[ROW][COL];
	//棋盘空格初始化
	Initboard(board, ROW,COL);
	//棋盘格子初始化
	DisplayBoard(board, ROW, COL);

	char ret = 0;
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
		printf("平局\n");
}


int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		welcome();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}while(input);

	return 0;
}