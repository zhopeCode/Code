#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//二分查找法
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };//整形有序数组
	int left = 0;//范围左
	int right = (sizeof arr / sizeof arr[0]) - 1;//范围右
	int mid = 0;//查找下标
	int num = 10;//被查找数
	while (left <= right)
	{
		mid = (left + right) / 2;//进行数组的二分
		if (arr[mid] > num)//将右范围缩小
		{
			right = mid - 1;
		}
		else if (arr[mid] < num)//将左范围缩小
		{
			left = mid + 1;
		}
		else//找到
		{
			printf("数组下标为:%d\n", mid);
			break;
		}
	}
	if (left > right)//没找到
	{
		printf("找不到");
	}

	return 0;
}
