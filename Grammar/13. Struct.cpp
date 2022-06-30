#include <iostream>

#define		NAME_SIZE		32
using namespace std;

/*
	구조체 : 관련 있는 변수들을 모아서 하나의 새로운 자료형을 만들어주는 기능이다.
	사용자 정의 자료형이다.
	형태 : struct 구조체명 {};
*/

struct _tagStudent
{
	char	strName[NAME_SIZE];

	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAverage;
};

int main()
{
	_tagStudent	tStudent;
	
	/*
		구조체와 배열의 공통점 :

		1. 데이터 집합이다.
		2. 물리적인 메모리 구조로 봤을 때 연속된 메모리 블럭을 갖고 있다.
	*/

	_tagStudent tStudentArr[100] = {};

	/*
		구조체 멤버에 접근할 때는 . 을 이용해서 접근하게 된다.
	*/

	tStudent.iKor = 100;

//	tStudent.strName = "Hello World";
	/*
		문자열을 배열에 넣어줄 때는 단순 대입으로는 불가능하다.
		strcpy_s라는 함수를 이용해서 문자열을 복사해 주어야 한다.
		이 함수는 오른쪽에 있는 문자열을 왼쪽으로 복사해준다.
	*/
	// strcpy_s(tStudent.strName, "학생이름");

	/*tStudent.strName[0] = 'a';
	tStudent.strName[1] = 'p';
	tStudent.strName[2] = 'p';
	tStudent.strName[3] = 'l';
	tStudent.strName[4] = 'e';
	tStudent.strName[5] = '\0';*/

	/*
		문자열의 끝은 항상 0(NULL)로 끝나야 한다.
		쓰레기 값이 들어가 있는 상태에서 지금처럼 각 배열 요소에 값을 넣어주게 되면,
		그 값이 그대로 출력되고 넣어주지 않은 부분은 쓰레기 값으로 그대로 출력된다.
		왜냐하면 출력할 때 문자열의 끝을 인식할 수 없기 때문이다.
		0이 들어가야 하는데 쓰레기 값이 들어가있기 때문에다.
	*/
	// NULL, 0, false, '\0'		모두 NULL을 의미

	strcpy_s(tStudent.strName, "가나다라 apple");	// 문자열의 길이, 크기, 바이트 14
	cout << "이름 길이 : " << strlen(tStudent.strName) << endl;

	/*
		strcat_s : 함수는 문자열을 붙여주는 기능이다.
		오른쪽에 있는 문자열을 왼쪽에 붙여준다.
		strName에는 현재 위에서 가나다라 apple를 저장해두었기 때문에 
		이 뒤에 오른쪽 문자열을 붙여서 만들어준다.
	*/

	strcat_s(tStudent.strName, "문자열을 붙이기");

	/*
		strcmp 함수는 두 문자열을 비교하여 같을 경우 0을 반환하고, 다를 경우 0이 아닌 값을 반환.
	*/
	
	strcpy_s(tStudent.strName, "홍길동");

	cout << "비교할 이름을 입력하세요 : ";

	char strName[NAME_SIZE] = {};
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
		cout << "학생을 찾았습니다." << endl;

	else
		cout << "찾는 학생이 없습니다." << endl;



	cout << "이 름 : " << tStudent.strName << endl;
	cout << "학 번 : " << tStudent.iNumber << endl;
	cout << "국 어 : " << tStudent.iKor << endl;
	cout << "영 어 : " << tStudent.iEng << endl;
	cout << "수 학 : " << tStudent.iMath << endl;
	cout << "총 점 : " << tStudent.iTotal << endl;
	cout << "평 균 : " << tStudent.fAverage << endl;


	return 0;
}