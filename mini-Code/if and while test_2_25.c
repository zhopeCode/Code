#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int userLine = 0;
	while (userLine < 30000)
	{
		printf("写代码%d\n", userLine);
		userLine++;
	}
	if (userLine == 30000)
	{
		printf("头发掉光光\n");
	}
}
