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

	// ������ ������ �ε����� �����ϱ� ���� ������ �����ϰ� ���� ������ ��ġ�� 24�� �ε��� �̱� ������ 24�� �ε����� �ʱ�ȭ
	int iBlankIndex = 24;

	// 24�� �ε����� ������ �ǹ��ϴ� INT_MAX�� �ִ´�.
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

		cout << endl << endl;
		cout << "W : ��" << "\t";
		cout << "S : ��" << "\t";
		cout << "A : ��" << "\t";
		cout << "D : ��" << "\t";
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
	cout << "������ �����մϴ�." << endl;

	return 0;
}