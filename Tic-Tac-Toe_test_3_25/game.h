#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define userX 3
#define userY 3

void menu();

void game();

void init_board(char board[userX][userY], int X, int Y);

void display_board(char board[userX][userY], int X, int Y);

void player_move(char board[userX][userY], int X, int Y);

void bot_move(char board[userX][userY], int X, int Y);

char Who_win(char board[userX][userY], int X, int Y);

int Is_full(char board[userX][userY], int X, int Y);