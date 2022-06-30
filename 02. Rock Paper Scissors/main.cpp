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
	// 컴퓨터가 랜덤한 값을 내야하기 때문에 랜덤테이블을 만든다.
	srand(time(NULL));

	// 플레이어와 컴퓨터의 값을 저장할 변수를 만든다.
	int iPlayer, iComputer;

	// 플레이어와 컴퓨터의 이름을 설정
	char strName[NAME_SIZE] = {};
	char EnemyName[NAME_SIZE] = {};

	system("cls");
	cout << "_______ ROCK PAPER SCSISSORS _______" << endl << endl;
	cout << "Player의 이름 : ";
	cin >> strName;

	cout << "상대의 이름 : ";
	cin >> EnemyName;


	// 게임이 종료되지 않도록 무한루프
	while (true)
	{
		system("cls");
		cout << "_______ ROCK PAPER SCSISSORS _______" << endl << endl;
		cout << "1. 가위" << endl;
		cout << "2. 바위" << endl;
		cout << "3. 보" << endl;
		cout << "4. 종료" << endl << endl;

		cout << "메뉴를 선택하세요 : ";

		cin >> iPlayer;

		// 예외처리
		if (iPlayer < SCISSORS || iPlayer > END)
		{
			cout << "잘못된 값을 입력하였습니다." << endl;
			system("pause");
			continue;
		}

		// 종료 예외처리
		else if (iPlayer == END)
			break;

		// 컴퓨터의 값 랜덤하게 설정
		iComputer = rand() % 3 + SCISSORS;

		
		// 각 값에 맞게 출력
		switch (iPlayer)
		{
		case SCISSORS:
			cout << strName << " : 가위" << endl;
			break;
		case ROCK:
			cout << strName << " : 바위" << endl;
			break;
		case PAPER:
			cout << strName << " : 보" << endl;
			break;
		}

		switch (iComputer)
		{
		case SCISSORS:
			cout << EnemyName << " : 가위" << endl;
			break;
		case ROCK:
			cout << EnemyName << " : 바위" << endl;
			break;
		case PAPER:
			cout << EnemyName << " : 보" << endl;
			break;
		}

		// 승부판정
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

	cout << "게임을 종료합니다." << endl;

	return 0;
}
