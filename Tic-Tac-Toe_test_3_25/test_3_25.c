#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main()
{
	int input = 0;
	do
	{
		srand((unsigned int)time(NULL));//随机值
		menu();										//打印菜单
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误请重新输入\n");
		}
	} while (input);	
	return 0;
}