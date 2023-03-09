#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//现在可以检测数字加字符
int main()
{
	char password1[20];
	char password2[20];
	printf("请输入密码:>");
	scanf("%s", &password1);
	printf("请再次输入密码:>");
	scanf("%s", &password2);
	if (strcmp(password1, password2) == 0)
		printf("确认密码成功");
	else
		printf("两次密码不一致");
}
