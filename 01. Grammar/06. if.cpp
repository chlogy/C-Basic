#include <iostream>

using namespace std;

int main()
{
	/*
		��� : ���ǹ�, �ݺ���, �б⹮

		���ǹ� : if, else if , else , switch ~ case
		�ݺ��� : for, while, do while
		�б⹮ : break, continue, goto

		�б⹮ : ���α׷��� ������ ���� ������ ������ �ʰ�, �ٸ� ����� �����ϵ��� �����Ű�� ���
	*/

	/*
		if�� : ������ üũ���ִ� ���
		���� : if(���ǽ�) {} <- �ڵ��
	*/

	const int	iAttack = 0x00000001;		//	    1
	const int	iArmor = 0x00000002;		//	   10
	const int	iHP = 0x00000004;			//	  100
	const int	iMP = 0x00000008;			//	 1000
	const int	iCritical = 0x00000010;		//	10000

	int iBuf = iAttack | iHP | iCritical;

	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack ������ �ֽ��ϴ�." << endl;
	}

	if ((iBuf & iHP))
	{
		cout << "HP ������ �ֽ��ϴ�." << endl;
	}



	if ((iBuf & iMP))
	{
		cout << "MP ������ �ֽ��ϴ�." << endl;
	}
	else
	{
		if ((iBuf & iCritical))
		{
			cout << "Critical ������ �ֽ��ϴ�." << endl;
		}
		else
		{
			cout << "������ �����ϴ�." << endl;
		}		
	}

	if ((iBuf & iMP))
	{
		cout << "MP ������ �ֽ��ϴ�." << endl;
	}
	else if ((iBuf & iCritical))
	{
		cout << "Critical ������ �ֽ��ϴ�." << endl;
	}
	else
	{
		cout << "������ �����ϴ�." << endl;		
	}


	int iNumber;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iNumber;

	if (iNumber >= 10 && iNumber <= 20)
		cout << "10 ~ 20 ������ �����Դϴ�." << endl;

	else if (21 <= iNumber && iNumber <= 30)
		cout << "21 ~ 30 ������ �����Դϴ�." << endl;

	else
		cout << "�� ���� �����Դϴ�." << endl;


	return 0;
}