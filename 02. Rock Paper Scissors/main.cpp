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

/*
	복습 방법

	1.	수업시간에 노트필기를 한다.
		노트필기는 수업의 코드 작성 근거를 위주로 쓴다. 만든 이유라던가.

	2.	노트필기'만' 보고 수업 코드를 참고하지 않고 어떻게 만들어야 되는지 생각해본다.

	3.	수업코드를 보지 않고 그렇게 구상한 생각으로만 직접 코드를 작성해본다.

	4.	만약 막히는 상황이 온다면 수업코드를 보고 주석을 직접 더 상세하게 달아본다.

	5.	그렇게 생각을 정리하고 다시 코드를 작성해본다.

	6.	그래도 어렵다면 수업코드를 한번 훑어보고 다시 코드를 작성해본다.

	7.	안보고 스스로 만들 수 있을 때 까지 반복한다.

	8.	도저히 안되면 코드를 참고해가면서 작성해본다. (받아쓰기)
		(반복)
*/