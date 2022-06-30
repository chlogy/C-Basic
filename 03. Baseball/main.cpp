#include <iostream>

using namespace std;

/*
	야구게임 만들기

	1 ~ 9 사이의 랜덤한 숫자 3개를 얻어온다.
	단, 숫자는 중복되어서는 안된다.

	3개의 숫자는 * * *의 형태로 출력되고, 이 3개의 숫자를 맞추는 게임이다.

	사용자는 이 3개의 숫잘르 맞출 때까지 계속해서 3개의 숫자를 입력한다.

	만약 맞춰야 할 숫자가 7 3 8일 경우

	만약 입력받은 숫자가 3개 중 한개라도 0이 있을 경우 게임을 종료한다.
	3개의 숫자를 모두 일치하게 하면 게임을 종료한다.
*/

int main()
{
	srand((unsigned int)time(NULL));

	int iNumber[9] = {};
	for (int i = 0; i < 9; i++)
	{
		iNumber[i] = i + 1;
	}

	int iTemp, idx1, idx2;
//	int iCount = 1;
	for (int i = 0; i < 200; i++)
	{
		/*system("cls");
		cout << iCount << "회" << endl;
		for (int i = 0; i < 9; i++)
		{
			cout << iNumber[i] << "\t";
		}
		iCount++;*/

		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	int iStrike = 0, iBall = 0;
	int iInput[3] = {};
	
	int iGameCount = 1;

	while (true)
	{
		system("cls");

		cout << iGameCount << " 회차" << endl;
		cout << "* * *" << endl;
		// cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl;

		cout << "1 ~ 9 사이의 숫자 중에 숫자 3개를 입력하세요! (0:종료) : ";

		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;

		else if (iInput[0] < 0 || iInput[0] > 9
			|| iInput[1] < 0 || iInput[1] > 9
			|| iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "잘못된 숫자를 입력하였습니다." << endl;
			system("pause");
			continue;
		}
		else if (iInput[0] == iInput[1]
			|| iInput[0] == iInput[2] 
			|| iInput[1] == iInput[2])
		{
			cout << "중복된 숫자를 입력하였습니다." << endl;
			system("pause");
			continue;
		}

		
		iStrike = iBall = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (iNumber[i] == iInput[j])
				{
					// 여기 들어오는 순간 무조건 Strike or Ball
					if (i == j)
						++iStrike;
					else
						++iBall;

					break;
				}
			}
		}

		if (iStrike == 3)
		{
			cout << iGameCount  << "회차 만에 숫자를 모두 맞췄습니다." << endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
			cout << "OUT!!!!!!!!" << endl;

		else
			cout << iStrike << " Strike " << iBall << " Ball" << endl;


		iGameCount++;

		system("pause");
	}


	cout << "게임을 종료합니다." << endl;


	return 0;
}