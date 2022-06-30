#include <iostream>

#define	NAME_SIZE		32

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum DUNGEON_TYPE
{
	DT_NONE,
	DT_CAVE_OF_SLIME,
	DT_FOREST_FAIRY,
	DT_CAVE_OF_BOSS,
	DT_BACK,
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END,
};

struct _tagPlayer
{
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];

	JOB		eJob;

	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;
};

struct _tagMonster
{
	char	strName[NAME_SIZE];

	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;
	int		iGoldMin;
	int		iGoldMax;
};

int main()
{
	srand(time(NULL));

	_tagPlayer	tPlayer = {};

	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "********************  캐릭터  설정  ********************" << endl << endl;
	
	cout << "당신의 이름을 입력해주세요 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;

	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "____________________ CHANWOOL WORLD ____________________" << endl;
		cout << "********************  캐릭터  직업  ********************" << endl << endl;

		cout << "1. 검    사" << endl << endl;
		cout << "2. 궁    수" << endl << endl;
		cout << "3. 마 법 사" << endl << endl << endl << endl;

		cout << "직업을 선택하세요 : ";
		
		cin >> iJob;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
//	tPlayer.eJob = (JOB)iJob;		// c
	tPlayer.eJob = static_cast<JOB>(iJob);	// c++
	
	switch (tPlayer.eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "검    사");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 20;
		tPlayer.iArmorMax = 25;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMPMax = 100;
		tPlayer.iMP = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "궁    수");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMPMax = 200;
		tPlayer.iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "마 법 사");
		tPlayer.iAttackMin = 20;
		tPlayer.iAttackMax = 25;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMPMax = 300;
		tPlayer.iMP = 300;
		break;
	}

	_tagMonster tMonsterArr[DT_BACK - 1] = {};

	// 슬라임
	strcpy_s(tMonsterArr[DT_CAVE_OF_SLIME - 1].strName, "슬라임");
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iAttackMin = 20;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iAttackMax = 30;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iArmorMin = 2;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iArmorMax = 5;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iHP = 100;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iHPMax = 100;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iMP = 10;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iMPMax = 10;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iLevel = 1;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iExp = 1000;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iGoldMin = 500;
	tMonsterArr[DT_CAVE_OF_SLIME - 1].iGoldMax = 1500;

	// 요정
	strcpy_s(tMonsterArr[DT_FOREST_FAIRY - 1].strName, "엘  프");
	tMonsterArr[DT_FOREST_FAIRY - 1].iAttackMin = 80;
	tMonsterArr[DT_FOREST_FAIRY - 1].iAttackMax = 130;
	tMonsterArr[DT_FOREST_FAIRY - 1].iArmorMin = 60;
	tMonsterArr[DT_FOREST_FAIRY - 1].iArmorMax = 90;
	tMonsterArr[DT_FOREST_FAIRY - 1].iHP = 2000;
	tMonsterArr[DT_FOREST_FAIRY - 1].iHPMax = 2000;
	tMonsterArr[DT_FOREST_FAIRY - 1].iMP = 100;
	tMonsterArr[DT_FOREST_FAIRY - 1].iMPMax = 100;
	tMonsterArr[DT_FOREST_FAIRY - 1].iLevel = 5;
	tMonsterArr[DT_FOREST_FAIRY - 1].iExp = 7000;
	tMonsterArr[DT_FOREST_FAIRY - 1].iGoldMin = 600;
	tMonsterArr[DT_FOREST_FAIRY - 1].iGoldMax = 8000;
	
	// 보스
	strcpy_s(tMonsterArr[DT_CAVE_OF_BOSS - 1].strName, "자  쿰");
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iAttackMin = 250;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iAttackMax = 500;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iArmorMin = 200;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iArmorMax = 400;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iHP = 30000;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iHPMax = 30000;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iMP = 20000;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iMPMax = 20000;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iLevel = 10;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iExp = 30000;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iGoldMin = 20000;
	tMonsterArr[DT_CAVE_OF_BOSS - 1].iGoldMax = 50000;

	while (true)
	{
		system("cls");						   
		cout << "____________________ CHANWOOL WORLD ____________________" << endl;
		cout << "********************   마      을   ********************" << endl << endl;
		cout << "1. 마을 밖 던전입구" << endl << endl;
		cout << "2. 야시장 골목길" << endl << endl;
		cout << "3. 인 벤 토 리" << endl << endl;
		cout << "4. 게 임 종 료" << endl << endl << endl << endl;

		cout << "메뉴를 선택하세요 : ";

		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "____________________ CHANWOOL WORLD ____________________" << endl;
				cout << "********************  던전  진입로  ********************" << endl << endl;

				cout << "1. 슬라임의 동굴" << endl << endl;
				cout << "2. 요정의 숲" << endl << endl;
				cout << "3. 보스의 동굴" << endl << endl;
				cout << "4. 마을로 돌아가기" << endl << endl << endl << endl;

				cout << "던전을 선택하세요 : ";

				cin >> iMenu;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == DT_BACK)
					break;

				_tagMonster	tMonster = tMonsterArr[iMenu - 1];

				while (true)
				{
					system("cls");
					cout << "____________________ CHANWOOL WORLD ____________________" << endl;

					switch (iMenu)
					{
					case DT_CAVE_OF_SLIME:
						cout << "******************** 슬라임의  동굴 ********************" << endl << endl;
						break;
					case DT_FOREST_FAIRY:
						cout << "*********************** 요정의숲 ***********************" << endl << endl;
						break;
					case DT_CAVE_OF_BOSS:
						cout << "********************* 보스의  동굴 *********************" << endl << endl;
						break;
					}


				}
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		case MM_EXIT:
			break;
		default:
			cout << "잘못 선택하였습니다." << endl;
			break;
		}

	}

	cout << endl << "게임을 종료합니다." << endl << endl;

	return 0;
}