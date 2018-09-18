#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>

enum { KB = 224, UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 };
const int BOARD_SIZE(25);


void gotoxy(COORD);

class snake
{
private:
	COORD pos;
public:
	snake()
	{
		pos = { 13,13 };
	};
//	int direction_input();
	int move();
	bool collision_check();
};