#include "snake.h"

const int COLL_BOARDSIZE(BOARD_SIZE - 2);
void gotoxy(COORD pox)
{
	COORD pos = { (pox.X + 1) * 2 , pox.Y + 2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

bool snake::collision_check()
{
	return (unsigned short)pos.X < COLL_BOARDSIZE&&(unsigned short)pos.Y < COLL_BOARDSIZE;
}

int snake::move()
{
	COORD bef = pos;
	int nSelect = 0;
	if (_kbhit) {
		nSelect = _getch();
		if (nSelect == KB) {
			nSelect = _getch();
			switch (nSelect)
			{
			case UP:
				pos.Y--;
				break;
			case DOWN:
				pos.Y++;
				break;
			case LEFT:
				pos.X--;
				break;
			case RIGHT:
				pos.X++;
				break;
			default:
				break;
			}
		}
	}

	if (collision_check())
	{
		gotoxy(bef);
		std::cout << "бр";
		gotoxy(pos);
		std::cout << "бс";
		return 1;
	}
	else
	{
		system("cls");
		std::cout << "Out Of Boundary" << std::endl;
		return 0;
	}
}

