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
	cout << &pText << endl;			// pText�� �ּ�
	cout << (char*)pText << endl;	// Hello Bro
	cout << (int*)pText << endl;	// Hello Bro ��� ���ڿ��� �ּ�
	cout << *pText << endl;			// H
	cout << &pText[0] << endl;		// Hello Bro



	_tagStudent tStudent = {};
	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;
	cout << tStudent.iKor << endl;

	/*
		������ �켱 ���� ������ .�� ���� �ν��ϰ� �ȴ�.
		�޸� �ּ�. �� �߸��� �����̴�.
		�׷��Ƿ� *pStudent �� ��ȣ�� ������ �ڿ� .�� �̿��ؼ� ����Ű�� ����� ��� ������ �����ؾ� �Ѵ�.
	*/
	(*pStudent).iKor = 300;
	cout << tStudent.iKor << endl;

	pStudent->iKor = 1004;
	cout << tStudent.iKor << endl;
	/*
		�޸��ּ� ->�� �̿��ؼ� ����Ű�� ����� ����� ������ �� �ִ�.
	*/


	// void*

	/*
		void :	c++���� void�� �ǹ̴� Ÿ���� ����.
				void* ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ� ��� ������ �����ϴ�.

				��, �������� �Ұ����ϰ� �޸� �ּҸ� ������ �����ϴ�.
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