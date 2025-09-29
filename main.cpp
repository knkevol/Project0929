#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int PlayerX = 1;
int PlayerY = 1;
int MonsterX = 8;
int MonsterY = 8;
char PlayerShape = 'P';
char MonsterShape = 'M';
bool bIsPlaying = true;

int KeyCode = 0;

void Input(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int main()
{
	Input(PlayerX, PlayerY);
	cout << PlayerShape;

	Input(MonsterX, MonsterY);
	cout << MonsterShape;

	while (bIsPlaying)
	{
		KeyCode = _getch();


		if (KeyCode == 'w')
		{
			PlayerY--;
		}
		else if (KeyCode == 's')
		{
			PlayerY++;
		}
		else if (KeyCode == 'a')
		{
			PlayerX--;
		}
		else if (KeyCode == 'd')
		{
			PlayerX++;
		}
		else if (KeyCode == 'q')
		{
			bIsPlaying = false;
			break; 
		}
		system("cls");

		Input(PlayerX, PlayerY);
		cout << PlayerShape;

		Input(MonsterX, MonsterY);
		cout << MonsterShape;
	}
	return 0;
}