#include <iostream>

using namespace std;

int main()
{
	int iNumber = 2222;
	int iNumber1 = 1111;

	int* pNum = &iNumber;

	/*
		���������� : *�� 2�� ���δ�.
					�Ϲ� ������ ������ �Ϲ� ������ �޸� �ּҸ� �����ϴ� �������, ���������ʹ� �������� �������̴�.
					�� ���������ʹ� ������ ������ �޸� �ּҸ� �����ϴ� �������̴�.
	*/

	int** ppNum = &pNum;
	
	*ppNum = &iNumber1;

//	*pNum = 3333;
	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "*pNum : " << *pNum << "\t" << ("pNum�� ������. ��, iNumber") << endl;
	cout << "pNum Value : " << pNum << "\t" << "(pNum�� ����Ű�� ������ �ּ�)" << endl;
	cout << "pNum Address : " << &pNum << endl;

	cout << "*ppNum : " << *ppNum << "\t" << "(ppNum�� ������. ��, pNum)" << endl;
	cout << "ppNum Value : " << ppNum << "\t" << "(ppNum�� ����Ű�� ������ �ּ�) : pNum�� �ּ�" << endl;
	cout << "ppNum Address : " << &ppNum << endl;

	cout << "**ppNum : " << **ppNum << "\t" << "(ppNum�� ������ : pNum�� ������) �� iNumber" << endl;

	return 0;
}