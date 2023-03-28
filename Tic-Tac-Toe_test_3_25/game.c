#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//��ӡ���˵�
void menu()
{
	printf("*******************************\n");
	printf("**********1.��ʼ��Ϸ***********\n");
	printf("**********0.�˳���Ϸ***********\n");
	printf("*******************************\n");
}

//��Ϸ����
void game()
{
	char board[userX][userY];
	init_board(board, userX, userY);//��ʶ������
	char ret = 0;
	while (1)
	{
		display_board(board, userX, userY);//��ӡ����
		player_move(board, userX, userY);//����ƶ�
		ret = Who_win(board, userX, userY);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
		display_board(board, userX, userY);//��ӡ����
		bot_move(board, userX, userY);//�����ƶ�
		ret = Who_win(board, userX, userY);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
		display_board(board, userX, userY);
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
		display_board(board, userX, userY);
	}
	else
	{
		printf("ƽ��\n");
		display_board(board, userX, userY);
	}
}

void init_board(char board[userX][userY], int X, int Y)//��ʼ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			board[j][i] = ' ';
		}
	}
}

void display_board(char board[userX][userY], int X, int Y)//��ӡ����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			printf(" %c ", board[j][i]);
			if (j < X - 1)
			{
				putchar('|');
			}
		}
		putchar('\n');
		if (i < Y - 1)
		{
			for (j = 0; j < X; j++)
			{
				printf("---");
				if (j < X - 1)
				{
					putchar('|');
				}
			}
			putchar('\n');
		}
	}
	putchar('\n');
}

void player_move(char board[userX][userY], int X, int Y)//����ƶ�
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("�����:>");
		scanf("%d %d", &j, &i);
		if (i >= 1 && i <= Y && j >= 1 && j <= X)
		{
			if (board[j - 1][i - 1] == ' ')
			{
				board[j - 1][i - 1] = '*';
				break;
			}
		}
		printf("λ�ô�������������\n");
	}
}

void bot_move(char board[userX][userY], int X, int Y)//�����ƶ�
{
	while (1)
	{
		int i = rand() % Y;
		int j = rand() % X;
			if (board[j][i] == ' ')
			{
				board[j][i] = '#';
				printf("������:>%d %d\n", j + 1, i + 1);
				break;
			}		
	}	
}

char Who_win(char board[userX][userY], int X, int Y)//�ж���Ӯ
{
	int i = 0;
	int j = 0;
	for (j = 0; j < X; j++)
	{
		if (board[j][0] == board[j][1] && board[j][1] == board[j][2] && board[j][0] != ' ')//�ж���Ԫ��������ӿո�
		{
			return board[j][0];
		}
	}
	for (i = 0; i < Y; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')//�ж���Ԫ��������ӿո�
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];																							//�����Ƿ�������ӿո�
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	int ret = 0;
	ret = Is_full(board, userX, userY);
	if (ret == 1)
	{
		return 'Q';//����������Q
	}
	else
	{
		return 'C';//��������C
	}
}

int Is_full(char board[userX][userY], int X, int Y)//�ж������Ƿ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			if (board[j][i] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
