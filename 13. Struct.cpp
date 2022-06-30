#include <iostream>

#define		NAME_SIZE		32
using namespace std;

/*
	����ü : ���� �ִ� �������� ��Ƽ� �ϳ��� ���ο� �ڷ����� ������ִ� ����̴�.
	����� ���� �ڷ����̴�.
	���� : struct ����ü�� {};
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
		����ü�� �迭�� ������ :

		1. ������ �����̴�.
		2. �������� �޸� ������ ���� �� ���ӵ� �޸� ���� ���� �ִ�.
	*/

	_tagStudent tStudentArr[100] = {};

	/*
		����ü ����� ������ ���� . �� �̿��ؼ� �����ϰ� �ȴ�.
	*/

	tStudent.iKor = 100;

//	tStudent.strName = "Hello World";
	/*
		���ڿ��� �迭�� �־��� ���� �ܼ� �������δ� �Ұ����ϴ�.
		strcpy_s��� �Լ��� �̿��ؼ� ���ڿ��� ������ �־�� �Ѵ�.
		�� �Լ��� �����ʿ� �ִ� ���ڿ��� �������� �������ش�.
	*/
	// strcpy_s(tStudent.strName, "�л��̸�");

	/*tStudent.strName[0] = 'a';
	tStudent.strName[1] = 'p';
	tStudent.strName[2] = 'p';
	tStudent.strName[3] = 'l';
	tStudent.strName[4] = 'e';
	tStudent.strName[5] = '\0';*/

	/*
		���ڿ��� ���� �׻� 0(NULL)�� ������ �Ѵ�.
		������ ���� �� �ִ� ���¿��� ����ó�� �� �迭 ��ҿ� ���� �־��ְ� �Ǹ�,
		�� ���� �״�� ��µǰ� �־����� ���� �κ��� ������ ������ �״�� ��µȴ�.
		�ֳ��ϸ� ����� �� ���ڿ��� ���� �ν��� �� ���� �����̴�.
		0�� ���� �ϴµ� ������ ���� ���ֱ� ��������.
	*/
	// NULL, 0, false, '\0'		��� NULL�� �ǹ�

	strcpy_s(tStudent.strName, "�����ٶ� apple");	// ���ڿ��� ����, ũ��, ����Ʈ 14
	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	/*
		strcat_s : �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
		�����ʿ� �ִ� ���ڿ��� ���ʿ� �ٿ��ش�.
		strName���� ���� ������ �����ٶ� apple�� �����صξ��� ������ 
		�� �ڿ� ������ ���ڿ��� �ٿ��� ������ش�.
	*/

	strcat_s(tStudent.strName, "���ڿ��� ���̱�");

	/*
		strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�ϰ�, �ٸ� ��� 0�� �ƴ� ���� ��ȯ.
	*/
	
	strcpy_s(tStudent.strName, "ȫ�浿");

	cout << "���� �̸��� �Է��ϼ��� : ";

	char strName[NAME_SIZE] = {};
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
		cout << "�л��� ã�ҽ��ϴ�." << endl;

	else
		cout << "ã�� �л��� �����ϴ�." << endl;



	cout << "�� �� : " << tStudent.strName << endl;
	cout << "�� �� : " << tStudent.iNumber << endl;
	cout << "�� �� : " << tStudent.iKor << endl;
	cout << "�� �� : " << tStudent.iEng << endl;
	cout << "�� �� : " << tStudent.iMath << endl;
	cout << "�� �� : " << tStudent.iTotal << endl;
	cout << "�� �� : " << tStudent.fAverage << endl;


	return 0;
}