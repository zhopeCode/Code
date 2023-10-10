#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//字符串倒序
void inversion(char* left, char* right)
{
 	char tmp = ' ';
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}	
}

//获取一个单词（找空格）
void get_word(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != ' ' && *end != '\0')
	{
		end++;
	}
	inversion(start, end - 1);
	start = end + 1;
	end = start;
}



int main()
{
	char str[100] = { "" };
	gets_s(str, 100);
	int len = strlen(str);
	inversion(str, str + (len - 1));
	get_word(str);
	puts(str);
	return 0;
}