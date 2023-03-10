#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//二分查找法
int main()
{
	int userArr[] = { 0,1,2,3,4,5,6,7,8,9,10 };//整形有序数组
	int userLeft = 0;//范围左
	int userright = (sizeof userArr / sizeof userArr[0]) - 1;//范围右
	int userMid = 0;//查找下标
	int userNum = 10;//被查找数
	while (userLeft <= userright)
	{
		userMid = (userLeft + userright) / 2;//进行数组的二分
		if (userArr[userMid] > userNum)//将右范围缩小
		{
			userright = userMid - 1;
		}
		else if (userArr[userMid] < userNum)//将左范围缩小
		{
			userLeft = userMid + 1;
		}
		else//找到
		{
			printf("数组下标为:%d\n", userMid);
			break;
		}
	}
	if (userLeft > userright)//没找到
	{
		printf("找不到");
	}

	return 0;
}
