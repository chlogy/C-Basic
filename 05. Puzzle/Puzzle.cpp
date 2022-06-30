#include <iostream>
#include <conio.h>

using namespace std;

enum PUZZLE_DIRECTION
{
	PD_UP,
	PD_DOWN,
	PD_LEFT,
	PD_RIGHT
};

int main()
{
	srand((unsigned int)time(NULL));

	int iNumber[25] = {};

	for (int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}

	int iBlankIndex = 24;
	iNumber[iBlankIndex] = INT_MAX;

	int iMoveCount = 0;

	int iShuffleCount = 0;
	int iShuffleDecide;
	cout << "������ Ƚ���� �Է����ּ��� : ";
	cin >> iShuffleDecide;

	for (int i = 0; i < iShuffleDecide; i++)
	{
		int iDir = rand() % 4;

		switch (iDir)
		{
		case PD_UP:
			if (iBlankIndex > 4)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex - 5];
				iNumber[iBlankIndex - 5] = INT_MAX;
				iBlankIndex -= 5;
			}
			break;
		case PD_DOWN:
			if (iBlankIndex < 20)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex + 5];
				iNumber[iBlankIndex + 5] = INT_MAX;
				iBlankIndex += 5;
			}
			break;
		case PD_LEFT:
			if (iBlankIndex % 5 != 0)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex - 1];
				iNumber[iBlankIndex - 1] = INT_MAX;
				iBlankIndex--;
			}
			break;
		case PD_RIGHT:
			if (iBlankIndex % 5 != 4)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex + 1];
				iNumber[iBlankIndex + 1] = INT_MAX;
				iBlankIndex++;
			}
			break;
		}

		system("cls");

		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (iNumber[j * 5 + k] == INT_MAX)
					cout << " \t";
				else
					cout << iNumber[j * 5 + k] << "\t";
			}
			cout << endl << endl << endl;
		}

		cout << endl;
		cout << iShuffleCount << "ȸ Shuffle" << endl;
		iShuffleCount++;
	}

	for (int i = 0; i < 4; i++)
	{
		if (iBlankIndex < 20)
		{
			iNumber[iBlankIndex] = iNumber[iBlankIndex + 5];
			iNumber[iBlankIndex + 5] = INT_MAX;
			iBlankIndex += 5;
		}

		if (iBlankIndex % 5 != 4)
		{
			iNumber[iBlankIndex] = iNumber[iBlankIndex + 1];
			iNumber[iBlankIndex + 1] = INT_MAX;
			iBlankIndex++;
		}
	}


	while (true)
	{
		system("cls");

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << " \t";
				else
					cout << iNumber[i * 5 + j] << "\t";			// �ٹ�ȣ * ���ΰ��� + ĭ��ȣ
			}
			cout << endl << endl << endl;
		}

		bool bClear = true;
		for (int i = 0; i < 24; i++)
		{
			if (iNumber[i] != i + 1)
			{
				bClear = false;
				break;
			}
		}

		if (bClear == true)
		{
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}

		cout << endl;

		cout << "Move Count : " << iMoveCount << endl << endl;

		cout << "W : ��" << "\t";
		cout << "S : ��" << "\t";
		cout << "A : ��" << "\t";
		cout << "D : ��" << "\t";
		cout << "R : Reset" << "\t";
		cout << "Q : Exit" << endl << endl;

		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		switch (cInput)
		{
		case 'W':
		case 'w':
			if (iBlankIndex > 4)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex - 5];
				iNumber[iBlankIndex - 5] = INT_MAX;
				iBlankIndex -= 5;
				iMoveCount++;
			}
			break;
		case 'S':
		case 's':
			if (iBlankIndex < 20)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex + 5];
				iNumber[iBlankIndex + 5] = INT_MAX;
				iBlankIndex += 5;
				iMoveCount++;
			}
			break;
		case 'A':
		case 'a':
			if (iBlankIndex % 5 != 0)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex - 1];
				iNumber[iBlankIndex - 1] = INT_MAX;
				iBlankIndex--;
				iMoveCount++;
			}
			break;
		case 'D':
		case 'd':
			if (iBlankIndex % 5 != 4)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex + 1];
				iNumber[iBlankIndex + 1] = INT_MAX;
				iBlankIndex++;
				iMoveCount++;
			}
			break;

		case 'R':
		case 'r':
			iShuffleCount = 0;
			iMoveCount = 0;
			cout << "������ Ƚ���� �Է����ּ��� : ";
			cin >> iShuffleDecide;

			for (int i = 0; i < iShuffleDecide; i++)
			{
				int iDir = rand() % 4;

				switch (iDir)
				{
				case PD_UP:
					if (iBlankIndex > 4)
					{
						iNumber[iBlankIndex] = iNumber[iBlankIndex - 5];
						iNumber[iBlankIndex - 5] = INT_MAX;
						iBlankIndex -= 5;
					}
					break;
				case PD_DOWN:
					if (iBlankIndex < 20)
					{
						iNumber[iBlankIndex] = iNumber[iBlankIndex + 5];
						iNumber[iBlankIndex + 5] = INT_MAX;
						iBlankIndex += 5;
					}
					break;
				case PD_LEFT:
					if (iBlankIndex % 5 != 0)
					{
						iNumber[iBlankIndex] = iNumber[iBlankIndex - 1];
						iNumber[iBlankIndex - 1] = INT_MAX;
						iBlankIndex--;
					}
					break;
				case PD_RIGHT:
					if (iBlankIndex % 5 != 4)
					{
						iNumber[iBlankIndex] = iNumber[iBlankIndex + 1];
						iNumber[iBlankIndex + 1] = INT_MAX;
						iBlankIndex++;
					}
					break;
				}

				system("cls");

				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						if (iNumber[j * 5 + k] == INT_MAX)
							cout << " \t";
						else
							cout << iNumber[j * 5 + k] << "\t";
					}
					cout << endl << endl << endl;
				}

				cout << endl;
				cout << iShuffleCount << "ȸ Shuffle" << endl;
				iShuffleCount++;
			}

			for (int i = 0; i < 4; i++)
			{
				if (iBlankIndex < 20)
				{
					iNumber[iBlankIndex] = iNumber[iBlankIndex + 5];
					iNumber[iBlankIndex + 5] = INT_MAX;
					iBlankIndex += 5;
				}

				if (iBlankIndex % 5 != 4)
				{
					iNumber[iBlankIndex] = iNumber[iBlankIndex + 1];
					iNumber[iBlankIndex + 1] = INT_MAX;
					iBlankIndex++;
				}
			}
			break;
		}
	}

	cout << endl;
	cout << "������ �����մϴ�." << endl;

	return 0;
}