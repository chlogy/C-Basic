// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

#include <iostream>

using namespace std;

int main()
{
	/*
		���� : ������ ����, Random Number
	*/
	srand((unsigned int)time(0));	// ����� ����ȯ

	float fPie = 3.14f;
	int Number = fPie;		// ����ȯ
	// �Ͻ���, ������ ����ȯ


	printf("%d\n", rand());
	
	// 0 ~ 99 ���� ��� �ʹٸ�?
	cout << rand() % 100 << endl;

	// 0 ~ 100 ���� ��� �ʹٸ�?
	cout << rand() % 101 << endl;

	// 100 ~ 200
	cout << rand() % 101 + 100 << endl;

	// 0 ~ 99.99
	cout << rand() % 10000 / 100.f << endl;


	int iUpgrade;

	cout << "Upgrade �⺻ ��ġ�� �Է��ϼ��� : ";
	cin >> iUpgrade;

	float fPercent = rand() % 10000 / 100.f;

	/*
		��ȭ Ȯ�� : ���׷��̵� ��ġ��
		0 ~ 3 : ������
		4 ~ 6 : 40%
		7 ~ 9 : 10%
		10 ~ 13 : 1%
		14 ~ 15 : 0.01%
	*/

	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "��ȭ ����!!!" << endl;
	
	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "��ȭ ����!!!" << endl;
		else
			cout << "��ȭ ����!!!" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "��ȭ ����!!!" << endl;
		else
			cout << "��ȭ ����!!!" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "��ȭ ����!!!" << endl;
		else
			cout << "��ȭ ����!!!" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.01f)
			cout << "��ȭ ����!!!" << endl;
		else
			cout << "��ȭ ����!!!" << endl;
	}

	return 0;
}