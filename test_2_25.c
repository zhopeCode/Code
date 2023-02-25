#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int line = 0;
	while (line < 30000)
	{
		printf("写代码：%d\n", line);
		line++;
	}
	if (line == 30000)
		printf("头发掉光光\n");
}