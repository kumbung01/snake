#include "snake.h"
using namespace std;


int main()
{
	snake s;
	enum { EMP, FUL, ADD };
	cout.width(BOARD_SIZE);
	cout << "SNAKE" << endl;
	for (int col = 0; col < BOARD_SIZE; ++col)
	{
		cout << "¡å";
	}
	cout << "\n";
	for (int row = 0; row < BOARD_SIZE-2; ++row)
	{
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			switch (col)
			{
			case 0: cout << "¢º"; break;
			case BOARD_SIZE-1:cout << "¢¸"; break;
			default:cout << "¡à"; break;
			}
		}
		cout << "\n";
	}
	for (int col = 0; col < BOARD_SIZE; ++col)
	{
		cout << "¡ã";
	}
	cout << "\n";

	while (int check = 1)
	{
		check = s.move();
	}
	std::cout << "finished!" << endl;
	getchar();
	return 0;
}
