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

int Input()
{
	KeyCode = _getch();

	return 0;
}

void Render(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int Process()
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

	Render(PlayerX, PlayerY);
	cout << PlayerShape;
	Render(MonsterX, MonsterY);
	cout << MonsterShape;

	return 0;
	
}

int main()
{
	//초기값
	Render(PlayerX, PlayerY);
	cout << PlayerShape;
	Render(MonsterX, MonsterY);
	cout << MonsterShape;

	while (bIsPlaying)
	{
		Input();
		Process();
	}
	

	return 0;
}