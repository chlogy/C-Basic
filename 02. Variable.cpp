#include <iostream>

#include "Func.h"

using namespace std;

int main()
{
	cout << "Hello World\n";	// �̽������� ����
	cout << "Hello World\t";
	cout << "Hello World" << endl;
	
	/*
		���� : ���ϴ� ��. ���� �ٲ� �� �ִ�. (���� �����ϴ� ����)

		�뷮�� �ּҴ��� : bit
		1Byte = 8bit
		1Kbyte = 1024Byte
		1Mbyte = 1024Kbyte
		1Gbyte = 1024Mbyte
		1Tbyte = 1024Gbyte

		����		|		�뷮(ũ��)		|	������	|		ǥ�� ����		|		unsigned		|
		char	|		1byte			|	����		|	   -128 ~ 127		|		0 ~ 255			|
		bool	|		1byte			|	��/����	|	   true / false		|	  true / false		|
		short	|		2byte			|	����		|	  -32768 ~ 32767	|		0 ~ 65535		|
		int		|		4byte			|	����		|	  �� -21�� ~ 21��	|		0 ~ �� 42��		|
		float	|		4byte			|	�Ǽ�		|
		double	|		8byte			|	�Ǽ�		|

		���Կ����� : = �����ʿ� �ִ� ���� ���� ������ �ִ´�. 
	*/
	// lValue , RValue
	int Number = 10;
	Number = 20;
	cout << Number << endl;
	
	bool	bTest = true;
	bTest = false;
	cout << bTest << endl;		// false : 0		true : 0�� �ƴ� ��� ��

	char	cTest = 66;
	cout << cTest << endl;

	return 0;
}
