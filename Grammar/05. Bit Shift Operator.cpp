#include <iostream>

using namespace std;

int main()
{
	/*
		상수 : 변하지 않는 수. 값을 한번 지정해놓으면 바꿀 수 없다.

		상수는 선언과 동시에 값을 지정해두어야 한다. (초기화)

		0x를 붙이면 16진수를 표현

		4Byte : 8bit * 4
	*/

	const int	iAttack = 0x00000001;		//	    1
	const int	iArmor = 0x00000002;		//	   10
	const int	iHP = 0x00000004;			//	  100
	const int	iMP = 0x00000008;			//	 1000
	const int	iCritical = 0x00000010;		//	10000

	int iBuf = iAttack | iHP | iCritical;
//	00001
//	00100
//	10000

//	10101

	iBuf ^= iHP;
	iBuf ^= iHP;

	cout << "Attack : " << (iBuf & iAttack) << endl;
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << "HP : " << (iBuf & iHP) << endl;
	cout << "MP : " << (iBuf & iMP) << endl;
	cout << "Critical : " << (iBuf & iCritical) << endl;
	/*
		연사자 축약형 : 연산자를 줄여서 사용할 수 있다.
		iNumber = iNumber + 20;
		iNumber += 20;
	*/

	/*
		쉬프트 연산자 : << >> 를 사용하여 값 대 값으로 연산하여 값으로 나오게 한다.

		int Value = 10;
		00000000000000000000000000001010

		<<
		00000000000000000000000000101000

		>>
		00000000000000000000000000000010
	*/

	int iNumber = 10;
	cout << iNumber << endl;
	iNumber <<= 2;

	cout << iNumber << endl;

	
	int iHigh = 187;
	int iLow = 13560;
	
	cout << iHigh << endl;
	cout << iLow << endl;

	int Value;
	Value = 187;

	Value <<= 16;
	Value |= 13560;

	cout << "High : " << (Value >> 16) << endl;
	cout << "Low : " << (Value & 0x0000ffff) << endl;

	/*
		증감연산자 : ++ --가 있다. 1증가, 1감소
	*/
	iNumber = 10;

	// 전위연산자, 전치
	++iNumber;

	// 후위연산자, 후치
	iNumber++;

	cout << iNumber << endl;	// 12

	cout << ++iNumber << endl;	// 13
	cout << iNumber++ << endl;	// 13
	cout << iNumber << endl;	// 14



	return 0;
}