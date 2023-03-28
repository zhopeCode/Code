#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//现在可以检测数字加字符
int main()
{
	char firstPassword[20];
	char secondPassword[20];
	printf("请输入密码:>");
	scanf("%s", firstPassword);
	printf("请再次输入密码:>");
	scanf("%s", secondPassword);
	if (strcmp(firstPassword, secondPassword) == 0)
	{
		printf("确认密码成功");
	}
	else
	{
		printf("两次密码不一致");
	}
}
