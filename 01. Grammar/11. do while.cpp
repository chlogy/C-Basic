#include <iostream>

using namespace std;

int main()
{
	/*
		do while문 : 반복문의 한 종류.
		형태 : do {} while(조건식); 의 형태로 구성된다.

		while문은 처음 진입부터 조건식을 체크하지만 do while은
		처음 한번은 무조건 동작이 되고 그 후에 조건식을 체크해서 
		true일 경우 반복해서 동작되는 반복문이다.
	*/

	int iNumber = 0;

	do 
	{
		cout << iNumber << endl;
	} while (iNumber > 0);




	int iCount = 0;
	while (iCount == 0 || (iNumber > 0))
	{
		iCount++;
		
		cout << iNumber << endl;
	}



	/*
		배열이란 : 여러 개의 변수를 한번에 생성해 줄 수 있는 기능.
		형태 : 변수의 타입 (데이터 타입) 배열명[갯수]; 의 형태

		배열의 특징 : 배열은 연속된 메모리 블럭에 공간이 할당된다.

		배열은 인덱스를 이용해서 원하는 부분에 접근하여 값을 저장할 수 있다.
		인덱스는 0부터 N-1까지다.

		즉. 10개를 저장하려면 인덱스는 0 ~ 9까지의 총 10개의 인덱스를 가지게 된다.
	*/

	// int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	// int iArray[10] = { 1,2,3,4,5 };
	
	int iArray[10] = {};

	for (int i = 0; i < 10; i++)
	{
		cout << iArray[i] << "\t";
	}

	int iArray2[10][10] = { {1,2,3}, {4,5,6} };

	/*
		2차원 배열의 개수는 앞의 수 * 뒤의 수 만큼 처리가 된다.
	*/

	cout << endl << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << iArray2[i][j] << "\t";
		}
		cout << endl << endl;
	}


	return 0;
}