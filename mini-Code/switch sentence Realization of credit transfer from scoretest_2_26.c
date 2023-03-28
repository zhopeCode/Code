#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int userScore, sum;
	char userGrade;					//定义变量
	printf(" 请输入分数：");					//提升输入分数
	scanf("%d", &userScore);						//接收分数
	if (userScore >= 0 && userScore <= 100)	//如果是一个正确的百分制的成绩
	{
		sum = userScore / 10;							//成绩整除10
		switch (sum)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:userGrade = '2'; break;	//60分以下的转换为2分
		case 6:
		case 7:userGrade = '3'; break;	//80分以下的转换为3分
		case 8:userGrade = '4'; break;	//90分以下的转换为4分
		case 9:								//100分以下和100分转化为5分
		case 10:userGrade = '5'; break;
		}
		printf("分数等级是%c\n", userGrade);	//输出五分制成绩
	}
	else
	{
		printf("错误数据!\n");
	}
	return 0;
}
