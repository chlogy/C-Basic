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
	cout << "1. 학생 정보 추가" << endl << endl;
	cout << "2. 학생 정보 삭제" << endl << endl;
	cout << "3. 학생 정보 검색" << endl << endl;
	cout << "4. 전체 학생 출력" << endl << endl;
	cout << "5. 학생 정보 역순" << endl << endl;
	cout << "6. 프로그램 종료" << endl << endl << endl << endl;

	cout << "메뉴를 선택하세요 : ";

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

	cout << "이 름 : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "학 번 : ";
	tStudent.iNumber = InputInt();

	cout << "국 어 : ";
	tStudent.iKor = InputInt();

	cout << "영 어 : ";
	tStudent.iEng = InputInt();

	cout << "수 학 : ";
	tStudent.iMath = InputInt();


	// 총점, 평균
	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAverage = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE;

	// 지금 현재 추가하는 노드는 가장 마지막에 추가될 것이기 때문에 다음 노드가 존재하지 않는다.
	// 추가할 노드의 다음은 nullptr로 초기화하고 데이터는 위에서 입력한 학생 정보를 주도록 한다.

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

	//const int* ptr1 = &iValue1;		// 가리킨 대상을 역참조하여 값을 바꿀 수 없다.		(포인터가 역참조하는 것을 상수화)
	//int* const ptr2 = &iValue2;		// 가리키는 대상을 바꿀 수 없다.					(포인터 변수를 상수화)
	//int const* ptr3 = &iValue3;		// 가리킨 대상을 역참조하여 값을 바꿀 수 없다.		(포인터가 역참조하는 것을 상수화)



	cout << "이 름 : " << _pStudent->strName << "\t학 번 : " << _pStudent->iNumber << endl;
	cout << "국 어 : " << _pStudent->iKor << "\t영 어 : " << _pStudent->iEng << "\t수 학 : " << _pStudent->iMath << endl;
	cout << "총 점 : " << _pStudent->iTotal << "\t평 균 : " << _pStudent->fAverage << endl << endl << endl;
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

	cout << "검색할 학생의 이름을 입력하세요 : ";

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

	cout << "찾는 학생의 정보가 존재하지 않습니다." << endl << endl;
	system("pause");
}

void Delete(PLIST _pList)
{
	system("cls");
	cout << "_______________ STUDENT INFORMATION DELETE _______________" << endl << endl;

	cout << "삭제할 학생의 이름을 입력하세요 : ";

	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = _pList->pHead;
	PNODE pPrev = nullptr;

	while (pNode != nullptr)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			cout << endl << strName << "학생 삭제" << endl << endl;

			PNODE pNext = pNode->pNext;

			// 지울 노드가 첫 노드라면
			if (pPrev == nullptr)
			{
				delete pNode;
				_pList->pHead = pNext;

				// 다음 노드도 nullptr이라면 현재 단일 노드였던 상황이었으므로 pTail을 nullptr로 변경
				if (pNext == nullptr)
					_pList->pTail = nullptr;
			}
			// 이전노드가 있을경우 이전 노드의 pNext를 지운 노드의 pNext로 연결
			else
			{
				delete pNode;
				pPrev->pNext = pNext;

				// 내가 지운 노드가 마지막 노드였더라면
				if (pNext == nullptr)
					_pList->pTail = pPrev;
			}

			cout << strName << "학생 삭제 완료" << endl << endl;
			system("pause");
			--_pList->iSize;
			return;
		}

		// 현재 노드가 노드가 아니라면 이전 노드는 현재 노드가 되고
		// 현재 노드는 다음 노드를 가리킨다.
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	cout << "삭제할 학생의 정보가 존재하지 않습니다." << endl << endl;
	system("pause");
}

void Delete2(PLIST _pList)
{
	system("cls");
	cout << "_______________ STUDENT INFORMATION DELETE _______________" << endl << endl;

	cout << "삭제할 학생의 이름을 입력하세요 : ";

	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = _pList->pHead;
	PNODE pPrev = nullptr;

	while (pNode != nullptr)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			cout << endl << strName << "학생 삭제" << endl << endl;

			// 지울 노드가 첫 노드라면
			if (pPrev == nullptr)
			{
				// 다음 노드도 nullptr이라면 현재 단일 노드였던 상황이었으므로 pTail을 nullptr로 변경
				if (pNode->pNext == nullptr)
					_pList->pTail = nullptr;

				_pList->pHead = pNode->pNext;
				delete pNode;
			}
			// 이전노드가 있을경우 이전 노드의 pNext를 지운 노드의 pNext로 연결
			else
			{
				// 내가 지운 노드가 마지막 노드였더라면
				if (pNode->pNext == nullptr)
					_pList->pTail = pPrev;

				pPrev->pNext = pNode->pNext;
				delete pNode;				
			}

			cout << strName << "학생 삭제 완료" << endl << endl;
			system("pause");
			--_pList->iSize;
			return;
		}

		// 현재 노드가 노드가 아니라면 이전 노드는 현재 노드가 되고
		// 현재 노드는 다음 노드를 가리킨다.
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	cout << "삭제할 학생의 정보가 존재하지 않습니다." << endl << endl;
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