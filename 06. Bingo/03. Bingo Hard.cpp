#include <iostream>
#define NAME_SIZE	 32

using namespace std;

enum COMPUTER_MODE
{
	CM_EASY = 1,
	CM_HARD,
	END,
};

enum LINE_NUMBER
{
	LN_H1,	// Line Number Horizontal ����
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,

	LN_V1,	// Line Number Vertical	 ����
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,

	LN_LT,
	LN_RT,
};

int main()
{
	srand(time(NULL));

	int iNumber[25] = {};
	int iComputerNumber[25] = {};
	for (int i = 0; i < 25; i++)
	{
		iNumber[i] = i + 1;
		iComputerNumber[i] = i + 1;
	}

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iComputerNumber[idx1];
		iComputerNumber[idx1] = iComputerNumber[idx2];
		iComputerNumber[idx2] = iTemp;
	}

	int iBingo = 0, iComputerBingo = 0;
	int iComputerMode;

	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	char strName[NAME_SIZE] = {};
	cout << "___________ BINGO GAME ___________" << endl << endl;

	cout << "����� �̸��� �Է����ּ��� : ";
	cin >> strName;

	while (true)
	{
		system("cls");
		cout << "___________ BINGO GAME ___________" << endl << endl;
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl << endl;

		cout << "��ǻ�� ���̵��� �����ϼ��� : ";

		cin >> iComputerMode;

		if (CM_EASY <= iComputerMode && iComputerMode <= CM_HARD)
			break;
	}

	while (true)
	{
		system("cls");
		cout << "___________ BINGO GAME ___________" << endl << endl;
		cout << "============= " << strName << " ============= " << endl;

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
		cout << "Bingo Line : " << iBingo << endl << endl << endl;


		switch (iComputerMode)
		{
		case CM_EASY:
			cout << "========= Computer  Easy =========" << endl;
			break;
		case CM_HARD:
			cout << "========= Computer  Hard =========" << endl;
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iComputerNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iComputerNumber[i * 5 + j] << "\t";
			}
			cout << endl << endl << endl;
		}
		cout << "Bingo Line : " << iComputerBingo << endl << endl << endl;

		// �º� ����
		if (iBingo >= 5 && iComputerBingo >= 5)
		{
			if (iBingo > iComputerBingo)
				cout << "Player Win !!!!!" << endl;

			else if (iBingo < iComputerBingo)
				cout << "Computer Win !!!!!" << endl;

			else
				cout << "Draw !!!!!!!" << endl;


			break;
		}
		else if (iBingo >= 5)
		{
			cout << "Player Win !!!!!" << endl;
			break;
		}
		else if (iComputerBingo >= 5)
		{
			cout << "Computer Win !!!!!" << endl;
			break;
		}


		cout << endl << "���ڸ� �Է��ϼ���(0:����) : ";
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

		for (int i = 0; i < 25; i++)
		{
			if (iInput == iComputerNumber[i])
			{
				iComputerNumber[i] = INT_MAX;
				break;
			}
		}


		// ���̵��� ���� ��ǻ���� ����
		switch (iComputerMode)
		{
		case CM_EASY:
			iNoneSelectCount = 0;

			for (int i = 0; i < 25; i++)
			{
				if (iComputerNumber[i] != INT_MAX)
				{
					iNoneSelect[iNoneSelectCount] = iComputerNumber[i];
					iNoneSelectCount++;
				}
			}

			iInput = iNoneSelect[rand() % iNoneSelectCount];

			break;
		case CM_HARD:
			// TODO
			int	iLine = 0;
			int	iStarCount = 0;
			int iSaveCount = 0;

			// ���� �� �� üũ
			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; j++)
				{
					if (iComputerNumber[i * 5 + j] == INT_MAX)
						++iStarCount;
				}

				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// ���� �� �� üũ
			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; j++)
				{
					if (iComputerNumber[j * 5 + i] == INT_MAX)
						++iStarCount;
				}

				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = i + LN_V1;
					iSaveCount = iStarCount;
				}
			}

			// �»��
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iComputerNumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}


			iStarCount = 0;
			for (int i = 4; i <= 20; i += 4)
			{
				if (iComputerNumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}


			// ������ �� ���
			if (iLine <= LN_H5)
			{
				for (int i = 0; i < 5; i++)
				{
					if (iComputerNumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iComputerNumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_V5)
			{
				for (int i = 0; i < 5; i++)
				{
					if (iComputerNumber[i * 5 + iLine - LN_V1] != INT_MAX)
					{
						iInput = iComputerNumber[i * 5 + iLine - LN_V1];
						break;
					}
				}
			}
			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (iComputerNumber[i] != INT_MAX) 
					{
						iInput = iComputerNumber[i];
						break;
					}
				}
			}
			else if (iLine == LN_RT)
			{
				for (int i = 4; i <= 20; i += 4)
				{
					if (iComputerNumber[i] != INT_MAX)
					{
						iInput = iComputerNumber[i];
						break;
					}
				}
			}


			break;
		}

		// ��ǻ�Ͱ� ������ ���ڸ� �÷��̾� �����ǿ� ����
		for (int i = 0; i < 25; i++)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		// ��ǻ�Ͱ� ������ ���ڸ� ��ǻ�� �����ǿ� ����
		for (int i = 0; i < 25; i++)
		{
			if (iComputerNumber[i] == iInput)
			{
				iComputerNumber[i] = INT_MAX;
				break;
			}
		}


		// ���� �� �� üũ
		iBingo = 0;
		iComputerBingo = 0;

		int iStar1 = 0, iStar2 = 0;
		int iComputerStar1 = 0, iComputerStar2 = 0;

		// ����, ����
		for (int i = 0; i < 5; i++)
		{
			iStar1 = iStar2 = 0;
			iComputerStar1 = iComputerStar2 = 0;

			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;

				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

				if (iComputerNumber[i * 5 + j] == INT_MAX)
					++iComputerStar1;

				if (iComputerNumber[j * 5 + i] == INT_MAX)
					++iComputerStar2;
			}

			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;

			if (iComputerStar1 == 5)
				++iComputerBingo;

			if (iComputerStar2 == 5)
				++iComputerBingo;
		}


		// �»�� �밢��
		iStar1 = 0;
		iComputerStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iComputerNumber[i] == INT_MAX)
				++iComputerStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		if (iComputerStar1 == 5)
			++iComputerBingo;


		// ���� �밢��
		iStar1 = 0;
		iComputerStar1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iComputerNumber[i] == INT_MAX)
				++iComputerStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		if (iComputerStar1 == 5)
			++iComputerBingo;

	}

	cout << endl << "������ �����մϴ�." << endl;

	return 0;
}