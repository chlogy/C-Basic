#include <iostream>

using namespace std;

struct _tagStudent
{
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

int main()
{
	const char* pText = "Hello World";
	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "Hello Friends";
	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "Hello Friends";
	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "Hello Bro";
	cout << pText << endl;
	cout << (int*)pText << endl;

	char str[10] = "Hello Bro";
	cout << str << endl;
	cout << (int*)str << endl;

	

	cout << "________________________" << endl;
	cout << pText << endl;			// Hello Bro
	cout << &pText << endl;			// pText의 주소
	cout << (char*)pText << endl;	// Hello Bro
	cout << (int*)pText << endl;	// Hello Bro 상수 문자열의 주소
	cout << *pText << endl;			// H
	cout << &pText[0] << endl;		// Hello Bro



	_tagStudent tStudent = {};
	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;
	cout << tStudent.iKor << endl;

	/*
		연산자 우선 순위 때문에 .을 먼저 인식하게 된다.
		메모리 주소. 은 잘못된 문법이다.
		그러므로 *pStudent 를 괄호로 감싸준 뒤에 .을 이용해서 가리키는 대상의 멤버 변수에 접근해야 한다.
	*/
	(*pStudent).iKor = 300;
	cout << tStudent.iKor << endl;

	pStudent->iKor = 1004;
	cout << tStudent.iKor << endl;
	/*
		메모리주소 ->를 이용해서 가리키는 대상의 멤버에 접근할 수 있다.
	*/


	// void*

	/*
		void :	c++에서 void의 의미는 타입이 없다.
				void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든 모두 저장이 가능하다.

				단, 역참조가 불가능하고 메모리 주소만 저장이 가능하다.
	*/
	int	iNumber = 100;
	void* pVoid = &iNumber;

	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "iNumber Address : " << pVoid << endl;

	// *pVoid = 10;

	pVoid = &tStudent;
	cout << "tStudent Address : " << &tStudent << endl;
	cout << "tStudent Address : " << pVoid << endl;


	pVoid = &iNumber;

	int* pConvert = (int*)pVoid;
	*pConvert = 1004;
	cout << iNumber << endl;


	*((int*)pVoid) = 10101010;
	cout << iNumber << endl;

	pVoid = &tStudent;


	(*((_tagStudent*)pVoid)).iMath = 1231300;

	cout << tStudent.iMath << endl;
	

	auto Test = 3.14f;

	cout << typeid(Test).name() << endl;

	auto pCon = (_tagStudent*)pVoid;	
	pCon->iKor = 3213;

	return 0;
}