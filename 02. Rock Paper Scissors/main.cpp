#include <iostream>
#define	NAME_SIZE		32

using namespace std;

enum ROCK_PARPER_SCISSORS
{
	SCISSORS = 1,
	ROCK,
	PAPER,
	END
};

int main()
{
	// ��ǻ�Ͱ� ������ ���� �����ϱ� ������ �������̺��� �����.
	srand(time(NULL));

	// �÷��̾�� ��ǻ���� ���� ������ ������ �����.
	int iPlayer, iComputer;

	// �÷��̾�� ��ǻ���� �̸��� ����
	char strName[NAME_SIZE] = {};
	char EnemyName[NAME_SIZE] = {};

	system("cls");
	cout << "_______ ROCK PAPER SCSISSORS _______" << endl << endl;
	cout << "Player�� �̸� : ";
	cin >> strName;

	cout << "����� �̸� : ";
	cin >> EnemyName;


	// ������ ������� �ʵ��� ���ѷ���
	while (true)
	{
		system("cls");
		cout << "_______ ROCK PAPER SCSISSORS _______" << endl << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "4. ����" << endl << endl;

		cout << "�޴��� �����ϼ��� : ";

		cin >> iPlayer;

		// ����ó��
		if (iPlayer < SCISSORS || iPlayer > END)
		{
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			system("pause");
			continue;
		}

		// ���� ����ó��
		else if (iPlayer == END)
			break;

		// ��ǻ���� �� �����ϰ� ����
		iComputer = rand() % 3 + SCISSORS;

		
		// �� ���� �°� ���
		switch (iPlayer)
		{
		case SCISSORS:
			cout << strName << " : ����" << endl;
			break;
		case ROCK:
			cout << strName << " : ����" << endl;
			break;
		case PAPER:
			cout << strName << " : ��" << endl;
			break;
		}

		switch (iComputer)
		{
		case SCISSORS:
			cout << EnemyName << " : ����" << endl;
			break;
		case ROCK:
			cout << EnemyName << " : ����" << endl;
			break;
		case PAPER:
			cout << EnemyName << " : ��" << endl;
			break;
		}

		// �º�����
		int iWin = iPlayer - iComputer;

		cout << "______________ Result ______________" << endl << endl;

		/*if (iWin == 1 || iWin == -2)
			cout << strName << " WIN !!!!" << endl;

		else if (iWin == 0)
			cout << "DRAW !!!!" << endl;

		else
			cout << strName << " LOSE !!!!" << endl;*/

		switch (iWin)
		{
		case 1:
		case -2:
			cout << strName << " WIN !!!!" << endl;
			break;
		case 0:
			cout << "DRAW !!!!" << endl;
			break;
		default:
			cout << strName << " LOSE !!!!" << endl;
			break;
		}

		system("pause");
	}

	cout << "������ �����մϴ�." << endl;

	return 0;
}

/*
	���� ���

	1.	�����ð��� ��Ʈ�ʱ⸦ �Ѵ�.
		��Ʈ�ʱ�� ������ �ڵ� �ۼ� �ٰŸ� ���ַ� ����. ���� ���������.

	2.	��Ʈ�ʱ�'��' ���� ���� �ڵ带 �������� �ʰ� ��� ������ �Ǵ��� �����غ���.

	3.	�����ڵ带 ���� �ʰ� �׷��� ������ �������θ� ���� �ڵ带 �ۼ��غ���.

	4.	���� ������ ��Ȳ�� �´ٸ� �����ڵ带 ���� �ּ��� ���� �� ���ϰ� �޾ƺ���.

	5.	�׷��� ������ �����ϰ� �ٽ� �ڵ带 �ۼ��غ���.

	6.	�׷��� ��ƴٸ� �����ڵ带 �ѹ� �Ⱦ�� �ٽ� �ڵ带 �ۼ��غ���.

	7.	�Ⱥ��� ������ ���� �� ���� �� ���� �ݺ��Ѵ�.

	8.	������ �ȵǸ� �ڵ带 �����ذ��鼭 �ۼ��غ���. (�޾ƾ���)
		(�ݺ�)
*/