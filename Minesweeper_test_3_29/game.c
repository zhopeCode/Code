#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()//打印菜单
{
	printf("*************************\n");
	printf("********1.开始游戏*******\n");
	printf("********0.退出游戏*******\n");
	printf("*************************\n");
}

void game()
{
	char mine[X2][Y2] = { 0 };//初始化
	char show[X2][Y2] = { 0 };//初始化

	init_board(mine, X2, Y2, '0');//初始化雷区
	init_board(show, X2, Y2, '*');//初始化显示区

	display_board(show, X1, Y1);//打印显示区

	set_mine(mine, X1, Y1);//设置雷
	//display_board(mine, X1, Y1);

	find_mine(mine, show, X1, Y1);//排查雷
}

void init_board(char board[X2][Y2], int x2, int y2, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < y2; i++)//遍历数组
	{
		for (j = 0; j < x2; j++)
		{
			board[j][i] = set;//赋值set中的字符
		}
	}
}

void display_board(char board[X2][Y2], int x1, int y1)
{
	printf("-----扫雷游戏-----\n");
	int i = 0;
	int j = 0;
	for (j = 0; j <= x1; j++)//打印横坐标
	{
		printf("%d ", j);
	}
	putchar('\n');
	for (i = 1; i <= y1; i++)
	{
		printf("%d ", i);//打印纵坐标
		for (j = 1; j <= x1; j++)
		{
			printf("%c ", board[j][i]);
		}
		putchar('\n');
	}
	printf("-----扫雷游戏-----\n");
}

void set_mine(char board[X2][Y2], int x1, int y1)
{
	int count = setMine;	
	while (count)
	{
		int i = rand() % y1 + 1;//控制雷设置在区域内
		int j = rand() % x1 + 1;
		if (board[j][i] == '0')//检测设置雷区域是否已经存在雷
		{
			board[j][i] = '1';
			count--;
		}
	}
}

static int get_mine_count(char mine[X2][Y2], int x, int y)//统计没雷区域周围8格有多少雷
{
	return
		mine[x][y - 1] +
		mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] - (8 * '0');//任意char类数字-48（-'0'）等于int类数字
}

void find_mine(char mine[X2][Y2], char show[X2][Y2], int x1, int y1)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < X1 * Y1 - setMine)//从0开始排查次数等于没雷区域
	{												//没雷区域=雷区减去雷 
		printf("请选择:>");					//假设3个没雷区	0 1 2 排查三次
		scanf("%d %d", &x, &y);
		if ((x < 1 || x > x1) || (y < 1 || y > y1))
		{
			printf("坐标错误，请重新选择\n");//检测坐标是否正确
			display_board(show, X1, Y1);
			continue;
		}
		if (mine[x][y] == '1')			//雷数组中1代表雷 0代表没雷
		{
			printf("踩到雷了，游戏结束!\n");
			display_board(mine, X1, Y1);
			break;
		}
		else
		{
			int ret = get_mine_count(mine, x, y);
			show[x][y] = (ret + '0');
			display_board(show, X1, Y1);
			win++;// 2 进入后自增 等于3 
		}
	}
	if (win == X1 * Y1 - setMine)// 不执行while 来到if判断 win = 3 = 没雷区数
	{											//游戏胜利
		printf("恭喜你！排雷成功！\n");
		display_board(mine, X1, Y1);
	}
}