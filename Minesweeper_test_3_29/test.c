#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main()
{
	srand((unsigned int)time(NULL));//ʵ���׵����
	int input = 0;//��Ҳ˵�ѡ��
	do
	{
		menu();
		printf("��ѡ��(1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}