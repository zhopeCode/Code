#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Bubble_Sort(int arr[], int sz)
{
	int i, j;
	for (i = 0; i < sz - 1; i++)//多少趟，趟数比个数少一
	{
		int flag = 0;//优化
		for (j = 0; j < sz - 1 - i; j++)//每趟多少次，次数随着趟数增加而减少
		{
			if (arr[j] > arr[j + 1])//交换
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if(flag == 0)//判断这一趟下来有没有进行过交换，如果没有说明排序完毕
		{
			break;
		}
	}
}

int main()
{
	int n = 0;
	int arr[] = { 1, 9, 3, 8, 5, 7, 4, 2, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (n = 0; n < sz; n++)//打印未冒泡排序的顺序
	{
		printf("%d ", arr[n]);
	}
	putchar('\n');
	Bubble_Sort(arr, sz);
	for (n = 0; n < sz; n++)//打印已冒泡排序的顺序
	{
		printf("%d ", arr[n]);
	}
	putchar('\n');
	return 0;
}
