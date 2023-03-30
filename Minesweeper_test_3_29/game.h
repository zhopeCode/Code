#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X1 9//雷区长
#define Y1 9//雷区宽

#define X2 X1 + 2
#define Y2 Y1 + 2

#define setMine 10 //雷的个数

void menu();//打印菜单

void game();//游戏函数

void init_board(char board[X2][Y2], int x2, int y2, char set);//初始化雷区

void display_board(char board[X2][Y2], int x1, int y1);//打印雷区

void set_mine(char mine[X2][Y2], int x1, int y1);//设置雷

void find_mine(char mine[X2][Y2], char show[X2][Y2], int x1, int y1);//排查雷