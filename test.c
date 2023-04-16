
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
	//���̿ո��ʼ��
	Initboard(board, ROW,COL);
	//���̸��ӳ�ʼ��
	DisplayBoard(board, ROW, COL);

	char ret = 0;
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
		printf("ƽ��\n");
}


int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		welcome();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}while(input);

	return 0;
}