#include <iostream>

#define NAME_SIZE	32
#define INPUT_ERROR	-1

using namespace std;

enum MAIN_MENU
{
	MM_INSERT = 1,
	MM_DELETE,
	MM_SEARCH,
	MM_PRINT,
	MM_REVERSE,
	MM_EXIT
};

typedef struct __tagStudent
{
	char	strName[NAME_SIZE];

	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAverage;
}STUDENT, *PSTUDENT;

typedef struct __tagNode
{
	STUDENT		tStudent;

	__tagNode*	pNext;
	__tagNode*	pPrev;
}NODE, *PNODE;

typedef struct __tagList
{
	PNODE	pHead;
	PNODE	pTail;

	int		iSize;
}LIST, *PLIST;

void InitList(PLIST _pList)
{
	_pList->pHead = nullptr;
	_pList->pTail = nullptr;
	_pList->iSize = 0;
}

int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');

		return INPUT_ERROR;
	}

	return iInput;
}

void InputString(char* _pString, int _iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');

	cin.getline(_pString, _iSize - 1);
}

int PrintMenu()
{
	system("cls");

	cout << "_______________ STUDENT MANAGEMENT PROGRAM _______________" << endl << endl;
	cout << "1. �л� ���� �߰�" << endl << endl;
	cout << "2. �л� ���� ����" << endl << endl;
	cout << "3. �л� ���� �˻�" << endl << endl;
	cout << "4. ��ü �л� ���" << endl << endl;
	cout << "5. �л� ���� ����" << endl << endl;
	cout << "6. ���α׷� ����" << endl << endl << endl << endl;

	cout << "�޴��� �����ϼ��� : ";

	int iInput = InputInt();

	if (iInput < MM_INSERT || iInput > MM_EXIT)
		return INPUT_ERROR;

	return iInput;
}

void Insert(PLIST _pList)
{
	system("cls");
	cout << "_______________ STUDENT INFORMATION INSERT _______________" << endl << endl;
	
	STUDENT tStudent = {};

	cout << "�� �� : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "�� �� : ";
	tStudent.iNumber = InputInt();

	cout << "�� �� : ";
	tStudent.iKor = InputInt();

	cout << "�� �� : ";
	tStudent.iEng = InputInt();

	cout << "�� �� : ";
	tStudent.iMath = InputInt();


	// ����, ���
	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAverage = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE;

	// ���� ���� �߰��ϴ� ���� ���� �������� �߰��� ���̱� ������ ���� ��尡 �������� �ʴ´�.
	// �߰��� ����� ������ nullptr�� �ʱ�ȭ�ϰ� �����ʹ� ������ �Է��� �л� ������ �ֵ��� �Ѵ�.

	pNode->pNext = nullptr;
	pNode->tStudent = tStudent;

	if (_pList->pHead == nullptr)
		_pList->pHead = pNode;

	else
		_pList->pTail->pNext = pNode;

	_pList->pTail = pNode;

	++_pList->iSize;
}

void ClearList(PLIST _pList)
{
	PNODE pNode = _pList->pHead;

	while (pNode != nullptr)
	{
		PNODE pNext = pNode->pNext;

		delete pNode;

		pNode = pNext;
	}

	_pList->pHead = nullptr;
	_pList->pTail = nullptr;
	_pList->iSize = 0;
}

void PrintStudentInformation(const __tagStudent* _pStudent)
{
	//int iValue1 = 10;
	//int iValue2 = 20;
	//int iValue3 = 30;

	//const int* ptr1 = &iValue1;		// ����Ų ����� �������Ͽ� ���� �ٲ� �� ����.		(�����Ͱ� �������ϴ� ���� ���ȭ)
	//int* const ptr2 = &iValue2;		// ����Ű�� ����� �ٲ� �� ����.					(������ ������ ���ȭ)
	//int const* ptr3 = &iValue3;		// ����Ų ����� �������Ͽ� ���� �ٲ� �� ����.		(�����Ͱ� �������ϴ� ���� ���ȭ)



	cout << "�� �� : " << _pStudent->strName << "\t�� �� : " << _pStudent->iNumber << endl;
	cout << "�� �� : " << _pStudent->iKor << "\t�� �� : " << _pStudent->iEng << "\t�� �� : " << _pStudent->iMath << endl;
	cout << "�� �� : " << _pStudent->iTotal << "\t�� �� : " << _pStudent->fAverage << endl << endl << endl;
}

void Print()
{

}

void Print(PLIST _pList)
{
	system("cls");
	cout << "_______________ EVERY STUDENT INFORM PRINT _______________" << endl << endl;

	PNODE pNode = _pList->pHead;

	while (pNode != nullptr)
	{
		PrintStudentInformation(&pNode->tStudent);
		pNode = pNode->pNext;
	}

	system("pause");
}

void ReversePrint()
{

}

void Search(PLIST _pList)
{
	system("cls");
	cout << "_______________ STUDENT INFORMATION SEARCH _______________" << endl << endl;

	cout << "�˻��� �л��� �̸��� �Է��ϼ��� : ";

	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = _pList->pHead;
	while (pNode != nullptr)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			PrintStudentInformation(&pNode->tStudent);
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}

	cout << "ã�� �л��� ������ �������� �ʽ��ϴ�." << endl << endl;
	system("pause");
}

void Delete(PLIST _pList)
{
	system("cls");
	cout << "_______________ STUDENT INFORMATION DELETE _______________" << endl << endl;

	cout << "������ �л��� �̸��� �Է��ϼ��� : ";

	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = _pList->pHead;
	PNODE pPrev = nullptr;

	while (pNode != nullptr)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			cout << endl << strName << "�л� ����" << endl << endl;

			PNODE pNext = pNode->pNext;

			// ���� ��尡 ù �����
			if (pPrev == nullptr)
			{
				delete pNode;
				_pList->pHead = pNext;

				// ���� ��嵵 nullptr�̶�� ���� ���� ��忴�� ��Ȳ�̾����Ƿ� pTail�� nullptr�� ����
				if (pNext == nullptr)
					_pList->pTail = nullptr;
			}
			// ������尡 ������� ���� ����� pNext�� ���� ����� pNext�� ����
			else
			{
				delete pNode;
				pPrev->pNext = pNext;

				// ���� ���� ��尡 ������ ��忴�����
				if (pNext == nullptr)
					_pList->pTail = pPrev;
			}

			cout << strName << "�л� ���� �Ϸ�" << endl << endl;
			system("pause");
			--_pList->iSize;
			return;
		}

		// ���� ��尡 ��尡 �ƴ϶�� ���� ���� ���� ��尡 �ǰ�
		// ���� ���� ���� ��带 ����Ų��.
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	cout << "������ �л��� ������ �������� �ʽ��ϴ�." << endl << endl;
	system("pause");
}

void Delete2(PLIST _pList)
{
	system("cls");
	cout << "_______________ STUDENT INFORMATION DELETE _______________" << endl << endl;

	cout << "������ �л��� �̸��� �Է��ϼ��� : ";

	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = _pList->pHead;
	PNODE pPrev = nullptr;

	while (pNode != nullptr)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			cout << endl << strName << "�л� ����" << endl << endl;

			// ���� ��尡 ù �����
			if (pPrev == nullptr)
			{
				// ���� ��嵵 nullptr�̶�� ���� ���� ��忴�� ��Ȳ�̾����Ƿ� pTail�� nullptr�� ����
				if (pNode->pNext == nullptr)
					_pList->pTail = nullptr;

				_pList->pHead = pNode->pNext;
				delete pNode;
			}
			// ������尡 ������� ���� ����� pNext�� ���� ����� pNext�� ����
			else
			{
				// ���� ���� ��尡 ������ ��忴�����
				if (pNode->pNext == nullptr)
					_pList->pTail = pPrev;

				pPrev->pNext = pNode->pNext;
				delete pNode;				
			}

			cout << strName << "�л� ���� �Ϸ�" << endl << endl;
			system("pause");
			--_pList->iSize;
			return;
		}

		// ���� ��尡 ��尡 �ƴ϶�� ���� ���� ���� ��尡 �ǰ�
		// ���� ���� ���� ��带 ����Ų��.
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	cout << "������ �л��� ������ �������� �ʽ��ϴ�." << endl << endl;
	system("pause");
}

//__tagNode* ReverseGetFirstNode(__tagNode* pHead)
//{
//	// __tagNode* p, *q, *r;
//	__tagNode* p, *q, *r;
//
//	p = pHead;
//	q = nullptr;
//
//	while (p != nullptr)
//	{
//		r = q;
//		q = p;
//		p = p->pNext;
//		q->pNext = r;
//	}
//
//	return q;
//}

//void ReverseCall(PLIST _pList)
//{
//	_pList->pHead = ReverseGetFirstNode(_pList->pHead);
//}

void Reverse(PLIST _pList)
{
	// __tagNode* p, *q, *r;
	PNODE p, q, r;

	p = _pList->pHead;
	q = nullptr;

	while (p != nullptr)
	{
		r = q;
		q = p;
		p = p->pNext;
		q->pNext = r;
	}

	_pList->pHead = q;
}

int main()
{
	LIST tList;
	InitList(&tList);

	while (true)
	{
		int iMenu = PrintMenu();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_INSERT:
			Insert(&tList);
			break;
		case MM_DELETE:
			Delete2(&tList);
			break;
		case MM_SEARCH:
			Search(&tList);
			break;
		case MM_PRINT:
			Print(&tList);
			break;

		case MM_REVERSE:
			Reverse(&tList);
			break;
		}
	}

	ClearList(&tList);

	return 0;
}