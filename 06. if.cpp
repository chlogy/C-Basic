#include <iostream>

using namespace std;

int main()
{
	/*
		제어문 : 조건문, 반복문, 분기문

		조건문 : if, else if , else , switch ~ case
		반복문 : for, while, do while
		분기문 : break, continue, goto

		분기문 : 프로그램의 순차적 수행 순서에 따르지 않고, 다른 명령을 수행하도록 이행시키는 명령
	*/

	/*
		if문 : 조건을 체크해주는 기능
		형태 : if(조건식) {} <- 코드블럭
	*/

	const int	iAttack = 0x00000001;		//	    1
	const int	iArmor = 0x00000002;		//	   10
	const int	iHP = 0x00000004;			//	  100
	const int	iMP = 0x00000008;			//	 1000
	const int	iCritical = 0x00000010;		//	10000

	int iBuf = iAttack | iHP | iCritical;

	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack 버프가 있습니다." << endl;
	}

	if ((iBuf & iHP))
	{
		cout << "HP 버프가 있습니다." << endl;
	}



	if ((iBuf & iMP))
	{
		cout << "MP 버프가 있습니다." << endl;
	}
	else
	{
		if ((iBuf & iCritical))
		{
			cout << "Critical 버프가 있습니다." << endl;
		}
		else
		{
			cout << "버프가 없습니다." << endl;
		}		
	}

	if ((iBuf & iMP))
	{
		cout << "MP 버프가 있습니다." << endl;
	}
	else if ((iBuf & iCritical))
	{
		cout << "Critical 버프가 있습니다." << endl;
	}
	else
	{
		cout << "버프가 없습니다." << endl;		
	}


	int iNumber;
	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	if (iNumber >= 10 && iNumber <= 20)
		cout << "10 ~ 20 사이의 숫자입니다." << endl;

	else if (21 <= iNumber && iNumber <= 30)
		cout << "21 ~ 30 사이의 숫자입니다." << endl;

	else
		cout << "그 외의 숫자입니다." << endl;


	return 0;
}