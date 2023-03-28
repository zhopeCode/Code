#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//检测素数
int main()
{
	int userNum = 0;

	for (userNum = 100; userNum <= 200; userNum++)//确定查找素数的范围
	{																			   //素数的定义:除了1和它自身外，不能被其他自然数整除的数叫做素数
		int userDivisor = 0;//声明一个除数

		for (userDivisor = 2; userDivisor < userNum; userDivisor++)//除数逻辑
		{
			if (userNum % userDivisor == 0)//被整除后跳出除数的 for 循环
			{
				break;
			}
		}
		if (userNum == userDivisor)//是不是素数
		{
			printf("%d ", userNum);
		}
	}
	return 0;
}
