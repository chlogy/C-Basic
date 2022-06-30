#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	int iNumber[25] = {};

	for (int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}

	// 앞으로 공백의 인덱스를 저장하기 위한 변수를 선언하고 최초 공백의 위치는 24번 인덱스 이기 때문에 24번 인덱스로 초기화
	int iBlankIndex = 24;

	// 24번 인덱스는 공백을 의미하는 INT_MAX를 넣는다.
	iNumber[24] = INT_MAX;

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;
		
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
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
					cout << iNumber[i * 5 + j] << "\t";			// 줄번호 * 가로개수 + 칸번호
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
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		cout << endl << endl;
		cout << "W : ↑" << "\t";
		cout << "S : ↓" << "\t";
		cout << "A : ←" << "\t";
		cout << "D : →" << "\t";
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
			}
			break;
		case 'S':
		case 's':
			if (iBlankIndex < 20)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex + 5];
				iNumber[iBlankIndex + 5] = INT_MAX;
				iBlankIndex += 5;
			}			
			break;
		case 'A':
		case 'a':
			if (iBlankIndex % 5 != 0)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex - 1];
				iNumber[iBlankIndex - 1] = INT_MAX;
				iBlankIndex--;
			}
			break;
		case 'D':
		case 'd':
			if (iBlankIndex % 5 != 4)
			{
				iNumber[iBlankIndex] = iNumber[iBlankIndex + 1];
				iNumber[iBlankIndex + 1] = INT_MAX;
				iBlankIndex++;
			}			
			break;
		}
	}

	cout << endl;
	cout << "게임을 종료합니다." << endl;

	return 0;
}