#include <iostream>
#include <conio.h>
#include <Windows.h>

#define PlayerPos 1
#define MonsterPos 8

using namespace std;

int PlayerX = PlayerPos;
int PlayerY = PlayerPos;
int MonsterX = MonsterPos;
int MonsterY = MonsterPos;
char PlayerShape = 'P';
char MonsterShape = 'M';
bool bIsPlaying = true;
int KeyCode = 0;

void Input()
{
	KeyCode = _getch();
}

void Render(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	if (PlayerX == x && PlayerY == y)
	{
		cout << PlayerShape;
	}
	else if (MonsterX == x && MonsterY == y)
	{
		cout << MonsterShape;
	}
}

void Process()
{
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
	}
	system("cls");
}

int main()
{
	do
	{
		Render(PlayerX, PlayerY);
		Render(MonsterX, MonsterY);
		Input();
		Process();
	} while (bIsPlaying);
	
	return 0;
}