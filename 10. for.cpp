#include <iostream>

using namespace std;
int main()
{
	/*
		for문 : 반복문의 한 종류.
		형태 : for(초기식; 조건식; 증감식) {} 의 형태로 구성이 되어있다.
		조건식이 true면 코드블럭의 코드가 동작된다.
	*/

	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}

	for (int i = 1; i < 10; i++)
	{
		cout << "2 * " << i << " = " << 2 * i << endl;
	}

	// 1 ~ 100 사이의 숫자 중 짝수만 출력하는 for문을 작성해봅시다.
	// 단 if문은 쓰지 않고 순수 for문으로만 
	for (int i = 2; i <= 100; i += 2)
	{
		cout << i << endl;
	}
	
	
	// i값이 3과 7의 공배수일 경우멘 출력할 수 있도록 if문을 작성해봅시다.
	for (int i = 1; i <= 100; i++)
	{
		if ((i % 3 == 0) && (i % 7 == 0))
			cout << i << endl;
	}


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "i = " << i << "\t" << "j = " << j << endl;
		}
		cout << endl;
	}

	return 0;
}

/*
	숙제

	5 * 5
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

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