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

// �Լ��� ����� ���� �κ����� ���� �� �ִ�.

void SettingNumber(int* pArray, int iSize);
void ArrayShuffle(int* pArray);
COMPUTER_MODE	SelectComputerMode();
void OutputNumber(int* pArray, int iBingo);

bool isFinish(int iBingo, int iComputerBingo);
bool ChangeNumber(int* pArray, int iInput);

int SelectComputerInput(int* pArray, COMPUTER_MODE eMode);

int BingoCounting(int* pArray);
int BingoCounting_Horizontal(int* pArray);
int BingoCounting_Vertical(int* pArray);
int BingoCounting_Diagonal(int* pArray, LINE_NUMBER eNumber);

void SetName(char* pName);

int main()
{
	srand(time(NULL));

	int iNumber[25] = {};
	int iComputerNumber[25] = {};

	SettingNumber(iNumber, 25);
	SettingNumber(iComputerNumber, 25);

	ArrayShuffle(iNumber);
	ArrayShuffle(iComputerNumber);

	int iBingo = 0, iComputerBingo = 0;

	char strName[NAME_SIZE] = {};
	SetName(strName);

	COMPUTER_MODE eComputerMode = SelectComputerMode();

	while (true)
	{
		system("cls");
		cout << "___________ BINGO GAME ___________" << endl << endl;
		cout << "============= " << strName << " ============= " << endl;

		OutputNumber(iNumber, iBingo);


		switch (eComputerMode)
		{
		case CM_EASY:
			cout << "========= Computer  Easy =========" << endl;
			break;
		case CM_HARD:
			cout << "========= Computer  Hard =========" << endl;
			break;
		}

		OutputNumber(iComputerNumber, iComputerBingo);

		// �º� ����
		if (isFinish(iBingo, iComputerBingo))
			break;


		cout << endl << "���ڸ� �Է��ϼ���(0:����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;

		bool bAcc = ChangeNumber(iNumber, iInput);

		if (bAcc)
			continue;

		ChangeNumber(iComputerNumber, iInput);


		iInput = SelectComputerInput(iComputerNumber, eComputerMode);

		// ��ǻ�Ͱ� ������ ���ڸ� �÷��̾� �����ǿ� ����
		ChangeNumber(iNumber, iInput);


		// ��ǻ�Ͱ� ������ ���ڸ� ��ǻ�� �����ǿ� ����
		ChangeNumber(iComputerNumber, iInput);



		// ���� �� �� üũ
		iBingo = BingoCounting(iNumber);
		iComputerBingo = BingoCounting(iComputerNumber);
				
	}

	cout << endl << "������ �����մϴ�." << endl;

	return 0;
}

void SettingNumber(int* pArray, int iSize)
{
	for (int i = 0; i < iSize; i++)
	{
		pArray[i] = i + 1;
	}
}

void ArrayShuffle(int* pArray)
{
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = iTemp;
	}
}

COMPUTER_MODE SelectComputerMode()
{
	int iComputerMode;

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

	return (COMPUTER_MODE)iComputerMode;
}

void OutputNumber(int* pArray, int iBingo)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (pArray[i * 5 + j] == INT_MAX)
				cout << "*\t";
			else
				cout << pArray[i * 5 + j] << "\t";
		}
		cout << endl << endl << endl;
	}
	cout << "Bingo Line : " << iBingo << endl << endl << endl;
}

bool isFinish(int iBingo, int iComputerBingo)
{
	if (iBingo >= 5 && iComputerBingo >= 5)
	{
		if (iBingo > iComputerBingo)
			cout << "Player Win !!!!!" << endl;

		else if (iBingo < iComputerBingo)
			cout << "Computer Win !!!!!" << endl;

		else
			cout << "Draw !!!!!!!" << endl;


		return true;
	}
	else if (iBingo >= 5)
	{
		cout << "Player Win !!!!!" << endl;
		return true;
	}
	else if (iComputerBingo >= 5)
	{
		cout << "Computer Win !!!!!" << endl;
		return true;
	}

	return false;
}

bool ChangeNumber(int* pArray, int iInput)
{
	for (int i = 0; i < 25; i++)
	{
		if (iInput == pArray[i])
		{
			pArray[i] = INT_MAX;

			return false;
		}
	}

	return true;
}

int SelectComputerInput(int* pArray, COMPUTER_MODE eMode)
{
	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	// ���̵��� ���� ��ǻ���� ����
	switch (eMode)
	{
	case CM_EASY:
		iNoneSelectCount = 0;

		for (int i = 0; i < 25; i++)
		{
			if (pArray[i] != INT_MAX)
			{
				iNoneSelect[iNoneSelectCount] = pArray[i];
				iNoneSelectCount++;
			}
		}

		return iNoneSelect[rand() % iNoneSelectCount];

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
				if (pArray[i * 5 + j] == INT_MAX)
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
				if (pArray[j * 5 + i] == INT_MAX)
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
			if (pArray[i] == INT_MAX)
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
			if (pArray[i] == INT_MAX)
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
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
				}
			}
		}
		else if (iLine <= LN_V5)
		{
			for (int i = 0; i < 5; i++)
			{
				if (pArray[i * 5 + iLine - LN_V1] != INT_MAX)
				{
					return pArray[i * 5 + iLine - LN_V1];
				}
			}
		}
		else if (iLine == LN_LT)
		{
			for (int i = 0; i < 25; i += 6)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}
		else if (iLine == LN_RT)
		{
			for (int i = 4; i <= 20; i += 4)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}


		break;
	}

	return -1;
}

int BingoCounting(int* pArray)
{
	int iBingo = 0;

	// ����
	iBingo += BingoCounting_Horizontal(pArray);

	// ����
	iBingo += BingoCounting_Vertical(pArray);

	// �밢��
	iBingo += BingoCounting_Diagonal(pArray, LN_LT);
	iBingo += BingoCounting_Diagonal(pArray, LN_RT);

	return iBingo;
}

int BingoCounting_Horizontal(int* pArray)
{
	int iStar1 = 0, iBingo = 0;

	// ����
	for (int i = 0; i < 5; i++)
	{
		iStar1 = 0;

		for (int j = 0; j < 5; j++)
		{
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar1;
		}

		if (iStar1 == 5)
			++iBingo;
	}

	return iBingo;
}

int BingoCounting_Vertical(int* pArray)
{
	int iStar1 = 0, iBingo = 0;

	// ����
	for (int i = 0; i < 5; i++)
	{
		iStar1 = 0;

		for (int j = 0; j < 5; j++)
		{
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar1;
		}

		if (iStar1 == 5)
			++iBingo;
	}

	return iBingo;
}

int BingoCounting_Diagonal(int* pArray, LINE_NUMBER eNumber)
{
	int iStar1 = 0, iBingo = 0;

	switch (eNumber)
	{
	case LN_LT:
		// �»�� �밢��
		for (int i = 0; i < 25; i += 6)
		{
			if (pArray[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		break;
	case LN_RT:
		// ���� �밢��
		for (int i = 4; i <= 20; i += 4)
		{
			if (pArray[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		break;
	}

	return iBingo;
}

void SetName(char* pName)
{
	cout << "___________ BINGO GAME ___________" << endl << endl;

	cout << "����� �̸��� �Է����ּ��� : ";
	cin >> pName;
}