#include <iostream>

#define NUM_4	4

using namespace std;

enum NUM
{
	NUM_0,	// �ƹ��͵� �ο����� ���� ��� 0���� ���ʴ�� 1�� ���� �ο��ȴ�.
	NUM_1,
	NUM_2,
	NUM_3,
};

enum PAPULATUS_STATE
{
	IDLE,
	PATROL,
	TRACE,
	HEAL,
	SKILL_CRUSH,
	BUFF,
	PHASE2,
	DIE,
};

int main()
{
	/*
		switch �� : ���ǹ��� �� ����
		���� : switch(����) {}
		�ڵ�� �ȿ��� case ~ break ������ ����.
		'case ���' : �� ���·� ó���� �ǰ�, ���� ���� ���������� ����
		case �ڿ� ���� ����� ���ϰ� �ȴ�.
	*/

	int iNumber;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iNumber;

	switch (iNumber)
	{
	case NUM_0:
		cout << "�Է�ȯ ���ڴ� 0�Դϴ�." << endl;
		break;
	case NUM_1:
		cout << "�Է��� ���ڴ� 1�Դϴ�." << endl;
		break;
	case NUM_2:
		cout << "�Է��� ���ڴ� 2�Դϴ�." << endl;
		break;
	case NUM_3:
		cout << "�Է��� ���ڴ� 3�Դϴ�." << endl;
		break;
	case NUM_4:
		cout << "�Է��� ���ڴ� 4�Դϴ�." << endl;
		break;
	default:
		cout << "�� ���� �����Դϴ�." << endl;
		break;
	}

	/*
		����ü : ���ӵ� ���ڿ� �̸��� �ο��� �� �ִ� ���.
		���� : enum ����ü�� {}�� ����
	*/
	

	PAPULATUS_STATE		Papulatus = HEAL;

	/*switch (Papulatus)
	{
	case IDLE:
		break;
	case PATROL:
		break;
	case TRACE:
		break;
	case HEAL:
		PlayAnimation(sln\~~~~~'Anim');
		break;
	case SKILL_CRUSH:
		break;
	case BUFF:
		break;
	case PHASE2:
		break;
	case DIE:
		break;
	}*/


	cout << sizeof(PAPULATUS_STATE) << endl;
	cout << typeid(PAPULATUS_STATE).name() << endl;

	return 0;
}