#include <iostream>

using namespace std;
int main()
{
	srand(time(NULL));

	int iNumber[25] = {};
	for (int i = 0; i < 25; i++)
	{
		iNumber[i] = i + 1;
	}

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	int iBingo = 0;
	
	while (true)
	{
		system("cls");
		
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl << endl << endl;
		}
		cout << "Bingo Line : " << iBingo << endl;

		if (iBingo >= 5)
			break;

		cout << endl << "숫자를 입력하세요(0:종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;

		bool bAcc = true;
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iNumber[i])
			{
				bAcc = false;
				iNumber[i] = INT_MAX;
				break;
			}
		}

		if (bAcc)		
			continue;
		

		// 빙고 줄 수 체크
		iBingo = 0;
		int iStar1 = 0, iStar2 = 0;
		
		// 가로, 세로
		for (int i = 0; i < 5; i++)
		{
			iStar1 = iStar2 = 0;

			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;

				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
			}

			if (iStar1 == 5)
				++iBingo;
			
			if (iStar2 == 5)
				++iBingo;
		}

		
		// 좌상단 대각선
		iStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		// 우상단 대각선
		iStar1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;

	}


	return 0;
}