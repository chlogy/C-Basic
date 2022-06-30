#include <iostream>

#define	NAME_SIZE			32
#define ITEM_DESC_LENGTH	512
#define	INVENTORY_MAX		10

#define STORE_WEAPON_MAX	6
#define STORE_ARMOR_MAX		6

using namespace std;

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK,
};

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

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK,
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK,
};

struct _tagItem
{
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	char	strDesc[ITEM_DESC_LENGTH];

	ITEM_TYPE	eType;

	int		iMin;
	int		iMax;
	int		iPrice;
	int		iSell;
};

struct _tagInventory
{
	int		iGold;
	int		iItemCount;

	_tagItem	tItem[INVENTORY_MAX];
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

	_tagInventory	tInventory;
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


	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_ARMOR_MAX] = {};
	// todo


	while (true)
	{
		system("cls");
		cout << "____________________ CHANWOOL WORLD ____________________" << endl;
		cout << "********************   마 을 광 장   ********************" << endl << endl;
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
					
					cout << "********************* ＰＬＡＹＥＲ *********************" << endl << endl;
					cout << "이  름 : " << tPlayer.strName << "\t\t\t직  업 : " << tPlayer.strJobName << endl;
					cout << "레  벨 : " << tPlayer.iLevel << "\t\t\t경험치 : " << tPlayer.iExp << endl;
					cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax
						<< "\t\t방어력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					cout << "체  력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax
						<< "\t\t마  력 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

					cout << "소지금 : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;


					cout << "******************** ＭＯＮＳＴＥＲ ********************" << endl << endl;
					cout << "이  름 : " << tMonster.strName << "\t\t\t레  벨 : " << tMonster.iLevel << endl;
					cout << "공격력 : " << tMonster.iAttackMin << " - " << tMonster.iAttackMax
						<< "\t\t방어력 : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
					cout << "체  력 : " << tMonster.iHP << " / " << tMonster.iHPMax
						<< "\t\t마  력 : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;

					cout << "드랍 경험치 : " << tMonster.iExp
						<< "\t\t드랍 골드 : " << tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl << endl << endl;

					
					cout << "1. 공격하기" << endl;
					cout << "2. 도망가기" << endl << endl;
					
					cout << "행동을 선택하세요 : ";

					cin >> iMenu;
					
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu)
					{
					case BATTLE_ATTACK:
						// Min 5
						// Max 15
						
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;

						int iDamage = iAttack - iArmor;

						// 삼항연산자 : 조건식 ? true값 : false값

						iDamage = iDamage < 1 ? 1 : iDamage;

						/*if (iDamage < 1)
							iDamage = 1;*/

						tMonster.iHP -= iDamage;

						cout << endl << tPlayer.strName << "이(가) " << tMonster.strName << "에게 " << iDamage << " 피해를 입혔습니다." << endl;

						// 몬스터가 사망했을 경우
						if (tMonster.iHP <= 0)
						{
							cout << endl<< tMonster.strName << " 몬스터가 사망하였습니다." << endl << endl;

							tPlayer.iExp += tMonster.iExp;

							int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " Exp 경험치를 획득하였습니다." << endl;
							cout << iGold << " Gold를 획득하였습니다." << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							cout << endl;
							system("pause");
							break;
						}

						// 몬스터가 살아있을 경우
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;

						iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						// Player의 HP를 감소시킨다.
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << "이(가) " << tPlayer.strName << "에게 " << iDamage << " 피해를 입혔습니다." << endl << endl;

						// 플레이어 사망시
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << "이(가) 사망하였습니다." << endl << endl;

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " Exp 경험치를 잃었습니다." << endl;
							cout << iGold << " Gold를 잃었습니다." << endl;

							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}

						cout << endl;
						system("pause");


						break;
					}
				}
			}
			break;
		case MM_STORE:
			while (true)
			{
				system("cls");
				cout << "____________________ CHANWOOL WORLD ____________________" << endl;
				cout << "*****************  어두운 시장 뒷골목  *****************" << endl << endl;

				cout << "1. 떡쇠네 대장간" << endl;
				cout << "2. 왈숙네 갑옷점" << endl;
				cout << "3. 마을 광장으로 돌아가기" << endl << endl;

				cout << "상점을 선택하세요 : ";

				cin >> iMenu;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (iMenu == SM_BACK)
					break;

				switch (iMenu)
				{
				case SM_WEAPON:
					// todo

					break;

				case SM_ARMOR:
					break;
				}
				
			}
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