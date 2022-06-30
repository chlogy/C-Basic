#include <iostream>

#include "Func.h"

using namespace std;

int main()
{
	cout << "Hello World\n";	// 이스케이프 문자
	cout << "Hello World\t";
	cout << "Hello World" << endl;
	
	/*
		변수 : 변하는 수. 값이 바뀔 수 있다. (값을 저장하는 공간)

		용량의 최소단위 : bit
		1Byte = 8bit
		1Kbyte = 1024Byte
		1Mbyte = 1024Kbyte
		1Gbyte = 1024Mbyte
		1Tbyte = 1024Gbyte

		종류    |       	    용량(크기)		  |	    데이터	         |		표현 범위	       |		unsigned	      |
		char	|	 	1byte			|	문자		|	   -128 ~ 127		 |		0 ~ 255			|
		bool	|		1byte			|	참/거짓	       |	   true / false		|	  true / false		       |
		short	| 		2byte			|	정수		|	  -32768 ~ 32767	 |		0 ~ 65535		|
		int	|	        4byte			|	정수		|	  약 -21억 ~ 21억	      |		0 ~ 약 42억		    |
		float	|		4byte			|	실수		|
		double	|		8byte			|	실수		|

		대입연산자 : = 오른쪽에 있는 값을 왼쪽 변수에 넣는다. 
	*/
	// lValue , RValue
	int Number = 10;
	Number = 20;
	cout << Number << endl;
	
	bool	bTest = true;
	bTest = false;
	cout << bTest << endl;		// false : 0		true : 0이 아닌 모든 수

	char	cTest = 66;
	cout << cTest << endl;

	return 0;
}
