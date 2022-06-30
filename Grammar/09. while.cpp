#include <iostream>

using namespace std;

int main()
{
	/*
		while : 반복문의 한 종류이다.
		형태 : while(조건식) {}
	*/

	int iNumber = 0;

	while (iNumber < 10)
	{
		cout << iNumber << endl;
		++iNumber;

		if (iNumber == 4)
			break;
	}

	return 0;
}