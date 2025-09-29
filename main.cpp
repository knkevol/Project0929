#include <iostream>
#include <conio.h>

using namespace std;

int Map[30][30] =	{{0,}};

int PlayerX = 1;
int PlayerY = 1;
int MonsterX = 8;
int MonsterY = 8;
char PlayerShape = 'P';
char MonsterShape = 'M';
bool bIsPlaying = true;


int KeyCode = 0;

bool Predict(int NewY, int NewX)
{
	if (NewY >= 0 && NewY < 30 && NewX >= 0 && NewX < 30)
	{
		if (Map[NewY][NewX] == 0)
		{
			return true;
		}
	}

	return false;
}

void Input()
{
	KeyCode = _getch();
}

void Process()
{
	int nextX = PlayerX;
	int nextY = PlayerY;

	if (KeyCode == 'w')
	{
		nextY--;
	}
	else if (KeyCode == 's')
	{
		nextY++;
	}
	else if (KeyCode == 'a')
	{
		nextX--;
	}
	else if (KeyCode == 'd')
	{
		nextX++;
	}
	else if (KeyCode == 'q')
	{
		bIsPlaying = false;
		return;
	}

	if (Predict(nextY, nextX))
	{
		PlayerX = nextX;
		PlayerY = nextY;
	}

}

void Render()
{
	system("cls");
	for (int Y = 0; Y < 30; Y++)
	{
		for (int X = 0; X < 30; X++)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				cout << PlayerShape;

			}
			else if (MonsterX == X && MonsterY == Y)
			{
				cout << MonsterShape;
			}
			else
			{
				cout << " ";

			}
		}
		cout << "\n";
	}
}

int main()
{
	while (bIsPlaying)
	{
		Input();
		Process();
		Render();
	}

	return 0;
}