#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X1 9//������
#define Y1 9//������

#define X2 X1 + 2
#define Y2 Y1 + 2

#define setMine 10 //�׵ĸ���

void menu();//��ӡ�˵�

void game();//��Ϸ����

void init_board(char board[X2][Y2], int x2, int y2, char set);//��ʼ������

void display_board(char board[X2][Y2], int x1, int y1);//��ӡ����

void set_mine(char mine[X2][Y2], int x1, int y1);//������

void find_mine(char mine[X2][Y2], char show[X2][Y2], int x1, int y1);//�Ų���