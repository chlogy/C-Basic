#include <iostream>

using namespace std;

int main()
{
	/*
		while : �ݺ����� �� �����̴�.
		���� : while(���ǽ�) {}
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