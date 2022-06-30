#include <iostream>
#include <conio.h>

using namespace std;

struct __tagPoint
{
	int x;
	int y;
};

typedef __tagPoint	POINT;
typedef __tagPoint* PPOINT;


void SetMaze(char Maze[20][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;
	/*
		0 : Wall
		1 : Road
		2 : Start
		3 : End
	*/

	strcpy_s(Maze[0],  "20000100000010000011");
	strcpy_s(Maze[1],  "10011111111111100110");
	strcpy_s(Maze[2],  "10010000010000111100");
	strcpy_s(Maze[3],  "11111111101110000000");
	strcpy_s(Maze[4],  "00100000111001000111");
	strcpy_s(Maze[5],  "01110000000001000100");
	strcpy_s(Maze[6],  "00010000011111100100");
	strcpy_s(Maze[7],  "11110011110000111100");
	strcpy_s(Maze[8],  "00100110010010100000");
	strcpy_s(Maze[9],  "00111100010010111000");
	strcpy_s(Maze[10], "01100000010010001000");
	strcpy_s(Maze[11], "00000111110000001000");
	strcpy_s(Maze[12], "11100100000100001110");
	strcpy_s(Maze[13], "00111100000111000011");
	strcpy_s(Maze[14], "00000100011101011000");
	strcpy_s(Maze[15], "01111111110001111100");
	strcpy_s(Maze[16], "00010000010000000110");
	strcpy_s(Maze[17], "00011100011110000011");
	strcpy_s(Maze[18], "01110110000011111000");
	strcpy_s(Maze[19], "01000010000010001113");
}

void Render(char Maze[20][21], PPOINT pPlayerPos)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "♀";

			else if (Maze[i][j] == '0')
				cout << "■";

			else if (Maze[i][j] == '1')
				cout << "  ";

			else if (Maze[i][j] == '2')
				cout << "□";

			else if (Maze[i][j] == '3')
				cout << "★";
		}
		cout << endl;
	}
}

void MoveUp(char Maze[20][21], PPOINT pPlayerPos)
{
	// 배열 내부인지 아닌지
	if (pPlayerPos->y - 1 >= 0)
	{
		// 벽인지 체크
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0')
			--pPlayerPos->y;
	}
}

void MoveDown(char Maze[20][21], PPOINT pPlayerPos)
{
	// 배열 내부인지 아닌지
	if (pPlayerPos->y + 1 < 20)
	{
		// 벽인지 체크
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0')
			++pPlayerPos->y;
	}
}

void MoveLeft(char Maze[20][21], PPOINT pPlayerPos)
{
	// 배열 내부인지 아닌지
	if (pPlayerPos->x - 1 >= 0)
	{
		// 벽인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0')
			--pPlayerPos->x;
	}
}

void MoveRight(char Maze[20][21], PPOINT pPlayerPos)
{
	// 배열 내부인지 아닌지
	if (pPlayerPos->x + 1 < 20)
	{
		// 벽인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0')
			++pPlayerPos->x;
	}
}

void MovePlayer(char Maze[20][21], PPOINT pPlayerPos, char cInput)
{
	switch (cInput)
	{
	case 'W':
	case 'w':
		MoveUp(Maze, pPlayerPos);
		break;
	case 'S':
	case 's':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'A':
	case 'a':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'D':
	case 'd':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}

int main()
{
	char strMaze[20][21] = {};

	POINT	tPlayerPos;
	POINT	tStartPos;
	POINT	tEndPos;

	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		Render(strMaze, &tPlayerPos);

		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y)
		{
			cout << "도착하였습니다." << endl;
			break;
		}

		cout << endl << endl;
		cout << "W : ↑\tS : ↓\tA : ←\tD : →\tQ : Exit" << endl;

		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		MovePlayer(strMaze, &tPlayerPos, cInput);
	}
	
	return 0;
}