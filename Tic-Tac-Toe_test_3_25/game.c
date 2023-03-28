#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//打印主菜单
void menu()
{
	printf("*******************************\n");
	printf("**********1.开始游戏***********\n");
	printf("**********0.退出游戏***********\n");
	printf("*******************************\n");
}

//游戏函数
void game()
{
	char board[userX][userY];
	init_board(board, userX, userY);//初识化棋盘
	char ret = 0;
	while (1)
	{
		display_board(board, userX, userY);//打印棋盘
		player_move(board, userX, userY);//玩家移动
		ret = Who_win(board, userX, userY);//判断输赢
		if (ret != 'C')
		{
			break;
		}
		display_board(board, userX, userY);//打印棋盘
		bot_move(board, userX, userY);//电脑移动
		ret = Who_win(board, userX, userY);//判断输赢
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
		display_board(board, userX, userY);
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
		display_board(board, userX, userY);
	}
	else
	{
		printf("平局\n");
		display_board(board, userX, userY);
	}
}

void init_board(char board[userX][userY], int X, int Y)//初始化棋盘
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

void display_board(char board[userX][userY], int X, int Y)//打印棋盘
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

void player_move(char board[userX][userY], int X, int Y)//玩家移动
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("玩家走:>");
		scanf("%d %d", &j, &i);
		if (i >= 1 && i <= Y && j >= 1 && j <= X)
		{
			if (board[j - 1][i - 1] == ' ')
			{
				board[j - 1][i - 1] = '*';
				break;
			}
		}
		printf("位置错误请重新输入\n");
	}
}

void bot_move(char board[userX][userY], int X, int Y)//电脑移动
{
	while (1)
	{
		int i = rand() % Y;
		int j = rand() % X;
			if (board[j][i] == ' ')
			{
				board[j][i] = '#';
				printf("电脑走:>%d %d\n", j + 1, i + 1);
				break;
			}		
	}	
}

char Who_win(char board[userX][userY], int X, int Y)//判断输赢
{
	int i = 0;
	int j = 0;
	for (j = 0; j < X; j++)
	{
		if (board[j][0] == board[j][1] && board[j][1] == board[j][2] && board[j][0] != ' ')//判断列元素相等无视空格
		{
			return board[j][0];
		}
	}
	for (i = 0; i < Y; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')//判断行元素相等无视空格
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];																							//交叉是否相等无视空格
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	int ret = 0;
	ret = Is_full(board, userX, userY);
	if (ret == 1)
	{
		return 'Q';//棋盘满返回Q
	}
	else
	{
		return 'C';//不满返回C
	}
}

int Is_full(char board[userX][userY], int X, int Y)//判断棋盘是否下满
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
