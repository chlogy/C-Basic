// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

#include <iostream>

using namespace std;

int main()
{
	/*
		난수 : 무작위 숫자, Random Number
	*/
	srand((unsigned int)time(0));	// 명시적 형변환

	float fPie = 3.14f;
	int Number = fPie;		// 형변환
	// 암시적, 묵시적 형변환


	printf("%d\n", rand());
	
	// 0 ~ 99 값을 얻고 싶다면?
	cout << rand() % 100 << endl;

	// 0 ~ 100 값을 얻고 싶다면?
	cout << rand() % 101 << endl;

	// 100 ~ 200
	cout << rand() % 101 + 100 << endl;

	// 0 ~ 99.99
	cout << rand() % 10000 / 100.f << endl;


	int iUpgrade;

	cout << "Upgrade 기본 수치를 입력하세요 : ";
	cin >> iUpgrade;

	float fPercent = rand() % 10000 / 100.f;

	/*
		강화 확률 : 업그레이드 수치가
		0 ~ 3 : 무조건
		4 ~ 6 : 40%
		7 ~ 9 : 10%
		10 ~ 13 : 1%
		14 ~ 15 : 0.01%
	*/

	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "강화 성공!!!" << endl;
	
	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "강화 성공!!!" << endl;
		else
			cout << "강화 실패!!!" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "강화 성공!!!" << endl;
		else
			cout << "강화 실패!!!" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "강화 성공!!!" << endl;
		else
			cout << "강화 실패!!!" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.01f)
			cout << "강화 성공!!!" << endl;
		else
			cout << "강화 실패!!!" << endl;
	}

	return 0;
}