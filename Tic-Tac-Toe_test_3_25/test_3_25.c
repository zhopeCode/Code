#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main()
{
	int input = 0;
	do
	{
		srand((unsigned int)time(NULL));//���ֵ
		menu();										//��ӡ�˵�
		printf("��ѡ��:>\n");
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
			printf("�����������������\n");
		}
	} while (input);	
	return 0;
}