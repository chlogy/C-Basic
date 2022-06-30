#include <iostream>

#define		INPUT_ERROR		-1

#define		NAME_SIZE			32
#define		ITEM_DESC_LENGTH	512
#define		INVENTORY_MAX		10

#define		STORE_WEAPON_MAX	3
#define		STORE_ARMOR_MAX		3

#define		LEVEL_MAX			10

using namespace std;

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK,
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK,
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

const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };
_tagLevelUpStatus	g_tLvUpTable[JOB_END - 1] = {};


int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');

		// INPUT_ERROR가 리턴되면 입력이 잘못 되었다는 의미
		return INPUT_ERROR;
	}

	return iInput;
}

int OutputMainMenu()
{
	system("cls");
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "********************   마 을 광 장   ********************" << endl << endl;
	cout << "1. 마을 밖 던전입구" << endl << endl;
	cout << "2. 야시장 골목길" << endl << endl;
	cout << "3. 인 벤 토 리" << endl << endl;
	cout << "4. 게 임 종 료" << endl << endl << endl << endl;

	cout << "메뉴를 선택하세요 : ";

	int iMenu = InputInt();

	if (iMenu == INPUT_ERROR || iMenu <= MM_NONE || iMenu > MM_EXIT)
		return INPUT_ERROR;

	return iMenu;
}

int OutputMapMenu()
{
	system("cls");
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "********************  던전  진입로  ********************" << endl << endl;

	cout << "1. 슬라임의 동굴" << endl << endl;
	cout << "2. 요정의 숲" << endl << endl;
	cout << "3. 보스의 동굴" << endl << endl;
	cout << "4. 마을로 돌아가기" << endl << endl << endl << endl;

	cout << "던전을 선택하세요 : ";

	int iMenu = InputInt();

	if (iMenu == INPUT_ERROR || iMenu <= DT_NONE || iMenu > DT_BACK)
		return INPUT_ERROR;

	return iMenu;
}

void OutputBattleTag(int iMenu)
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

void OutputPlayer(_tagPlayer* pPlayer)
{
	cout << "===================== ＰＬＡＹＥＲ =====================" << endl << endl;
	cout << "이  름 : " << pPlayer->strName << "\t\t\t직  업 : " << pPlayer->strJobName << endl;
	cout << "레  벨 : " << pPlayer->iLevel << "\t\t\t경험치 : " << pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;

	// 공격력을 아이템 능력치를 적용시켜서 바꿔준다.
	if (pPlayer->bEquip[EQ_WEAPON])
	{
		cout << "공격력 : " << pPlayer->iAttackMin << "(+"
			<< pPlayer->tEquip[EQ_WEAPON].iMin << ")"
			<< " - "
			<< pPlayer->iAttackMax << "(+"
			<< pPlayer->tEquip[EQ_WEAPON].iMax << ")"
			<< "\t";
	}
	else
	{
		cout << "공격력 : " << pPlayer->iAttackMin << " - " << pPlayer->iAttackMax << "\t\t";
	}

	// 방어력을 아이템 능력치를 적용시켜서 바꿔준다.
	if (pPlayer->bEquip[EQ_ARMOR])
	{
		cout << "방어력 : " << pPlayer->iArmorMin << "(+"
			<< pPlayer->tEquip[EQ_ARMOR].iMin << ")"
			<< " - "
			<< pPlayer->iArmorMax << "(+"
			<< pPlayer->tEquip[EQ_ARMOR].iMax << ")"
			<< endl;
	}
	else
	{
		cout << "방어력 : " << pPlayer->iArmorMin << " - " << pPlayer->iArmorMax << endl;
	}

	cout << "체  력 : " << pPlayer->iHP << " / " << pPlayer->iHPMax
		<< "\t\t마  력 : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;

	// 소지금을 출력하기 전에 장착 아이템을 표기해준다.

	if (pPlayer->bEquip[EQ_WEAPON])
		cout << "장착 무기 : " << pPlayer->tEquip[EQ_WEAPON].strName << "\t\t";

	else
		cout << "장착 무기 : 없음" << "\t\t";

	if (pPlayer->bEquip[EQ_ARMOR])
		cout << "장착 방어구 : " << pPlayer->tEquip[EQ_ARMOR].strName << endl;

	else
		cout << "장착 방어구 : 없음" << endl;


	cout << "소지금 : " << pPlayer->tInventory.iGold << " Gold" << endl << endl;
}

void OutputMonster(_tagMonster* pMonster)
{
	cout << "==================== ＭＯＮＳＴＥＲ ====================" << endl << endl;
	cout << "이  름 : " << pMonster->strName << "\t\t\t레  벨 : " << pMonster->iLevel << endl;
	cout << "공격력 : " << pMonster->iAttackMin << " - " << pMonster->iAttackMax
		<< "\t\t방어력 : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "체  력 : " << pMonster->iHP << " / " << pMonster->iHPMax
		<< "\t\t마  력 : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;

	cout << "드랍 경험치 : " << pMonster->iExp
		<< "\t\t드랍 골드 : " << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl << endl << endl;
}

int OutputBattleMenu()
{
	cout << "1. 공격하기" << endl;
	cout << "2. 도망가기" << endl << endl;

	cout << "행동을 선택하세요 : ";

	int iMenu = InputInt();

	if (iMenu == INPUT_ERROR || iMenu <= BATTLE_NONE || iMenu > BATTLE_BACK)
		return INPUT_ERROR;

	return iMenu;
}

_tagLevelUpStatus CreateLvUpStatus(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHPMin, int iHPMax, int iMPMin, int iMPMax)
{
	_tagLevelUpStatus	tStatus = {};

	tStatus.iAttackMin = iAttackMin;
	tStatus.iAttackMax = iAttackMax;
	tStatus.iArmorMin = iArmorMin;
	tStatus.iArmorMax = iArmorMax;
	tStatus.iHPMin = iHPMin;
	tStatus.iHPMax = iHPMax;
	tStatus.iMPMin = iMPMin;
	tStatus.iMPMax = iMPMax;

	return tStatus;
}

void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster)
{
	int iAttackMin = pPlayer->iAttackMin;
	int iAttackMax = pPlayer->iAttackMax;

	if (pPlayer->bEquip[EQ_WEAPON])
	{
		iAttackMin += pPlayer->tEquip[EQ_WEAPON].iMin;
		iAttackMax += pPlayer->tEquip[EQ_WEAPON].iMax;
	}

	int iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;
	int iArmor = rand() % (pMonster->iArmorMax - pMonster->iArmorMin + 1) + pMonster->iArmorMin;

	int iDamage = iAttack - iArmor;

	// 삼항연산자 : 조건식 ? true값 : false값

	iDamage = iDamage < 1 ? 1 : iDamage;

	/*if (iDamage < 1)
		iDamage = 1;*/

	pMonster->iHP -= iDamage;

	cout << endl << pPlayer->strName << "이(가) " << pMonster->strName << "에게 " << iDamage << " 피해를 입혔습니다." << endl;

	// 몬스터가 사망했을 경우
	if (pMonster->iHP <= 0)
	{
		cout << endl << pMonster->strName << " 몬스터가 사망하였습니다." << endl << endl;

		pPlayer->iExp += pMonster->iExp;

		int iGold = rand() % (pMonster->iGoldMax - pMonster->iGoldMin + 1) + pMonster->iGoldMin;
		pPlayer->tInventory.iGold += iGold;

		cout << pMonster->iExp << " Exp 경험치를 획득하였습니다." << endl;
		cout << iGold << " Gold를 획득하였습니다." << endl;

		pMonster->iHP = pMonster->iHPMax;
		pMonster->iMP = pMonster->iMPMax;

		cout << endl;

		// 레벨업 했는지 체크한다.
		if (pPlayer->iExp >= g_iLevelUpExp[pPlayer->iLevel - 1])
		{
			// 플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한다.
			pPlayer->iExp -= g_iLevelUpExp[pPlayer->iLevel - 1];

			// 레벨을 증가 시켜준다.
			++pPlayer->iLevel;
			cout << "Level UP !!!!!!!!!" << endl << endl;

			// 능력치를 상승시킨다.
			int iJobIndex = pPlayer->eJob - 1;

			int iHPUp = rand() % (g_tLvUpTable[iJobIndex].iHPMax - g_tLvUpTable[iJobIndex].iHPMin + 1) + g_tLvUpTable[iJobIndex].iHPMin;
			int iMPUp = rand() % (g_tLvUpTable[iJobIndex].iMPMax - g_tLvUpTable[iJobIndex].iMPMin + 1) + g_tLvUpTable[iJobIndex].iMPMin;

			pPlayer->iAttackMin += g_tLvUpTable[iJobIndex].iAttackMin;
			pPlayer->iAttackMax += g_tLvUpTable[iJobIndex].iAttackMax;
			pPlayer->iArmorMin += g_tLvUpTable[iJobIndex].iArmorMin;
			pPlayer->iArmorMax += g_tLvUpTable[iJobIndex].iArmorMax;

			pPlayer->iHPMax += iHPUp;
			pPlayer->iMPMax += iMPUp;

			// 체력과 마력을 회복시킨다.
			pPlayer->iHP = pPlayer->iHPMax;
			pPlayer->iMP = pPlayer->iMPMax;
		}

		return;
	}

	// 몬스터가 공격하는 부분도 방어력을 고려하여 수정한다.

	// 몬스터가 살아있을 경우
	iAttack = rand() % (pMonster->iAttackMax - pMonster->iAttackMin + 1) + pMonster->iAttackMin;

	int iArmorMin = pPlayer->iArmorMin;
	int iArmorMax = pPlayer->iArmorMax;

	if (pPlayer->bEquip[EQ_ARMOR])
	{
		iArmorMin += pPlayer->tEquip[EQ_ARMOR].iMin;
		iArmorMax += pPlayer->tEquip[EQ_ARMOR].iMax;
	}

	iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;

	iDamage = iAttack - iArmor;
	iDamage = iDamage < 1 ? 1 : iDamage;

	// Player의 HP를 감소시킨다.
	pPlayer->iHP -= iDamage;

	cout << pMonster->strName << "이(가) " << pPlayer->strName << "에게 " << iDamage << " 피해를 입혔습니다." << endl << endl;

	// 플레이어 사망시
	if (pPlayer->iHP <= 0)
	{
		cout << pPlayer->strName << "이(가) 사망하였습니다." << endl << endl;

		int iExp = pPlayer->iExp * 0.1f;
		int iGold = pPlayer->tInventory.iGold * 0.1f;

		pPlayer->iExp -= iExp;
		pPlayer->tInventory.iGold -= iGold;

		cout << iExp << " Exp 경험치를 잃었습니다." << endl;
		cout << iGold << " Gold를 잃었습니다." << endl;

		pPlayer->iHP = pPlayer->iHPMax;
		pPlayer->iMP = pPlayer->iMPMax;
	}

	cout << endl;
}

void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu)
{
	_tagMonster	tMonster = pMonsterArr[iMenu - 1];

	while (true)
	{
		OutputBattleTag(iMenu);

		OutputPlayer(pPlayer);

		OutputMonster(&tMonster);

		switch (OutputBattleMenu())
		{
		case BATTLE_ATTACK:
			Battle(pPlayer, &tMonster);

			system("pause");
			break;
		case BATTLE_BACK:
			return;
		}
	}
}

void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr)
{
	while (true)
	{
		int iMenu = OutputMapMenu();

		if (DT_BACK == iMenu)
			return;

		RunBattle(pPlayer, pMonsterArr, iMenu);
	}
}

int SelectJob()
{
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

		iJob = InputInt();

		if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}

	return iJob;
}

void SetPlayer(_tagPlayer* pPlayer)
{
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "********************  캐릭터  설정  ********************" << endl << endl;

	cout << "당신의 이름을 입력해주세요 : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);

	pPlayer->eJob = static_cast<JOB>(SelectJob());

	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 300000;

	switch (pPlayer->eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "검    사");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMax = 15;
		pPlayer->iArmorMin = 20;
		pPlayer->iArmorMax = 25;
		pPlayer->iHPMax = 500;
		pPlayer->iHP = 500;
		pPlayer->iMPMax = 100;
		pPlayer->iMP = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(pPlayer->strJobName, "궁    수");
		pPlayer->iAttackMin = 15;
		pPlayer->iAttackMax = 20;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 400;
		pPlayer->iHP = 400;
		pPlayer->iMPMax = 200;
		pPlayer->iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(pPlayer->strJobName, "마 법 사");
		pPlayer->iAttackMin = 20;
		pPlayer->iAttackMax = 25;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMax = 15;
		pPlayer->iHPMax = 300;
		pPlayer->iHP = 300;
		pPlayer->iMPMax = 300;
		pPlayer->iMP = 300;
		break;
	}
}

_tagMonster CreateMonster(const char* pName, int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHP, int iMP,
	int iLevel, int iExp, int iGoldMin, int iGoldMax)
{
	_tagMonster	tMonster = {};

	strcpy_s(tMonster.strName, pName);
	tMonster.iAttackMin = iAttackMin;
	tMonster.iAttackMax = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = iArmorMax;
	tMonster.iHP = iHP;
	tMonster.iHPMax = iHP;
	tMonster.iMP = iMP;
	tMonster.iMPMax = iMP;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoldMin = iGoldMin;
	tMonster.iGoldMax = iGoldMax;

	return tMonster;
}

void SetMonster(_tagMonster* pMonsterArr)
{
	pMonsterArr[0] = CreateMonster("슬라임", 20, 30, 2, 5, 100, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster("엘　프", 80, 130, 60, 90, 2000, 100, 5, 7000, 600, 8000);
	pMonsterArr[2] = CreateMonster("자　쿰", 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 50000);
}

void SetLvUpStatusTable()
{
	g_tLvUpTable[JOB_KNIGHT - 1] = CreateLvUpStatus(10, 15, 15, 25, 50, 100, 10, 20);
	g_tLvUpTable[JOB_ARCHER - 1] = CreateLvUpStatus(20, 25, 10, 15, 30, 60, 30, 50);
	g_tLvUpTable[JOB_WIZARD - 1] = CreateLvUpStatus(30, 45, 2, 5, 20, 40, 50, 90);
}

int OutputStoreMenu()
{
	system("cls");
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "*****************  어두운 시장 뒷골목  *****************" << endl << endl;

	cout << "1. 떡쇠네 대장간" << endl;
	cout << "2. 왈숙네 갑옷점" << endl;
	cout << "3. 마을 광장으로 돌아가기" << endl << endl;

	cout << "상점을 선택하세요 : ";

	int iMenu = InputInt();

	if (iMenu <= SM_NONE || iMenu > SM_BACK)
		return INPUT_ERROR;

	return iMenu;
}

int OutputStoreItemList(_tagInventory* pInventroy, _tagItem* pStore, int iStoreType, int iItemCount)
{
	// 판매 목록을 출력
	for (int i = 0; i < iItemCount; i++)
	{
		cout << endl << i + 1 << ". 번 아이템 진열대" << endl;
		cout << "이  름 : " << pStore[i].strName << "\t\t\t종  류 : " << pStore[i].strTypeName << endl;
		
		switch (iStoreType)
		{
		case SM_WEAPON:
			cout << "공격력 : " << pStore[i].iMin << " - " << pStore[i].iMax << endl;
			break;
		case SM_ARMOR:
			cout << "방어력 : " << pStore[i].iMin << " - " << pStore[i].iMax << endl;
			break;
		}

		cout << "판매가 : " << pStore[i].iPrice << "\t\t\t구매가 : " << pStore[i].iSell << endl << endl;
		cout << "설  명 : " << pStore[i].strDesc << endl << endl;
		cout << "______________________________________________" << endl;
	}

	cout << endl << endl;
	cout << iItemCount + 1 << ". 대장간에서 나가기" << endl << endl << endl;

	cout << "소지금 : " << pInventroy->iGold << " Gold" << endl;
	cout << "빈공간 : " << INVENTORY_MAX - pInventroy->iItemCount << "칸" << endl << endl << endl;

	cout << "구입할 아이템을 선택하세요 : ";

	int iMenu = InputInt();

	if (iMenu < 1 || iMenu > iItemCount + 1)
		return INPUT_ERROR;

	return iMenu;

}

void BuyItem(_tagInventory* pInventory, _tagItem* pStore, int iItemCount, int iStoreType)
{
	while (true)
	{
		system("cls");
		cout << "____________________ CHANWOOL WORLD ____________________" << endl;
		
		switch (iStoreType)
		{
		case SM_WEAPON:
			cout << "*******************   떡쇠네 대장간   *******************" << endl << endl;
			break;
		case SM_ARMOR:
			cout << "*******************   왈숙네 갑옷점   *******************" << endl << endl;
			break;
		}

		int iInput = OutputStoreItemList(pInventory, pStore, iStoreType, iItemCount);
		
		if (iInput == INPUT_ERROR)
		{
			cout << "잘못 입력하였습니다." << endl;
			system("pause");
			continue;
		}

		// 뒤로가기 기능
		else if (iInput == iItemCount + 1)
			break;

		// 상점 판매 목록 배열의 인덱스를 구해준다.
		int iIndex = iInput - 1;

		// 인벤토리에 공간이 있는지 검사한다.
		if (pInventory->iItemCount == INVENTORY_MAX)
		{
			cout << "소지품 공간이 없습니다." << endl << endl;
			system("pause");
			continue;
		}

		// 돈이 부족할 경우
		else if (pInventory->iGold < pStore[iIndex].iPrice)
		{
			cout << "소지금이 부족합니다." << endl << endl;
			system("pause");
			continue;
		}

		pInventory->tItem[pInventory->iItemCount] = pStore[iIndex];

		++pInventory->iItemCount;

		// 골드를 차감한다.
		pInventory->iGold -= pStore[iIndex].iPrice;

		cout << pStore[iIndex].strName << " 아이템을 구매하였습니다." << endl << endl;

		system("pause");
	}
}

void RunStore(_tagInventory* pInventory, _tagItem* pWeapon, _tagItem* pArmor)
{
	while (true)
	{
		switch (OutputStoreMenu())
		{
		case SM_WEAPON:
			BuyItem(pInventory, pWeapon, STORE_WEAPON_MAX, SM_WEAPON);
			break;
		case SM_ARMOR:
			BuyItem(pInventory, pArmor, STORE_ARMOR_MAX, SM_ARMOR);
			break;
		case SM_BACK:
			return;
		}
	}
}

_tagItem CreateItem(const char* pName, const char* pDesc, ITEM_TYPE eType, int iMin, int iMax, int iPrice, int iSell)
{
	_tagItem tItem = {};

	strcpy_s(tItem.strName, pName);
	strcpy_s(tItem.strDesc, pDesc);
	tItem.eType = eType;

	switch (eType)
	{
	case IT_WEAPON:
		strcpy_s(tItem.strTypeName, "무　기");
		break;
	case IT_ARMOR:
		strcpy_s(tItem.strTypeName, "방어구");
		break;
	}

	tItem.iMin = iMin;
	tItem.iMax = iMax;
	tItem.iPrice = iPrice;
	tItem.iSell = iSell;

	return tItem;
}

void SetStore(_tagItem* pWeapon, _tagItem* pArmor)
{
	pWeapon[0] = CreateItem("목　검", "떡쇠가 깎아만든 목검", IT_WEAPON, 10, 15, 1000, 500);
	pWeapon[1] = CreateItem("새  총", "떡쇠가 파는 새 총.", IT_WEAPON, 10, 15, 1000, 500);
	pWeapon[2] = CreateItem("마법서", "떡쇠가 공수해온 마법서. 여기저기 찢어져 있다..", IT_WEAPON, 10, 15, 1000, 500);

	pArmor[0] = CreateItem("천 갑옷", "기본적인 천 갑옷.", IT_ARMOR, 10, 15, 1000, 500);
	pArmor[1] = CreateItem("천 장갑", "하얀색 천 장갑.", IT_ARMOR, 10, 15, 1000, 500);
	pArmor[2] = CreateItem("천 로브", "마법이 깃든 로브", IT_ARMOR, 10, 15, 1000, 500);
}

int OutputInventory(_tagPlayer* pPlayer)
{
	system("cls");
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "********************   인 벤 토 리   ********************" << endl << endl;

	OutputPlayer(pPlayer);

	for (int i = 0; i < pPlayer->tInventory.iItemCount; i++)
	{
		cout << endl << i + 1 << ". 번 아이템" << endl;
		cout << "이  름 : " << pPlayer->tInventory.tItem[i].strName << "\t\t\t종  류 : " << pPlayer->tInventory.tItem[i].strTypeName << endl;

		switch (pPlayer->tInventory.tItem[i].eType)
		{
		case IT_WEAPON:
			cout << "공격력 : " << pPlayer->tInventory.tItem[i].iMin << " - " << pPlayer->tInventory.tItem[i].iMax << endl;
			break;
		case IT_ARMOR:
			cout << "방어력 : " << pPlayer->tInventory.tItem[i].iMin << " - " << pPlayer->tInventory.tItem[i].iMax << endl;
			break;
		}

		cout << "판매가 : " << pPlayer->tInventory.tItem[i].iPrice << "\t\t\t구매가 : " << pPlayer->tInventory.tItem[i].iSell << endl << endl;
		cout << "설  명 : " << pPlayer->tInventory.tItem[i].strDesc << endl << endl;
		cout << "______________________________________________" << endl;
	}

	cout << endl << endl;
	cout << pPlayer->tInventory.iItemCount + 1 << ". 뒤로가기" << endl << endl;

	cout << "장착할 아이템을 선택하세요 : ";
	int iMenu = InputInt();

	if (iMenu < 1 || iMenu > pPlayer->tInventory.iItemCount + 1)
		return INPUT_ERROR;

	return iMenu;
}

EQUIP ComputeEquipType(ITEM_TYPE eType)
{
	EQUIP	eq;

	switch (eType)
	{
	case IT_WEAPON:
		eq = EQ_WEAPON;
		break;
	case IT_ARMOR:
		eq = EQ_ARMOR;
		break;
	}

	return eq;
}

void RunInventory(_tagPlayer* pPlayer)
{
	while (true)
	{
		int iInput = OutputInventory(pPlayer);
		
		if (iInput == INPUT_ERROR)
			continue;
		
		else if (iInput == pPlayer->tInventory.iItemCount + 1)
			break;

		else if (iInput < 1 || iInput > pPlayer->tInventory.iItemCount + 1)
		{
			cout << "잘못 선택하였습니다." << endl << endl;
			system("pause");
			continue;
		}

		int idx = iInput - 1;

		EQUIP	eq = ComputeEquipType(pPlayer->tInventory.tItem[idx].eType);

		/*
			아이템이 이미 장착되어 있을 경우
			장착되어 있는 아이템과 장착할 아이템을 교체해주어야 한다.
			Swap 알고리즘을 활용
		*/
		if (pPlayer->bEquip[eq])
		{
			_tagItem tSwap = pPlayer->tEquip[eq];
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];
			pPlayer->tInventory.tItem[idx] = tSwap;
		}

		/*
			장착되어있지 않은 슬롯이었을 경우 인벤토리의 아이템을 장착 창으로 옮기고 인벤토리 1칸 비워지게 된다.
		*/
		else
		{
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];

			for (int i = idx; i < pPlayer->tInventory.iItemCount; i++)
			{
				pPlayer->tInventory.tItem[i] = pPlayer->tInventory.tItem[i + 1];
			}

			--pPlayer->tInventory.iItemCount;


			// 장착했기 때문에 해당 슬롯을 true로 만들어준다.
			pPlayer->bEquip[eq] = true;
		}

		cout << pPlayer->tEquip[eq].strName << " 아이템을 장착하였습니다." << endl << endl;

		system("pause");
	}
}

int main()
{
	srand(time(NULL));

	// 플레이어 정보를 설정한다.
	_tagPlayer	tPlayer = {};
	SetPlayer(&tPlayer);

	// 몬스터 정보를 설정한다.
	_tagMonster tMonsterArr[DT_BACK - 1] = {};
	SetMonster(tMonsterArr);

	SetLvUpStatusTable();

	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_ARMOR_MAX] = {};

	SetStore(tStoreWeapon, tStoreArmor);

	bool bLoop = true;
	while (bLoop)
	{
		switch (OutputMainMenu())
		{
		case MM_MAP:
			RunMap(&tPlayer, tMonsterArr);
			break;
		case MM_STORE:
			RunStore(&tPlayer.tInventory, tStoreWeapon, tStoreArmor);
			break;
		case MM_INVENTORY:
			RunInventory(&tPlayer);
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}

	}

	return 0;
}