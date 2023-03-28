//猜数字游戏
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void UserMenu()//菜单打印
{
	printf("********************\n");
	printf("******1.play********\n");
	printf("******0.exti********\n");
	printf("********************\n");
}


void UserGame()//游戏主体的实现
{
	int userRet = (rand() % 100) + 1;/*通过对 rand 取模 100 后必定为0~99再加 1 即可得到0~100
												最后赋值给 userRet 在22行的 while 中用于跟用户输入值比较*/
	int userGuess = 0;//用户的猜测值将赋值 userGuess

	while (1)
	{
		printf("\n你猜测的数字(范围为0~100)为:>");
		scanf("%d", &userGuess);//用户开始猜测数字
		if (userGuess > userRet)//用户猜大了继续循环
		{
			printf("猜大了\n");
		}
		else if (userGuess < userRet)//用户猜小了继续循环
		{
			printf("猜小了\n");
		}
		else//用户猜对了结束循环
		{
			printf("恭喜你猜对了\n\n");
			break;
		}
	}

}


int main()
{
	int userInput = 0;//菜单选择的值
	srand((unsigned int)time(NULL));/*时间戳转换为 srand 需要的 unsigned int 类型
														从而实现rand的随机*/
	do
	{
		UserMenu();
		printf("请选择:>");
		scanf("%d", &userInput);//用户开始选择
		switch (userInput)
		{
		case 1://用户选择为 1 开始游戏
			UserGame();
			break;
		case 0:
			printf("退出游戏\n");//用户选择为 0 退出游戏
			break;
		default:
			printf("\n选择错误重新选择\n");//用户输入错误的值后进行提示
		}
	} while (userInput);/*userInput = 1 时游戏结束后循环会继续， = 0 时则会退出游戏结束循环
							= 其它值后提示用户后继续循环*/
	return 0;
}
