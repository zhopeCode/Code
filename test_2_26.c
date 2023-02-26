#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int score, s; char grade;					//定义变量
	printf(" 请输入分数：");					//提升输入分数
	scanf("%d", &score);						//接收分数
	if (score >= 0 && score <= 100)	//如果是一个正确的百分制的成绩
	{
		s = score / 10;							//成绩整除10
		switch (s)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:grade = '2'; break;	//60分以下的转换为2分
		case 6:
		case 7:grade = '3'; break;	//80分以下的转换为3分
		case 8:grade = '4'; break;	//90分以下的转换为4分
		case 9:								//100分以下和100分转化为5分
		case 10:grade = '5'; break;
		}
		printf("分数等级是%c\n", grade);	//输出五分制成绩
	}
	else
		printf("错误数据!\n");
	return 0;
}