#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int my_strlen(char* a)//模拟实现strlen
{
	int count = 0;
	while (*a != '\0')
	{
		count++;
		a ++;
	}
	return count;
}

void reverse_string(char* string)//实现字符逆序的函数
{
	char tmp;//存储字符串首个字符的变量
	int len = my_strlen(string);//计算字符串长度
	tmp = *string;//将首字符赋值给tmp
	*string = *(string + len - 1);//将首字符更改成尾字符
	*(string + len - 1) = '\0';//将尾字符替换成'\0'
	if (my_strlen(string + 1) > 1)//判断字符串是否继续执行逆序操作
	{
		reverse_string(string + 1);//递归
	}
	*(string + len - 1) = tmp;//将首字符赋值给尾字符
}

int main()
{
	char arr[] = "abcdefg";
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}
