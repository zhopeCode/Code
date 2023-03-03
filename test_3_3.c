#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//现在还只能检测最高7位纯数字
//等以后技术上去了再改改
int main()
{
	long long password1;
	long long password2;
	printf("请输入密码:>");
	scanf("%s", &password1);
	printf("请再次输入密码:>");
	scanf("%s", &password2);
	if (password1 == password2)
		printf("确认密码成功");
	else
		printf("两次密码不一致");
}