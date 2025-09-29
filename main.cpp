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

	if (PlayerX == x && PlayerY == y)
	{
		cout << PlayerShape;
	}
	else if (MonsterX == x && MonsterY == y)
	{
		cout << MonsterShape;
	}
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

	return 0;
	
}

int main()
{
	//초기위치 설정
	Render(PlayerX, PlayerY);
	Render(MonsterX, MonsterY);

	while (bIsPlaying)
	{
		Input();
		Process();
		//현재 상태 업데이트
		Render(PlayerX, PlayerY);
		Render(MonsterX, MonsterY);
	}
	

	return 0;
}