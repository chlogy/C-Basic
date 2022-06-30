#include <iostream>

using namespace std;

int main()
{
	int iNumber = 2222;
	int iNumber1 = 1111;

	int* pNum = &iNumber;

	/*
		이중포인터 : *을 2개 붙인다.
					일반 포인터 변수가 일반 변수의 메모리 주소를 저장하는 변수라면, 이중포인터는 포인터의 포인터이다.
					즉 이중포인터는 포인터 변수의 메모리 주소를 저장하는 포인터이다.
	*/

	int** ppNum = &pNum;
	
	*ppNum = &iNumber1;

//	*pNum = 3333;
	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "*pNum : " << *pNum << "\t" << ("pNum의 역참조. 즉, iNumber") << endl;
	cout << "pNum Value : " << pNum << "\t" << "(pNum이 가리키는 변수의 주소)" << endl;
	cout << "pNum Address : " << &pNum << endl;

	cout << "*ppNum : " << *ppNum << "\t" << "(ppNum의 역참조. 즉, pNum)" << endl;
	cout << "ppNum Value : " << ppNum << "\t" << "(ppNum이 가리키는 변수의 주소) : pNum의 주소" << endl;
	cout << "ppNum Address : " << &ppNum << endl;

	cout << "**ppNum : " << **ppNum << "\t" << "(ppNum의 역참조 : pNum의 역참조) 즉 iNumber" << endl;

	return 0;
}