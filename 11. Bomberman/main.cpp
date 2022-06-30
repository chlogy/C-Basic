#include <iostream>
#include <conio.h>

#define BOMB_COUNT_MAX		5
#define BOMBPOWER_MAX		5

using namespace std;

enum MAZE_BLOCK_TYPE
{
	MBT_WALL = '0',
	MBT_ROAD = '1',
	MBT_START = '2',
	MBT_END = '3',
	MBT_BOMB = '4',
	MBT_POWER = '5',
	MBT_PUSH = '6',
	MBT_TRANSPARENCY = '7'
};

struct __tagPoint
{
	int x;
	int y;
};

typedef __tagPoint	POINT;
typedef __tagPoint* PPOINT;

typedef struct __tagPlayer
{
	__tagPoint	tPos;
	bool		bWallPush;
	bool		bPushOnOff;
	bool		bTransparency;
	int			iBombPower;
}PLAYER, *PPLAYER;

void SetMaze(char _Maze[20][21], PPLAYER _pPlayer, PPOINT _pStartPos, PPOINT _pEndPos)
{
	_pStartPos->x = 0;
	_pStartPos->y = 0;
	
	_pEndPos->x = 19;
	_pEndPos->y = 19;

	_pPlayer->tPos = *_pStartPos;

	/*
		0 : Wall
		1 : Road
		2 : Start
		3 : End
		4 : Bomb
		5 : Power Item
		6 : Push Wall
		7 : Transparency
	*/

	strcpy_s(_Maze[0], "20000100000010000011");
	strcpy_s(_Maze[1], "10011111111111100110");
	strcpy_s(_Maze[2], "10010000010000111100");
	strcpy_s(_Maze[3], "11111111101110000000");
	strcpy_s(_Maze[4], "00100000111001000111");
	strcpy_s(_Maze[5], "01110000000001000100");
	strcpy_s(_Maze[6], "00010000011111100100");
	strcpy_s(_Maze[7], "11110011110000111100");
	strcpy_s(_Maze[8], "00100110010010100000");
	strcpy_s(_Maze[9], "00111100010010111000");
	strcpy_s(_Maze[10], "01100000010010001000");
	strcpy_s(_Maze[11], "00000111110000001000");
	strcpy_s(_Maze[12], "11100100000100001110");
	strcpy_s(_Maze[13], "00111100000111000011");
	strcpy_s(_Maze[14], "00000100011101011000");
	strcpy_s(_Maze[15], "01111111110001111100");
	strcpy_s(_Maze[16], "00010000010000000110");
	strcpy_s(_Maze[17], "00011100011110000011");
	strcpy_s(_Maze[18], "01110110000011111000");
	strcpy_s(_Maze[19], "01000010000010001113");
}

void Render(char _Maze[20][21], PPLAYER _pPlayer)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (_Maze[i][j] == MBT_BOMB)
				cout << "㉿";

			else if (_pPlayer->tPos.x == j && _pPlayer->tPos.y == i)
				cout << "♀";

			else if (_Maze[i][j] == MBT_WALL)
				cout << "■";

			else if (_Maze[i][j] == MBT_ROAD)
				cout << "  ";

			else if (_Maze[i][j] == MBT_START)
				cout << "□";

			else if (_Maze[i][j] == MBT_END)
				cout << "★";

			else if (_Maze[i][j] == MBT_POWER)
				cout << "파";

			else if (_Maze[i][j] == MBT_TRANSPARENCY)
				cout << "투";

			else if (_Maze[i][j] == MBT_PUSH)
				cout << "밀";

		}
		cout << endl;
	}

	cout << "Bomb Power : " << _pPlayer->iBombPower << endl;
	
	cout << "Transparent : ";

	if (_pPlayer->bTransparency)
		cout << "ON\t";
	else
		cout << "OFF\t";

	cout << "Push Wall : ";
	
	if (_pPlayer->bWallPush)
	{
		cout << "가능 / ";

		if (_pPlayer->bPushOnOff)
			cout << "ON";
		else
			cout << "OFF";
	}
	else
		cout << "불가능 / OFF";

	cout << endl;
}

bool AddItem(char _cItemType, PPLAYER _pPlayer)
{
	if (_cItemType == MBT_POWER)
	{
		if (_pPlayer->iBombPower < BOMBPOWER_MAX)
			++_pPlayer->iBombPower;

		return true;
	}
	else if (_cItemType == MBT_PUSH)
	{
		_pPlayer->bWallPush = true;
		_pPlayer->bPushOnOff = true;
		return true;
	}
	else if (_cItemType == MBT_TRANSPARENCY)
	{
		_pPlayer->bTransparency = true;
		return true;
	}

	return false;
}

void MoveUp(char _Maze[20][21], PPLAYER _pPlayer)
{
	// 배열 내부인지 아닌지
	if (_pPlayer->tPos.y - 1 >= 0)
	{
		// 벽인지 체크
		if (_Maze[_pPlayer->tPos.y - 1][_pPlayer->tPos.x] != MBT_WALL &&
			_Maze[_pPlayer->tPos.y - 1][_pPlayer->tPos.x] != MBT_BOMB)
			--_pPlayer->tPos.y;

		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우
		else if (_pPlayer->bWallPush && _Maze[_pPlayer->tPos.y - 1][_pPlayer->tPos.x] == MBT_WALL)
		{
			// 벽 밀기가 ON 상태일 경우
			if (_pPlayer->bPushOnOff)
			{
				// 위의 윗 칸이 0보다 크거 같은경우는 인덱스가 존재한다.
				if (_pPlayer->tPos.y - 2 >= 0)
				{
					// 위의 위칸이 길이어야 밀기가 가능하다 그러므로 길인지 체크
					if (_Maze[_pPlayer->tPos.y - 2][_pPlayer->tPos.x] == MBT_WALL)
					{
						if (_pPlayer->bTransparency)
							--_pPlayer->tPos.y;
					}
					else if (_Maze[_pPlayer->tPos.y - 2][_pPlayer->tPos.x] == MBT_ROAD)
					{
						_Maze[_pPlayer->tPos.y - 2][_pPlayer->tPos.x] = MBT_WALL;
						_Maze[_pPlayer->tPos.y - 1][_pPlayer->tPos.x] = MBT_ROAD;

						--_pPlayer->tPos.y;
					}
				}
				else if (_pPlayer->bTransparency)
					--_pPlayer->tPos.y;
			}
			else if (_pPlayer->bTransparency)
				--_pPlayer->tPos.y;
		}

		else if (_pPlayer->bTransparency)
			--_pPlayer->tPos.y;

		if (AddItem(_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x], _pPlayer))
			_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x] = MBT_ROAD;
	}
}

void MoveDown(char _Maze[20][21], PPLAYER _pPlayer)
{
	// 배열 내부인지 아닌지
	if (_pPlayer->tPos.y + 1 < 20)
	{
		// 벽인지 체크
		if (_Maze[_pPlayer->tPos.y + 1][_pPlayer->tPos.x] != MBT_WALL &&
			_Maze[_pPlayer->tPos.y + 1][_pPlayer->tPos.x] != MBT_BOMB)
			++_pPlayer->tPos.y;

		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우
		else if (_pPlayer->bWallPush && _Maze[_pPlayer->tPos.y + 1][_pPlayer->tPos.x] == MBT_WALL)
		{
			// 벽 밀기가 ON 상태일 경우
			if (_pPlayer->bPushOnOff)
			{
				// 위의 윗 칸이 0보다 크거 같은경우는 인덱스가 존재한다.
				if (_pPlayer->tPos.y + 2 < 20)
				{
					// 위의 위칸이 길이어야 밀기가 가능하다 그러므로 길인지 체크
					if (_Maze[_pPlayer->tPos.y + 2][_pPlayer->tPos.x] == MBT_WALL)
					{
						if (_pPlayer->bTransparency)
							++_pPlayer->tPos.y;
					}
					else if (_Maze[_pPlayer->tPos.y + 2][_pPlayer->tPos.x] == MBT_ROAD)
					{
						_Maze[_pPlayer->tPos.y + 2][_pPlayer->tPos.x] = MBT_WALL;
						_Maze[_pPlayer->tPos.y + 1][_pPlayer->tPos.x] = MBT_ROAD;

						++_pPlayer->tPos.y;
					}
				}
				else if (_pPlayer->bTransparency)
					++_pPlayer->tPos.y;
			}
			else if (_pPlayer->bTransparency)
				++_pPlayer->tPos.y;
		}

		else if (_pPlayer->bTransparency)
			++_pPlayer->tPos.y;

		if (AddItem(_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x], _pPlayer))
			_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x] = MBT_ROAD;
	}
}

void MoveLeft(char _Maze[20][21], PPLAYER _pPlayer)
{
	// 배열 내부인지 아닌지
	if (_pPlayer->tPos.x - 1 >= 0)
	{
		// 벽인지 체크
		if (_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x - 1] != MBT_WALL &&
			_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x - 1] != MBT_BOMB)
			--_pPlayer->tPos.x;
		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우
		else if (_pPlayer->bWallPush && _Maze[_pPlayer->tPos.y][_pPlayer->tPos.x - 1] == MBT_WALL)
		{
			// 벽 밀기가 ON 상태일 경우
			if (_pPlayer->bPushOnOff)
			{
				// 위의 윗 칸이 0보다 크거 같은경우는 인덱스가 존재한다.
				if (_pPlayer->tPos.x - 2 >= 0)
				{
					// 위의 위칸이 길이어야 밀기가 가능하다 그러므로 길인지 체크
					if (_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x - 2] == MBT_WALL)
					{
						if (_pPlayer->bTransparency)
							--_pPlayer->tPos.x;
					}
					else if (_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x - 2] == MBT_ROAD)
					{
						_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x - 2] = MBT_WALL;
						_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x - 1] = MBT_ROAD;

						--_pPlayer->tPos.x;
					}
				}
				else if (_pPlayer->bTransparency)
					--_pPlayer->tPos.x;
			}
			else if (_pPlayer->bTransparency)
				--_pPlayer->tPos.x;
		}
		else if (_pPlayer->bTransparency)
			--_pPlayer->tPos.x;

		if (AddItem(_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x], _pPlayer))
			_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x] = MBT_ROAD;
	}
}

void MoveRight(char _Maze[20][21], PPLAYER _pPlayer)
{
	// 배열 내부인지 아닌지
	if (_pPlayer->tPos.x + 1 < 20)
	{
		// 벽인지 체크
		if (_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x + 1] != MBT_WALL &&
			_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x + 1] != MBT_BOMB)
			++_pPlayer->tPos.x;
		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우
		else if (_pPlayer->bWallPush && _Maze[_pPlayer->tPos.y][_pPlayer->tPos.x + 1] == MBT_WALL)
		{
			// 벽 밀기가 ON 상태일 경우
			if (_pPlayer->bPushOnOff)
			{
				// 위의 윗 칸이 0보다 크거 같은경우는 인덱스가 존재한다.
				if (_pPlayer->tPos.x + 1 < 20)
				{
					// 위의 위칸이 길이어야 밀기가 가능하다 그러므로 길인지 체크
					if (_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x + 2] == MBT_WALL)
					{
						if (_pPlayer->bTransparency)
							++_pPlayer->tPos.x;
					}
					else if (_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x + 2] == MBT_ROAD)
					{
						_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x + 2] = MBT_WALL;
						_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x + 1] = MBT_ROAD;

						++_pPlayer->tPos.x;
					}
				}
				else if (_pPlayer->bTransparency)
					++_pPlayer->tPos.x;
			}
			else if (_pPlayer->bTransparency)
				++_pPlayer->tPos.x;
		}
		else if (_pPlayer->bTransparency)
			++_pPlayer->tPos.x;

		if (AddItem(_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x], _pPlayer))
			_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x] = MBT_ROAD;
	}
}

void MovePlayer(char _Maze[20][21], PPLAYER _pPlayer, char _cInput)
{
	switch (_cInput)
	{
	case 'W':
	case 'w':
		MoveUp(_Maze, _pPlayer);
		break;
	case 'S':
	case 's':
		MoveDown(_Maze, _pPlayer);
		break;
	case 'A':
	case 'a':
		MoveLeft(_Maze, _pPlayer);
		break;
	case 'D':
	case 'd':
		MoveRight(_Maze, _pPlayer);
		break;
	}
}

void CreateBomb(char _Maze[20][21], const PPLAYER _pPlayer, PPOINT _pBombArr, int* _pBombCount)
{
	if (*_pBombCount == BOMB_COUNT_MAX)
		return;

	else if (_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x] == MBT_WALL)
		return;

	for (int i = 0; i < *_pBombCount; i++)
	{
		if (_pPlayer->tPos.x == _pBombArr[i].x &&
			_pPlayer->tPos.y == _pBombArr[i].y)
			return;
	}

	_pBombArr[*_pBombCount] = _pPlayer->tPos;
	++(*_pBombCount);

	_Maze[_pPlayer->tPos.y][_pPlayer->tPos.x] = MBT_BOMB;
}

void Fire(char _Maze[20][21], PPLAYER _pPlayer, PPOINT _pBombArr, int* _pBombCount)
{
	for (int i = 0; i < *_pBombCount; i++)
	{
		if (_pPlayer->tPos.x == _pBombArr[i].x && _pPlayer->tPos.y == _pBombArr[i].y)
		{
			_pPlayer->tPos.x = 0;
			_pPlayer->tPos.y = 0;
		}

		for (int j = 1; j <= _pPlayer->iBombPower; j++)
		{
			// 위
			if (_pBombArr[i].y - j >= 0)
			{
				if (_Maze[_pBombArr[i].y - j][_pBombArr[i].x] == MBT_WALL)
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;

						if (iPercent < 70)
							_Maze[_pBombArr[i].y - j][_pBombArr[i].x] = MBT_POWER;

						else if (iPercent < 80)
							_Maze[_pBombArr[i].y - j][_pBombArr[i].x] = MBT_PUSH;

						else
							_Maze[_pBombArr[i].y - j][_pBombArr[i].x] = MBT_TRANSPARENCY;
					}
					else
						_Maze[_pBombArr[i].y - j][_pBombArr[i].x] = MBT_ROAD;
				}

				if (_pPlayer->tPos.x == _pBombArr[i].x && _pPlayer->tPos.y == _pBombArr[i].y - j)
				{
					_pPlayer->tPos.x = 0;
					_pPlayer->tPos.y = 0;
				}
			}

			// 아래
			if (_pBombArr[i].y + j < 20)
			{
				if (_Maze[_pBombArr[i].y + j][_pBombArr[i].x] == MBT_WALL)
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;

						if (iPercent < 70)
							_Maze[_pBombArr[i].y + j][_pBombArr[i].x] = MBT_POWER;

						else if (iPercent < 80)
							_Maze[_pBombArr[i].y + j][_pBombArr[i].x] = MBT_PUSH;

						else
							_Maze[_pBombArr[i].y + j][_pBombArr[i].x] = MBT_TRANSPARENCY;
					}
					else
						_Maze[_pBombArr[i].y + j][_pBombArr[i].x] = MBT_ROAD;
				}

				if (_pPlayer->tPos.x == _pBombArr[i].x && _pPlayer->tPos.y == _pBombArr[i].y + j)
				{
					_pPlayer->tPos.x = 0;
					_pPlayer->tPos.y = 0;
				}
			}

			// 왼쪽
			if (_pBombArr[i].x - j >= 0)
			{
				if (_Maze[_pBombArr[i].y][_pBombArr[i].x - j] == MBT_WALL)
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;

						if (iPercent < 70)
							_Maze[_pBombArr[i].y][_pBombArr[i].x - j] = MBT_POWER;

						else if (iPercent < 80)
							_Maze[_pBombArr[i].y][_pBombArr[i].x - j] = MBT_PUSH;

						else
							_Maze[_pBombArr[i].y][_pBombArr[i].x - j] = MBT_TRANSPARENCY;
					}
					else
						_Maze[_pBombArr[i].y][_pBombArr[i].x - j] = MBT_ROAD;
				}

				if (_pPlayer->tPos.x == _pBombArr[i].x - j && _pPlayer->tPos.y == _pBombArr[i].y)
				{
					_pPlayer->tPos.x = 0;
					_pPlayer->tPos.y = 0;
				}
			}

			// 오른쪽
			if (_pBombArr[i].x + j < 20)
			{
				if (_Maze[_pBombArr[i].y][_pBombArr[i].x + j] == MBT_WALL)
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;

						if (iPercent < 70)
							_Maze[_pBombArr[i].y][_pBombArr[i].x + j] = MBT_POWER;

						else if (iPercent < 80)
							_Maze[_pBombArr[i].y][_pBombArr[i].x + j] = MBT_PUSH;

						else
							_Maze[_pBombArr[i].y][_pBombArr[i].x + j] = MBT_TRANSPARENCY;
					}
					else
						_Maze[_pBombArr[i].y][_pBombArr[i].x + j] = MBT_ROAD;
				}

				if (_pPlayer->tPos.x == _pBombArr[i].x + j && _pPlayer->tPos.y == _pBombArr[i].y)
				{
					_pPlayer->tPos.x = 0;
					_pPlayer->tPos.y = 0;
				}
			}
		}
		

		_Maze[_pBombArr[i].y][_pBombArr[i].x] = '1';
	}

	*_pBombCount = 0;
}

int main()
{
	srand(time(NULL));

	char strMaze[20][21] = {};

	PLAYER	tPlayer = {};
	tPlayer.iBombPower = 1;

	POINT	tStartPos;
	POINT	tEndPos;

	int		iBombCount = 0;
	POINT	tBombPos[BOMB_COUNT_MAX];

	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		Render(strMaze, &tPlayer);

		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y)
		{
			cout << "도착하였습니다." << endl;
			break;
		}

		cout << endl << endl;

		cout << "P : 설치 \t O : 폭발\t I : Push ON/OFF" << endl;
		cout << "소유한 폭탄 : " << BOMB_COUNT_MAX - iBombCount << endl;
		cout << "W : ↑\tS : ↓\tA : ←\tD : →\tQ : Exit" << endl;

		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		else if (cInput == 'p' || cInput == 'P')
		{
			CreateBomb(strMaze, &tPlayer, tBombPos, &iBombCount);
		}
		else if (cInput == 'o' || cInput == 'O')
		{
			Fire(strMaze, &tPlayer, tBombPos, &iBombCount);
		}
		else if (cInput == 'i' || cInput == 'I')
		{
			if (tPlayer.bWallPush)
				tPlayer.bPushOnOff = !tPlayer.bPushOnOff;
		}
		else
			MovePlayer(strMaze, &tPlayer, cInput);
	}

	return 0;
}