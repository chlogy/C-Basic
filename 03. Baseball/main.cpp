#include <iostream>

using namespace std;

/*
	�߱����� �����

	1 ~ 9 ������ ������ ���� 3���� ���´�.
	��, ���ڴ� �ߺ��Ǿ�� �ȵȴ�.

	3���� ���ڴ� * * *�� ���·� ��µǰ�, �� 3���� ���ڸ� ���ߴ� �����̴�.

	����ڴ� �� 3���� ���߸� ���� ������ ����ؼ� 3���� ���ڸ� �Է��Ѵ�.

	���� ����� �� ���ڰ� 7 3 8�� ���

	���� �Է¹��� ���ڰ� 3�� �� �Ѱ��� 0�� ���� ��� ������ �����Ѵ�.
	3���� ���ڸ� ��� ��ġ�ϰ� �ϸ� ������ �����Ѵ�.
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
		cout << iCount << "ȸ" << endl;
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

		cout << iGameCount << " ȸ��" << endl;
		cout << "* * *" << endl;
		// cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl;

		cout << "1 ~ 9 ������ ���� �߿� ���� 3���� �Է��ϼ���! (0:����) : ";

		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;

		else if (iInput[0] < 0 || iInput[0] > 9
			|| iInput[1] < 0 || iInput[1] > 9
			|| iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�." << endl;
			system("pause");
			continue;
		}
		else if (iInput[0] == iInput[1]
			|| iInput[0] == iInput[2] 
			|| iInput[1] == iInput[2])
		{
			cout << "�ߺ��� ���ڸ� �Է��Ͽ����ϴ�." << endl;
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
					// ���� ������ ���� ������ Strike or Ball
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
			cout << iGameCount  << "ȸ�� ���� ���ڸ� ��� ������ϴ�." << endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
			cout << "OUT!!!!!!!!" << endl;

		else
			cout << iStrike << " Strike " << iBall << " Ball" << endl;


		iGameCount++;

		system("pause");
	}


	cout << "������ �����մϴ�." << endl;


	return 0;
}