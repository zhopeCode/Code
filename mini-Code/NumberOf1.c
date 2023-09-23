#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int NumberOf1(int num)
{
	int count = 0;

	while (num)
	{
		num = num & (num - 1);
		count++;
	}

	return count;
}

int main()
{
	int num = 14;
	printf("%d\n", NumberOf1(num));

	return 0;
}
