#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;

const int MAX(25);
enum { KB = 224, UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 };

void gotoxy(COORD pox)
{
	COORD pos = { (pox.X + 1) * 2 , pox.Y + 2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	COORD pos = { 13,13 };
	string stone[7]={"¡à","¡á","¡ã","¡å","¢¸","¢º","¡Ü"};
	string board[MAX][MAX];
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			switch (i)
			{
			case 0:board[i][j] = stone[3]; break;
			case (MAX - 1):board[i][j] = stone[2]; break;
			default:
				switch (j)
				{
				case 0:board[i][j] = stone[5]; break;
				case (MAX - 1):board[i][j] = stone[4]; break;
				default:board[i][j] = stone[0]; break;
				}break;
			}
		}
	}
	cout.width(MAX);
	cout << "SNAKE" << endl;
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}
	cout << "\n";
	COORD bef;
	while (1)
	{
		bef = pos;
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
		gotoxy(bef);
		cout << stone[0];
		gotoxy(pos);
		cout << stone[1];
	}
	return 0;
}
