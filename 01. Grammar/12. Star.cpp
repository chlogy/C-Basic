#include <iostream>

using namespace std;
/*
1. 구구단을 2단부터 9단까지 출력하는 중첩 for문을 만들기

2. 별을 아래의 형태로 출력되게 한다.
*
**
***
****
*****

3. 별을 아래의 형태로 출력되게 한다.
*****
****
***
**
*

4. 별을 아래의 형태로 출력되게 한다.
   *
  ***
 *****
*******
*/
int main()
{
	cout << "1. ===================" << endl;

	for (int i = 1; i <= 9; i++)
	{
		cout << i << "단" << endl;
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << endl;
	}

	cout << endl;
	cout << "2. ===================" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
	cout << "3. ===================" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
	cout << "4. ===================" << endl;

	// 공백 : 3, 2, 1
	// 별 : 1 3 5 7 

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < i * 2 + 1; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;
	cout << "5. ===================" << endl;
	/*
		2단	3단	4단
		5단	6단	7단
		8단	9단	10단
	*/

	for (int i = 2; i < 11; i += 3)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i * j << "\t";
			cout << i + 1 << " * " << j << " = " << (i + 1) * j << "\t";
			cout << i + 2 << " * " << j << " = " << (i + 2) * j << endl;
		}
		cout << endl;
	}


	cout << endl;
	cout << "6. ===================" << endl;
/*
	   *
	  ***
	 *****
	******* 
	 *****
	  ***
	   *
*/

	
	int iLine = 7;
	int iCount = 0;

	cout << "Line을 입력하세요 : ";
	cin >> iLine;
	
	if (iLine % 2 == 0)
		iLine++;

	for (int i = 0; i < iLine; i++)
	{
		// 공백 : 3 2 1 0 1 2 3
		//   별 : 1 3 5 7 5 3 1

		iCount = i;

		if (i > iLine / 2)
			iCount = iLine - 1 - i;

		for (int j = 0; j < iLine - iCount; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < iCount * 2 + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}