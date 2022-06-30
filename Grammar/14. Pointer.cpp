#include <iostream>

using namespace std;

int main()
{
	/*
		Pointer :	가리키다. 일반 변수는 일반적인 값을 저장하지만, 포인터 변수는 메모리 주소를 저장하게 된다.
					모든 변수 타입은 포인터 타입으로 선언할 수 있다.

					int 변수의 주소는 int Pointer 변수에 저장을 해야한다.
					포인터는 메모리 주소를 담아놓는 변수이기 때문에 메모리 주소는 x86 (32비트), x64(64비트)로 개발이 되는데
					
					각각 x86으로 개발을 할 때에는 4byte
					x64로 개발할 때는 8byte가 나온다.

					포인터는 자기 스스로 아무런 일도 할 수 없다.
					반드시 다른 변수의 메모리 주소를 가지고 있어야 일을 할 수 있는데 가지고 있는 그 메모리 주소에 접근해서 값을 제어할 수 있다.

		형태 : 변수타입 * 변수명; 의 형태로 선언한다.
	*/

	int iNumber = 100;

	/*
		변수 선언시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다.
		변수 앞에 &를 붙여주면 해당 변수의 메모리 주소가 된다.
		pNum은 iNumber 변수의 메모리 주소를 값으로 갖게 된다.
		그러므로 pNum을 이용해서 iNumber의 값을 제어할 수 있다.
	*/
	int* pNum = &iNumber;
	
	cout << sizeof(int*) << endl;		// 4
	cout << sizeof(char*) << endl;		// 4
	cout << sizeof(double) << endl;		// 8
	cout << sizeof(double*) << endl;	// 4

	/*
		16비트 : 65536
		32비트 : 4,294,967,296
		64비트 : 1800경 ↑
	*/
	
	*pNum = 300;

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Address : " << &pNum << endl;

	/*
		pNum을 이용해서 iNumber의 값을 제어해보자.
		역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
		역참조는 포인터 변수 앞에 *을 붙이게 되면 역참조가 된다.
	*/

	/*
		특수한 포인터 : 이중포인터, char*, void*, func*

		포인터와 배열의 관계 : 배열명은 포인터이다.
	*/
	int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int* pArray = iArray;

	cout << "iArray Address : " << iArray << endl;
	cout << "Arr[0] Address : " << &iArray[0] << endl;	
	cout << "Array ptr Data : " << pArray << endl;

	cout << "iArray 로 접근 : " << iArray[2] << endl;
	cout << "pArray 로 접근 : " << pArray[2] << endl;

	/*
		포인터 연산 : +, - 연산을 제공한다. 그렇기 때문에 ++, -- 같은 증감도 가능하다.
					 1이 증가하게 되면 단순히 메모리 주소값이 1증가 하는 것이 아니다.
					 int Pointer의 경우 int Type의 메모리 주소를 갖게되는데, 메모리 주소에 1을 더해주면
					 1 증가가 아닌 가리키는 해당 포인터가 가리키는 변수 타입의 크기만큼 증가하게 된다.
					 int Pointer는 int의 크기만큼 4만큼 값이 증가하게 된다.
	*/

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;


	return 0;
}