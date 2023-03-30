#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()//��ӡ�˵�
{
	printf("*************************\n");
	printf("********1.��ʼ��Ϸ*******\n");
	printf("********0.�˳���Ϸ*******\n");
	printf("*************************\n");
}

void game()
{
	char mine[X2][Y2] = { 0 };//��ʼ��
	char show[X2][Y2] = { 0 };//��ʼ��

	init_board(mine, X2, Y2, '0');//��ʼ������
	init_board(show, X2, Y2, '*');//��ʼ����ʾ��

	display_board(show, X1, Y1);//��ӡ��ʾ��

	set_mine(mine, X1, Y1);//������
	//display_board(mine, X1, Y1);

	find_mine(mine, show, X1, Y1);//�Ų���
}

void init_board(char board[X2][Y2], int x2, int y2, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < y2; i++)//��������
	{
		for (j = 0; j < x2; j++)
		{
			board[j][i] = set;//��ֵset�е��ַ�
		}
	}
}

void display_board(char board[X2][Y2], int x1, int y1)
{
	printf("-----ɨ����Ϸ-----\n");
	int i = 0;
	int j = 0;
	for (j = 0; j <= x1; j++)//��ӡ������
	{
		printf("%d ", j);
	}
	putchar('\n');
	for (i = 1; i <= y1; i++)
	{
		printf("%d ", i);//��ӡ������
		for (j = 1; j <= x1; j++)
		{
			printf("%c ", board[j][i]);
		}
		putchar('\n');
	}
	printf("-----ɨ����Ϸ-----\n");
}

void set_mine(char board[X2][Y2], int x1, int y1)
{
	int count = setMine;	
	while (count)
	{
		int i = rand() % y1 + 1;//������������������
		int j = rand() % x1 + 1;
		if (board[j][i] == '0')//��������������Ƿ��Ѿ�������
		{
			board[j][i] = '1';
			count--;
		}
	}
}

static int get_mine_count(char mine[X2][Y2], int x, int y)//ͳ��û��������Χ8���ж�����
{
	return
		mine[x][y - 1] +
		mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] - (8 * '0');//����char������-48��-'0'������int������
}

void find_mine(char mine[X2][Y2], char show[X2][Y2], int x1, int y1)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < X1 * Y1 - setMine)//��0��ʼ�Ų��������û������
	{												//û������=������ȥ�� 
		printf("��ѡ��:>");					//����3��û����	0 1 2 �Ų�����
		scanf("%d %d", &x, &y);
		if ((x < 1 || x > x1) || (y < 1 || y > y1))
		{
			printf("�������������ѡ��\n");//��������Ƿ���ȷ
			display_board(show, X1, Y1);
			continue;
		}
		if (mine[x][y] == '1')			//��������1������ 0����û��
		{
			printf("�ȵ����ˣ���Ϸ����!\n");
			display_board(mine, X1, Y1);
			break;
		}
		else
		{
			int ret = get_mine_count(mine, x, y);
			show[x][y] = (ret + '0');
			display_board(show, X1, Y1);
			win++;// 2 ��������� ����3 
		}
	}
	if (win == X1 * Y1 - setMine)// ��ִ��while ����if�ж� win = 3 = û������
	{											//��Ϸʤ��
		printf("��ϲ�㣡���׳ɹ���\n");
		display_board(mine, X1, Y1);
	}
}