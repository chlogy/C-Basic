#include <iostream>

using namespace std;

/*
	함수 :	기능을 만들어준다.	일종의 사용할 수 있는 기능을 만들어준다고 볼 수 있다.
			특정 상황에 내가 원하는 기능을 수행하도록 동작하는 코드를 만드는 것이다.

	형태 :	리턴타입 함수명(매개변수 == parameter == 인자) {}의 형태로 구성이 된다.
	
	리턴타입 :	이 해당 함수가 의도한 기능을 수행하고 그에 따른 결과를 반환해야 할 때 그 데이터 타입에 맞도록 지정해준다.			
				정수를 반환해야할 때는 int Type, 실수를 반환해야 할 때는 float, double 등과 같은 내가 필요한 데이터 타입에 맞게 지정해준다.

	함수명 :	함수의 이름을 의미한다.
			함수의 이름을 지을 때에는 이 함수가 하는 일을 명확하게 표기해 주는 것이 좋다.

	매개변수, 파라미터 :	해당 함수를 사용할 때 넘겨줄 값이 있는 경우 파라미터를 활용한다.

	해당 함수를 호출하면 코드블럭 안에 있는 코드가 동작된다.
*/

int Sum(int x, int y)
{
	cout << x + y << endl;
	return x + y;
}

void OutputText()
{
	cout << "Hello World" << endl;
}

void __Print(const char* _Text)
{
	cout << _Text << endl;
}

void ChangeNumber(int iNumber)		// Call by Value
{
	iNumber = 9999;
}

int ChangeNumber3(int iNumber)	// Call by Value
{
	iNumber = 9999;

	return iNumber;
}

void ChangeNumber(int* pNumber)	// Call by Address
{
	*pNumber = 9999;
}

void Output(int iNum1, int iNum2 = 30)
{
	cout << iNum1 << endl;
	cout << iNum2 << endl;
}

void Output(int iNum1)
{
	cout << iNum1 << endl;
}



int main()
{
	// 함수를 호출할 때는 함수명(매개변수); 의 형태로 호출하게 된다.

	cout << Sum(10, 20) << endl;

	Sum(20, 40);

	OutputText();

	__Print("찬울이 안녕");

	int iNumber = 0;
	iNumber = ChangeNumber3(iNumber);
	// ChangeNumber2(&iNumber);
	
	
	ChangeNumber(&iNumber);
	cout << iNumber << endl;

	/*
		함수 오버로딩 : 같은 이름의 함수를 기능이 다른 함수로 재정의해서 만드는 것.

		오버로딩의 조건 : 인자의 개수 혹은 타입이 달라야 오버로딩이 성립된다.
						 중요한 것 : return type은 영향을 받지 않는다.
	*/

	/*
		함수의 디폴트 인자 :	파라미터는 기본적으로 값을 넘겨받게 설계되어 있다.
							그런데 인자에 기본값을 대입해두면 인자를 넘겨주지 않을 경우 기본 설정한 값이 되고,
							인자를 넘겨준 경우 넘겨받은 값으로 인자를 설정하는 기능이다.

							디폴트 인자는 가장 오른쪽부터 넘겨줘야 한다.

	*/

	Output(10, 20);
	// Output(10);

	return 0;
}