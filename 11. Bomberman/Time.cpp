#include <iostream>
#include <conio.h>
#include <Windows.h>

#define BOMB_COUNT_MAX		5

#define BOMB_TIME			1.5f


using namespace std;

struct __tagPoint
{
	int x;
	int y;
};


struct __tagBomb
{
	__tagPoint	tPos;

	float		fAccTime = 0.f;
	float		fMaxTime = BOMB_TIME;
};

void SetMaze(char Maze[20][21], __tagPoint* pPlayerPos, __tagPoint* pStartPos, __tagPoint* pEndPos)
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

	strcpy_s(Maze[0], "20000100000010000011");
	strcpy_s(Maze[1], "10011111111111100110");
	strcpy_s(Maze[2], "10010000010000111100");
	strcpy_s(Maze[3], "11111111101110000000");
	strcpy_s(Maze[4], "00100000111001000111");
	strcpy_s(Maze[5], "01110000000001000100");
	strcpy_s(Maze[6], "00010000011111100100");
	strcpy_s(Maze[7], "11110011110000111100");
	strcpy_s(Maze[8], "00100110010010100000");
	strcpy_s(Maze[9], "00111100010010111000");
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

void Render(char Maze[20][21], __tagPoint* pPlayerPos)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (Maze[i][j] == '4')
				cout << "㉿";

			else if (pPlayerPos->x == j && pPlayerPos->y == i)
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

void MoveUp(char Maze[20][21], __tagPoint* pPlayerPos)
{
	// 배열 내부인지 아닌지
	if (pPlayerPos->y - 1 >= 0)
	{
		// 벽인지 체크
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0' &&
			Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4')
			--pPlayerPos->y;
	}
}

void MoveDown(char Maze[20][21], __tagPoint* pPlayerPos)
{
	// 배열 내부인지 아닌지
	if (pPlayerPos->y + 1 < 20)
	{
		// 벽인지 체크
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0' &&
			Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4')
			++pPlayerPos->y;
	}
}

void MoveLeft(char Maze[20][21], __tagPoint* pPlayerPos)
{
	// 배열 내부인지 아닌지
	if (pPlayerPos->x - 1 >= 0)
	{
		// 벽인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0' &&
			Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4')
			--pPlayerPos->x;
	}
}

void MoveRight(char Maze[20][21], __tagPoint* pPlayerPos)
{
	// 배열 내부인지 아닌지
	if (pPlayerPos->x + 1 < 20)
	{
		// 벽인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0' &&
			Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4')
			++pPlayerPos->x;
	}
}

void MovePlayer(char Maze[20][21], __tagPoint* pPlayerPos)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		MoveUp(Maze, pPlayerPos);
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		MoveDown(Maze, pPlayerPos);
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		MoveLeft(Maze, pPlayerPos);
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		MoveRight(Maze, pPlayerPos);
	}
}

void CreateBomb(char Maze[20][21], const __tagPoint* pPlayer, __tagBomb* pBombArr, int* pBombCount)
{
	if (*pBombCount == BOMB_COUNT_MAX)
		return;

	for (int i = 0; i < *pBombCount; i++)
	{
		if (pPlayer->x == pBombArr[i].tPos.x &&
			pPlayer->y == pBombArr[i].tPos.y)
			return;
	}

	pBombArr[*pBombCount].tPos = *pPlayer;

	++(*pBombCount);

	Maze[pPlayer->y][pPlayer->x] = '4';
}

void Fire(char Maze[20][21], __tagPoint* pPlayer, __tagBomb* pBombArr, int* pBombCount)
{
	for (int i = 0; i < *pBombCount; i++)
	{
		if (pPlayer->x == pBombArr[i].tPos.x && pPlayer->y == pBombArr[i].tPos.y)
		{
			pPlayer->x = 0;
			pPlayer->y = 0;
		}

		// 위
		if (pBombArr[i].tPos.y - 1 >= 0)
		{
			if (Maze[pBombArr[i].tPos.y - 1][pBombArr[i].tPos.x] == '0')
				Maze[pBombArr[i].tPos.y - 1][pBombArr[i].tPos.x] = '1';

			if (pPlayer->x == pBombArr[i].tPos.x && pPlayer->y == pBombArr[i].tPos.y - 1)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}

		// 아래
		if (pBombArr[i].tPos.y + 1 < 20)
		{
			if (Maze[pBombArr[i].tPos.y + 1][pBombArr[i].tPos.x] == '0')
				Maze[pBombArr[i].tPos.y + 1][pBombArr[i].tPos.x] = '1';

			if (pPlayer->x == pBombArr[i].tPos.x && pPlayer->y == pBombArr[i].tPos.y + 1)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}

		// 왼쪽
		if (pBombArr[i].tPos.x - 1 >= 0)
		{
			if (Maze[pBombArr[i].tPos.y][pBombArr[i].tPos.x - 1] == '0')
				Maze[pBombArr[i].tPos.y][pBombArr[i].tPos.x - 1] = '1';

			if (pPlayer->x == pBombArr[i].tPos.x - 1 && pPlayer->y == pBombArr[i].tPos.y)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}

		// 오른쪽
		if (pBombArr[i].tPos.x + 1 < 20)
		{
			if (Maze[pBombArr[i].tPos.y][pBombArr[i].tPos.x + 1] == '0')
				Maze[pBombArr[i].tPos.y][pBombArr[i].tPos.x + 1] = '1';

			if (pPlayer->x == pBombArr[i].tPos.x + 1 && pPlayer->y == pBombArr[i].tPos.y)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}

		Maze[pBombArr[i].tPos.y][pBombArr[i].tPos.x] = '1';
	}

	*pBombCount = 0;
}

void EachFire(char Maze[20][21], __tagPoint* pPlayer, __tagBomb* pBomb, int* pBombCount)
{
	pBomb->fAccTime = 0.f;
	Maze[pBomb->tPos.y][pBomb->tPos.x] = '1';


	if (pPlayer->x == pBomb->tPos.x && pPlayer->y == pBomb->tPos.y)
	{
		pPlayer->x = 0;
		pPlayer->y = 0;
	}

	// 위
	if (pBomb->tPos.y - 1 >= 0)
	{
		if (Maze[pBomb->tPos.y - 1][pBomb->tPos.x] == '0')
			Maze[pBomb->tPos.y - 1][pBomb->tPos.x] = '1';

		if (pPlayer->x == pBomb->tPos.x && pPlayer->y == pBomb->tPos.y - 1)
		{
			pPlayer->x = 0;
			pPlayer->y = 0;
		}
	}

	// 아래
	if (pBomb->tPos.y + 1 < 20)
	{
		if (Maze[pBomb->tPos.y + 1][pBomb->tPos.x] == '0')
			Maze[pBomb->tPos.y + 1][pBomb->tPos.x] = '1';

		if (pPlayer->x == pBomb->tPos.x && pPlayer->y == pBomb->tPos.y + 1)
		{
			pPlayer->x = 0;
			pPlayer->y = 0;
		}
	}

	// 왼쪽
	if (pBomb->tPos.x - 1 >= 0)
	{
		if (Maze[pBomb->tPos.y][pBomb->tPos.x - 1] == '0')
			Maze[pBomb->tPos.y][pBomb->tPos.x - 1] = '1';

		if (pPlayer->x == pBomb->tPos.x - 1 && pPlayer->y == pBomb->tPos.y)
		{
			pPlayer->x = 0;
			pPlayer->y = 0;
		}
	}

	// 오른쪽
	if (pBomb->tPos.x + 1 < 20)
	{
		if (Maze[pBomb->tPos.y][pBomb->tPos.x + 1] == '0')
			Maze[pBomb->tPos.y][pBomb->tPos.x + 1] = '1';

		if (pPlayer->x == pBomb->tPos.x + 1 && pPlayer->y == pBomb->tPos.y)
		{
			pPlayer->x = 0;
			pPlayer->y = 0;
		}
	}
}

void AccTime(__tagBomb* pBombArr, const int* pBombCount)
{
	for (int i = 0; i < *pBombCount; i++)
	{
		pBombArr[i].fAccTime += 0.1f;
	}
}


void SetTimer(char Maze[20][21], __tagPoint* pPlayer, __tagBomb* pBombArr, int* pBombCount)
{
	for (int i = 0; i < *pBombCount; i++)
	{
		if (pBombArr[i].fMaxTime <= pBombArr[i].fAccTime)
		{
			Maze[pBombArr[i].tPos.y][pBombArr[i].tPos.y] = '1';
			EachFire(Maze, pPlayer, &pBombArr[i], pBombCount);
			--*pBombCount;
		}
	}

}

int main()
{
	char strMaze[20][21] = {};

	__tagPoint	tPlayerPos;
	__tagPoint	tStartPos;
	__tagPoint	tEndPos;

	int		iBombCount = 0;
	__tagBomb	tBombPos[BOMB_COUNT_MAX];

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

		cout << "P : 설치 \t O : 폭발\t 소유한 폭탄 : " << BOMB_COUNT_MAX - iBombCount << endl;
		cout << "W : ↑\tS : ↓\tA : ←\tD : →\tQ : Exit" << endl;

		AccTime(tBombPos, &iBombCount);
		SetTimer(strMaze, &tPlayerPos, tBombPos, &iBombCount);

//		char cInput = _getch();

		Sleep(50);

		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		}

		else
			MovePlayer(strMaze, &tPlayerPos);
	}

	return 0;
}