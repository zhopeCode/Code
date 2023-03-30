#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main()
{
	srand((unsigned int)time(NULL));//实现雷的随机
	int input = 0;//玩家菜单选择
	do
	{
		menu();
		printf("请选择(1/0):>");
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
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}