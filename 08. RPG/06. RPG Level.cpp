#include <iostream>

#define	NAME_SIZE			32
#define ITEM_DESC_LENGTH	512
#define	INVENTORY_MAX		10

#define STORE_WEAPON_MAX	6
#define STORE_ARMOR_MAX		6

#define LEVEL_MAX			10

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

enum EQUIP
{
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX,
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

	_tagItem		tEquip[EQ_MAX];
	bool			bEquip[EQ_MAX];
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

struct _tagLevelUpStatus
{
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;

	int iHPMin;
	int iHPMax;
	int iMPMin;
	int iMPMax;
};

int main()
{
	srand(time(NULL));

	// 레벨업에 필요한 경험치 목록을 만든다.
	const int iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };

	_tagLevelUpStatus	tLvUpTable[JOB_END - 1] = {};

	tLvUpTable[JOB_KNIGHT - 1].iAttackMin = 10;
	tLvUpTable[JOB_KNIGHT - 1].iAttackMax = 15;
	tLvUpTable[JOB_KNIGHT - 1].iArmorMin = 15;
	tLvUpTable[JOB_KNIGHT - 1].iArmorMax = 25;
	tLvUpTable[JOB_KNIGHT - 1].iHPMin = 50;
	tLvUpTable[JOB_KNIGHT - 1].iHPMax = 100;
	tLvUpTable[JOB_KNIGHT - 1].iMPMin = 10;
	tLvUpTable[JOB_KNIGHT - 1].iMPMax = 20;

	tLvUpTable[JOB_ARCHER - 1].iAttackMin = 20;
	tLvUpTable[JOB_ARCHER - 1].iAttackMax = 25;
	tLvUpTable[JOB_ARCHER - 1].iArmorMin = 10;
	tLvUpTable[JOB_ARCHER - 1].iArmorMax = 15;
	tLvUpTable[JOB_ARCHER - 1].iHPMin = 30;
	tLvUpTable[JOB_ARCHER - 1].iHPMax = 60;
	tLvUpTable[JOB_ARCHER - 1].iMPMin = 30;
	tLvUpTable[JOB_ARCHER - 1].iMPMax = 50;

	tLvUpTable[JOB_WIZARD - 1].iAttackMin = 30;
	tLvUpTable[JOB_WIZARD - 1].iAttackMax = 45;
	tLvUpTable[JOB_WIZARD - 1].iArmorMin = 2;
	tLvUpTable[JOB_WIZARD - 1].iArmorMax = 5;
	tLvUpTable[JOB_WIZARD - 1].iHPMin = 20;
	tLvUpTable[JOB_WIZARD - 1].iHPMax = 40;
	tLvUpTable[JOB_WIZARD - 1].iMPMin = 50;
	tLvUpTable[JOB_WIZARD - 1].iMPMax = 90;



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
	tPlayer.tInventory.iGold = 300000;

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

	// 무기 정보 세팅
	strcpy_s(tStoreWeapon[0].strName, "목　검");
	strcpy_s(tStoreWeapon[0].strTypeName, "무　기");
	strcpy_s(tStoreWeapon[0].strDesc, "떡쇠가 깎아만든 목검");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 10;
	tStoreWeapon[0].iMax = 15;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;

	strcpy_s(tStoreWeapon[1].strName, "대　검");
	strcpy_s(tStoreWeapon[1].strTypeName, "무　기");
	strcpy_s(tStoreWeapon[1].strDesc, "떡쇠의 정성이 담긴 대검");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 40;
	tStoreWeapon[1].iPrice = 7000;
	tStoreWeapon[1].iSell = 3500;

	strcpy_s(tStoreWeapon[2].strName, "새  총");
	strcpy_s(tStoreWeapon[2].strTypeName, "무　기");
	strcpy_s(tStoreWeapon[2].strDesc, "떡쇠가 파는 새 총.");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 10;
	tStoreWeapon[2].iMax = 15;
	tStoreWeapon[2].iPrice = 1000;
	tStoreWeapon[2].iSell = 500;

	strcpy_s(tStoreWeapon[3].strName, "목  궁");
	strcpy_s(tStoreWeapon[3].strTypeName, "무　기");
	strcpy_s(tStoreWeapon[3].strDesc, "떡쇠의 목궁이다.");
	tStoreWeapon[3].eType = IT_WEAPON;
	tStoreWeapon[3].iMin = 20;
	tStoreWeapon[3].iMax = 40;
	tStoreWeapon[3].iPrice = 7000;
	tStoreWeapon[3].iSell = 3500;

	strcpy_s(tStoreWeapon[4].strName, "마법서");
	strcpy_s(tStoreWeapon[4].strTypeName, "무　기");
	strcpy_s(tStoreWeapon[4].strDesc, "떡쇠가 공수해온 마법서. 여기저기 찢어져 있다.");
	tStoreWeapon[4].eType = IT_WEAPON;
	tStoreWeapon[4].iMin = 10;
	tStoreWeapon[4].iMax = 15;
	tStoreWeapon[4].iPrice = 1000;
	tStoreWeapon[4].iSell = 500;

	strcpy_s(tStoreWeapon[5].strName, "스태프");
	strcpy_s(tStoreWeapon[5].strTypeName, "무　기");
	strcpy_s(tStoreWeapon[5].strDesc, "떡쇠가 직접 쓰던 지팡이라고 한다..");
	tStoreWeapon[5].eType = IT_WEAPON;
	tStoreWeapon[5].iMin = 20;
	tStoreWeapon[5].iMax = 40;
	tStoreWeapon[5].iPrice = 7000;
	tStoreWeapon[5].iSell = 3500;

	// 천 갑옷, 가시갑옷, 천 장갑, 목 장갑, 천 로브, 마법로브 


	// 방어구 정보 세팅
	strcpy_s(tStoreArmor[0].strName, "천 갑옷");
	strcpy_s(tStoreArmor[0].strTypeName, "방어구");
	strcpy_s(tStoreArmor[0].strDesc, "기본적인 천 갑옷");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 10;
	tStoreArmor[0].iMax = 15;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;

	strcpy_s(tStoreArmor[1].strName, "가시갑옷");
	strcpy_s(tStoreArmor[1].strTypeName, "방어구");
	strcpy_s(tStoreArmor[1].strDesc, "가시가 박혀있다.");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 20;
	tStoreArmor[1].iMax = 40;
	tStoreArmor[1].iPrice = 7000;
	tStoreArmor[1].iSell = 3500;

	strcpy_s(tStoreArmor[2].strName, "천 장갑");
	strcpy_s(tStoreArmor[2].strTypeName, "방어구");
	strcpy_s(tStoreArmor[2].strDesc, "하얀색 천 장갑.");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 10;
	tStoreArmor[2].iMax = 15;
	tStoreArmor[2].iPrice = 1000;
	tStoreArmor[2].iSell = 500;

	strcpy_s(tStoreArmor[3].strName, "목 장갑");
	strcpy_s(tStoreArmor[3].strTypeName, "방어구");
	strcpy_s(tStoreArmor[3].strDesc, "야가다의 필수품.");
	tStoreArmor[3].eType = IT_ARMOR;
	tStoreArmor[3].iMin = 20;
	tStoreArmor[3].iMax = 40;
	tStoreArmor[3].iPrice = 7000;
	tStoreArmor[3].iSell = 3500;

	strcpy_s(tStoreArmor[4].strName, "천 로브");
	strcpy_s(tStoreArmor[4].strTypeName, "방어구");
	strcpy_s(tStoreArmor[4].strDesc, "왈숙이의 천 로브");
	tStoreArmor[4].eType = IT_ARMOR;
	tStoreArmor[4].iMin = 10;
	tStoreArmor[4].iMax = 15;
	tStoreArmor[4].iPrice = 1000;
	tStoreArmor[4].iSell = 500;

	strcpy_s(tStoreArmor[5].strName, "마법 로브");
	strcpy_s(tStoreArmor[5].strTypeName, "방어구");
	strcpy_s(tStoreArmor[5].strDesc, "마법이 깃든 로브.");
	tStoreArmor[5].eType = IT_ARMOR;
	tStoreArmor[5].iMin = 20;
	tStoreArmor[5].iMax = 40;
	tStoreArmor[5].iPrice = 7000;
	tStoreArmor[5].iSell = 3500;


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

					cout << "===================== ＰＬＡＹＥＲ =====================" << endl << endl;
					cout << "이  름 : " << tPlayer.strName << "\t\t\t직  업 : " << tPlayer.strJobName << endl;
					cout << "레  벨 : " << tPlayer.iLevel << "\t\t\t경험치 : " << tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1] << endl;

					// 공격력을 아이템 능력치를 적용시켜서 바꿔준다.
					if (tPlayer.bEquip[EQ_WEAPON])
					{
						cout << "공격력 : " << tPlayer.iAttackMin << "(+"
							<< tPlayer.tEquip[EQ_WEAPON].iMin << ")"
							<< " - "
							<< tPlayer.iAttackMax << "(+"
							<< tPlayer.tEquip[EQ_WEAPON].iMax << ")"
							<< "\t";
					}
					else
					{
						cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax << "\t\t";
					}

					// 방어력을 아이템 능력치를 적용시켜서 바꿔준다.
					if (tPlayer.bEquip[EQ_ARMOR])
					{
						cout << "방어력 : " << tPlayer.iArmorMin << "(+"
							<< tPlayer.tEquip[EQ_ARMOR].iMin << ")"
							<< " - "
							<< tPlayer.iArmorMax << "(+"
							<< tPlayer.tEquip[EQ_ARMOR].iMax << ")"
							<< endl;
					}
					else
					{
						cout << "방어력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					}

					cout << "체  력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax
						<< "\t\t마  력 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

					// 소지금을 출력하기 전에 장착 아이템을 표기해준다.

					if (tPlayer.bEquip[EQ_WEAPON])
						cout << "장착 무기 : " << tPlayer.tEquip[EQ_WEAPON].strName << "\t\t";

					else
						cout << "장착 무기 : 없음" << "\t\t";

					if (tPlayer.bEquip[EQ_ARMOR])
						cout << "장착 방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;

					else
						cout << "장착 방어구 : 없음" << endl;


					cout << "소지금 : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;


					cout << "==================== ＭＯＮＳＴＥＲ ====================" << endl << endl;
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
						// 무기를 장착하고 있을 경우 무기의 Min, Max를 더해준다.

						int iAttackMin = tPlayer.iAttackMin;
						int iAttackMax = tPlayer.iAttackMax;

						if (tPlayer.bEquip[EQ_WEAPON])
						{
							iAttackMin += tPlayer.tEquip[EQ_WEAPON].iMin;
							iAttackMax += tPlayer.tEquip[EQ_WEAPON].iMax;
						}

						int iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;
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
							cout << endl << tMonster.strName << " 몬스터가 사망하였습니다." << endl << endl;

							tPlayer.iExp += tMonster.iExp;

							int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " Exp 경험치를 획득하였습니다." << endl;
							cout << iGold << " Gold를 획득하였습니다." << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							cout << endl;

							// 레벨업 했는지 체크한다.
							if (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1])
							{
								// 플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한다.
								tPlayer.iExp -= iLevelUpExp[tPlayer.iLevel - 1];

								// 레벨을 증가 시켜준다.
								++tPlayer.iLevel;
								cout << "Level UP !!!!!!!!!" << endl << endl;							
							
								// 능력치를 상승시킨다.
								int iJobIndex = tPlayer.eJob - 1;

								int iHPUp = rand() % (tLvUpTable[iJobIndex].iHPMax - tLvUpTable[iJobIndex].iHPMin + 1) + tLvUpTable[iJobIndex].iHPMin;
								int iMPUp = rand() % (tLvUpTable[iJobIndex].iMPMax - tLvUpTable[iJobIndex].iMPMin + 1) + tLvUpTable[iJobIndex].iMPMin;

								tPlayer.iAttackMin += tLvUpTable[iJobIndex].iAttackMin;
								tPlayer.iAttackMax += tLvUpTable[iJobIndex].iAttackMax;
								tPlayer.iArmorMin += tLvUpTable[iJobIndex].iArmorMin;
								tPlayer.iArmorMax += tLvUpTable[iJobIndex].iArmorMax;

								tPlayer.iHPMax += iHPUp;
								tPlayer.iMPMax += iMPUp;

								// 체력과 마력을 회복시킨다.
								tPlayer.iHP = tPlayer.iHPMax;
								tPlayer.iMP = tPlayer.iMPMax;
							}

							system("pause");
							break;
						}

						// 몬스터가 공격하는 부분도 방어력을 고려하여 수정한다.

						// 몬스터가 살아있을 경우
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;

						int iArmorMin = tPlayer.iArmorMin;
						int iArmorMax = tPlayer.iArmorMax;

						if (tPlayer.bEquip[EQ_ARMOR])
						{
							iArmorMin += tPlayer.tEquip[EQ_ARMOR].iMin;
							iArmorMax += tPlayer.tEquip[EQ_ARMOR].iMax;
						}

						iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;

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
					while (true)
					{
						system("cls");
						cout << "____________________ CHANWOOL WORLD ____________________" << endl;
						cout << "*******************   떡쇠네 대장간   *******************" << endl << endl;

						// 판매 목록을 출력
						for (int i = 0; i < STORE_WEAPON_MAX; i++)
						{
							cout << endl << i + 1 << ". 번 아이템 진열대" << endl;
							cout << "이  름 : " << tStoreWeapon[i].strName << "\t\t\t종  류 : " << tStoreWeapon[i].strTypeName << endl;
							cout << "공격력 : " << tStoreWeapon[i].iMin << " - " << tStoreWeapon[i].iMax << endl;
							cout << "판매가 : " << tStoreWeapon[i].iPrice << "\t\t\t구매가 : " << tStoreWeapon[i].iSell << endl << endl;
							cout << "설  명 : " << tStoreWeapon[i].strDesc << endl << endl;
							cout << "______________________________________________" << endl;
						}

						cout << endl << endl;
						cout << STORE_WEAPON_MAX + 1 << ". 대장간에서 나가기" << endl << endl << endl;

						cout << "소지금 : " << tPlayer.tInventory.iGold << " Gold" << endl;
						cout << "빈공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << "칸" << endl << endl << endl;

						cout << "구입할 아이템을 선택하세요 : ";

						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						// 뒤로가기 기능
						else if (iMenu == STORE_WEAPON_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_WEAPON_MAX + 1)
						{
							cout << "떡쇠가 그건 파는게 아니라고 합니다." << endl << endl;
							system("pause");
							continue;
						}

						// 상점 판매 목록 배열의 인덱스를 구해준다.
						int iWeaponIndex = iMenu - 1;

						// 인벤토리에 공간이 있는지 검사한다.
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "소지품 공간이 없습니다." << endl << endl;
							system("pause");
							continue;
						}

						// 돈이 부족할 경우
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "소지금이 부족합니다." << endl << endl;
							system("pause");
							continue;
						}

						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iWeaponIndex];

						++tPlayer.tInventory.iItemCount;

						// 골드를 차감한다.
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						cout << tStoreWeapon[iWeaponIndex].strName << " 아이템을 구매하였습니다." << endl << endl;

						system("pause");
					}

					break;

				case SM_ARMOR:
					while (true)
					{
						system("cls");
						cout << "____________________ CHANWOOL WORLD ____________________" << endl;
						cout << "*******************   왈숙네 갑옷점   *******************" << endl << endl;

						// 판매 목록을 출력
						for (int i = 0; i < STORE_ARMOR_MAX; i++)
						{
							cout << endl << i + 1 << ". 번 아이템 진열대" << endl;
							cout << "이  름 : " << tStoreArmor[i].strName << "\t\t\t종  류 : " << tStoreArmor[i].strTypeName << endl;
							cout << "방어력 : " << tStoreArmor[i].iMin << " - " << tStoreArmor[i].iMax << endl;
							cout << "판매가 : " << tStoreArmor[i].iPrice << "\t\t\t구매가 : " << tStoreArmor[i].iSell << endl << endl;
							cout << "설  명 : " << tStoreArmor[i].strDesc << endl << endl;
							cout << "______________________________________________" << endl;
						}

						cout << endl << endl;
						cout << STORE_ARMOR_MAX + 1 << ". 갑옷점에서 나가기" << endl << endl << endl;

						cout << "소지금 : " << tPlayer.tInventory.iGold << " Gold" << endl;
						cout << "빈공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << "칸" << endl << endl << endl;

						cout << "구입할 아이템을 선택하세요 : ";

						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						// 뒤로가기 기능
						else if (iMenu == STORE_ARMOR_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_ARMOR_MAX + 1)
						{
							cout << "왈숙이가 그건 파는게 아니라고 합니다." << endl << endl;
							system("pause");
							continue;
						}

						// 상점 판매 목록 배열의 인덱스를 구해준다.
						int iArmorIndex = iMenu - 1;

						// 인벤토리에 공간이 있는지 검사한다.
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "소지품 공간이 없습니다." << endl << endl;
							system("pause");
							continue;
						}

						// 돈이 부족할 경우
						else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
						{
							cout << "소지금이 부족합니다." << endl << endl;
							system("pause");
							continue;
						}

						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iArmorIndex];

						++tPlayer.tInventory.iItemCount;

						// 골드를 차감한다.
						tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;

						cout << tStoreArmor[iArmorIndex].strName << " 아이템을 구매하였습니다." << endl << endl;

						system("pause");
					}
					break;
				}

			}
			break;
		case MM_INVENTORY:
			while (true)
			{
				system("cls");
				cout << "____________________ CHANWOOL WORLD ____________________" << endl;
				cout << "********************   인 벤 토 리   ********************" << endl << endl;

				cout << "===================== ＰＬＡＹＥＲ =====================" << endl << endl;
				cout << "이  름 : " << tPlayer.strName << "\t\t\t직  업 : " << tPlayer.strJobName << endl;
				cout << "레  벨 : " << tPlayer.iLevel << "\t\t\t경험치 : " << tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1] << endl;

				// 공격력을 아이템 능력치를 적용시켜서 바꿔준다.
				if (tPlayer.bEquip[EQ_WEAPON])
				{
					cout << "공격력 : " << tPlayer.iAttackMin << "(+"
						<< tPlayer.tEquip[EQ_WEAPON].iMin << ")"
						<< " - "
						<< tPlayer.iAttackMax << "(+"
						<< tPlayer.tEquip[EQ_WEAPON].iMax << ")"
						<< "\t";
				}
				else
				{
					cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax << "\t\t";
				}

				// 방어력을 아이템 능력치를 적용시켜서 바꿔준다.
				if (tPlayer.bEquip[EQ_ARMOR])
				{
					cout << "방어력 : " << tPlayer.iArmorMin << "(+"
						<< tPlayer.tEquip[EQ_ARMOR].iMin << ")"
						<< " - "
						<< tPlayer.iArmorMax << "(+"
						<< tPlayer.tEquip[EQ_ARMOR].iMax << ")"
						<< endl;
				}
				else
				{
					cout << "방어력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
				}

				cout << "체  력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax
					<< "\t\t마  력 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

				// 소지금을 출력하기 전에 장착 아이템을 표기해준다.

				if (tPlayer.bEquip[EQ_WEAPON])
					cout << "장착 무기 : " << tPlayer.tEquip[EQ_WEAPON].strName << "\t\t";

				else
					cout << "장착 무기 : 없음" << "\t\t";

				if (tPlayer.bEquip[EQ_ARMOR])
					cout << "장착 방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;

				else
					cout << "장착 방어구 : 없음" << endl;


				cout << "소지금 : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;

				for (int i = 0; i < tPlayer.tInventory.iItemCount; i++)
				{
					cout << endl << i + 1 << ". 번 아이템" << endl;
					cout << "이  름 : " << tPlayer.tInventory.tItem[i].strName << "\t\t\t종  류 : " << tPlayer.tInventory.tItem[i].strTypeName << endl;

					switch (tPlayer.tInventory.tItem[i].eType)
					{
					case IT_WEAPON:
						cout << "공격력 : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
						break;
					case IT_ARMOR:
						cout << "방어력 : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
						break;
					}

					cout << "판매가 : " << tPlayer.tInventory.tItem[i].iPrice << "\t\t\t구매가 : " << tPlayer.tInventory.tItem[i].iSell << endl << endl;
					cout << "설  명 : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
					cout << "______________________________________________" << endl;
				}

				cout << endl << endl;
				cout << tPlayer.tInventory.iItemCount + 1 << ". 뒤로가기" << endl << endl;

				cout << "장착할 아이템을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (iMenu == tPlayer.tInventory.iItemCount + 1)
					break;

				else if (iMenu < 1 || iMenu > tPlayer.tInventory.iItemCount + 1)
				{
					cout << "잘못 선택하였습니다." << endl << endl;
					system("pause");
					continue;
				}

				int idx = iMenu - 1;

				EQUIP	eq;

				switch (tPlayer.tInventory.tItem[idx].eType)
				{
				case IT_WEAPON:
					eq = EQ_WEAPON;
					break;
				case IT_ARMOR:
					eq = EQ_ARMOR;
					break;
				}

				/*
					아이템이 이미 장착되어 있을 경우
					장착되어 있는 아이템과 장착할 아이템을 교체해주어야 한다.
					Swap 알고리즘을 활용
				*/
				if (tPlayer.bEquip[eq])
				{
					_tagItem tSwap = tPlayer.tEquip[eq];
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
					tPlayer.tInventory.tItem[idx] = tSwap;
				}

				/*
					장착되어있지 않은 슬롯이었을 경우 인벤토리의 아이템을 장착 창으로 옮기고 인벤토리 1칸 비워지게 된다.
				*/
				else
				{
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

					for (int i = idx; i < tPlayer.tInventory.iItemCount; i++)
					{
						tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
					}

					--tPlayer.tInventory.iItemCount;


					// 장착했기 때문에 해당 슬롯을 true로 만들어준다.
					tPlayer.bEquip[eq] = true;
				}

				cout << tPlayer.tEquip[eq].strName << " 아이템을 장착하였습니다." << endl << endl;

				system("pause");
			}
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