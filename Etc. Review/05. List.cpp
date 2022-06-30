#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE	9

#pragma warning(disable:4996)

typedef	struct _tagStudent
{
	char	strName[NAME_SIZE];

	int		iNumber;
	int		iMath;
	int		iEng;
	int		iKor;	
	int		iTotal;
	float	fAvg;

}STUDENT, *PSTUDENT;

typedef struct _tagNode 
{
	STUDENT		tStudent;
	
	_tagNode*	pNext;

}NODE, *PNODE;

typedef struct _tagList 
{
	PNODE	pBegin = NULL;
	PNODE	pEnd = NULL;

}LIST, *PLIST;

int OutputMain()
{
	printf_s("<<���� ���� ���α׷�>>\n");
	printf_s(">>-0- ����\n");
	printf_s(">>-1- �˻�\n");
	printf_s(">>-2- ���\n");
	printf_s(">>-3- �߰�\n\n");

	int iInput;
	scanf_s("%d", &iInput);

	return iInput;
}

void Insert(PLIST pList)
{
	STUDENT tStudent = {};

	printf_s("�߰��� �л� �̸� : ");
	scanf_s("%s", tStudent.strName, sizeof(tStudent.strName));

	printf_s("�� �� : ");
	scanf_s("%d", &tStudent.iNumber);

	printf_s("���� ���� : ");
	scanf_s("%d", &tStudent.iMath);

	printf_s("���� ���� : ");
	scanf_s("%d", &tStudent.iEng);

	printf_s("���� ���� : ");
	scanf_s("%d", &tStudent.iKor);

	tStudent.iTotal = tStudent.iMath + tStudent.iEng + tStudent.iKor;
	tStudent.fAvg = tStudent.iTotal / 3.f;


	PNODE	pNode = (NODE*)malloc(sizeof(NODE));

	pNode->tStudent = tStudent;
	pNode->pNext = nullptr;
	
	if (pList->pBegin == NULL)
		pList->pBegin = pNode;

	else
	{
		// pList->pEnd->pNext = pNode;

		PNODE pLast = pList->pBegin;
		while (pLast->pNext != NULL)
		{
			pLast = pLast->pNext;
		}

		pLast->pNext = pNode;
	}

	// pList->pEnd = pNode;
}


void InsertData(PLIST pList, STUDENT tStudent)
{
	PNODE	pNode = (NODE*)malloc(sizeof(NODE));

	pNode->tStudent = tStudent;
	pNode->pNext = nullptr;

	if (pList->pBegin == NULL)
		pList->pBegin = pNode;

	else
	{
		// pList->pEnd->pNext = pNode;

		PNODE pLast = pList->pBegin;
		while (pLast->pNext != NULL)
		{
			pLast = pLast->pNext;
		}

		pLast->pNext = pNode;
	}

	// pList->pEnd = pNode;
}

void OutputStudent(PSTUDENT pStudent)
{
	printf_s("��");
	printf_s("%9d", pStudent->iNumber);
	printf_s("��");

	printf_s("%8s", pStudent->strName);
	printf_s("��");

	printf_s("%4d", pStudent->iMath);
	printf_s("%4s", "��");

	printf_s("%4d", pStudent->iEng);
	printf_s("%4s", "��");

	printf_s("%4d", pStudent->iKor);
	printf_s("%4s", "��\n");
}

void Output(PLIST pList)
{
	PNODE	pNode = pList->pBegin;

	printf_s("��=============================================��\n");
	printf_s("�� ��   �� ��  ��  ��  �� ���� �� ���� �� ���� ��\n");
	printf_s("��=============================================��\n");

	while (pNode != NULL)
	{
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext;
	}

	printf_s("��=============================================��\n");

}

void OutputResult(PSTUDENT pStudent)
{
	printf_s("< �̸� : ");
	printf_s("%s >\n", pStudent->strName);

	printf_s("< ���� : ");
	printf_s("%d >\n", pStudent->iMath);
	printf_s("< ���� : ");
	printf_s("%d >\n", pStudent->iEng);
	printf_s("< ���� : ");
	printf_s("%d >\n", pStudent->iKor);

	printf_s("< ���� : ");
	printf_s("%d >\n", pStudent->iTotal);
	printf_s("< ��� : ");
	printf_s("%f >\n\n", pStudent->fAvg);
}

void Search(PLIST pList)
{
	printf_s("�˻��� �й� : ");
	int iNumber;
	scanf_s("%d", &iNumber);

	PNODE	pNode = pList->pBegin;

	while (pNode != NULL)
	{
		if (pNode->tStudent.iNumber == iNumber)
		{
			OutputResult(&pNode->tStudent);
		}
		pNode = pNode->pNext;
	}
}

void ClearList(PLIST pList)
{
	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		PNODE	pNext = pNode->pNext;
		delete	pNode;
		pNode = pNext;
	}

	pList->pBegin = NULL;
	// pList->pBegin = NULL;
}

bool ReadData(PLIST pList)
{
	FILE* pFile;

	pFile = fopen("data.txt", "r");

	if (pFile == NULL)
	{
		printf("File Read Error\n");
		return false;
	}


	while (!feof(pFile))
	{
		STUDENT tStudent = {};

		fscanf(pFile, "%d %s %d %d %d",
			&tStudent.iNumber, tStudent.strName,
			&tStudent.iMath, &tStudent.iEng, &tStudent.iKor);

		InsertData(pList, tStudent);
	}
}


int main()
{
	LIST tList;

	bool bEnd = ReadData(&tList);

	while (bEnd)
	{
		switch (OutputMain())
		{
		case 0:
			bEnd = false;
			break;
		case 1:
			Search(&tList);
			break;
		case 2:
			Output(&tList);
			break;
		case 3:
			Insert(&tList);
			break;
		}
	}

	ClearList(&tList);

	return 0;
}