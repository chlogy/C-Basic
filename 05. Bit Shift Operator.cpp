#include <iostream>

using namespace std;

int main()
{
	/*
		��� : ������ �ʴ� ��. ���� �ѹ� �����س����� �ٲ� �� ����.

		����� ����� ���ÿ� ���� �����صξ�� �Ѵ�. (�ʱ�ȭ)

		0x�� ���̸� 16������ ǥ��

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
		������ ����� : �����ڸ� �ٿ��� ����� �� �ִ�.
		iNumber = iNumber + 20;
		iNumber += 20;
	*/

	/*
		����Ʈ ������ : << >> �� ����Ͽ� �� �� ������ �����Ͽ� ������ ������ �Ѵ�.

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
		���������� : ++ --�� �ִ�. 1����, 1����
	*/
	iNumber = 10;

	// ����������, ��ġ
	++iNumber;

	// ����������, ��ġ
	iNumber++;

	cout << iNumber << endl;	// 12

	cout << ++iNumber << endl;	// 13
	cout << iNumber++ << endl;	// 13
	cout << iNumber << endl;	// 14



	return 0;
}