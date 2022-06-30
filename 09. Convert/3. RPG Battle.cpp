#include <iostream>

#define		INPUT_ERROR		-1

#define		NAME_SIZE			32
#define		ITEM_DESC_LENGTH	512
#define		INVENTORY_MAX		10

#define		STORE_WEAPON_MAX	6
#define		STORE_ARMOR_MAX		6

#define		LEVEL_MAX			10

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

		// INPUT_ERROR�� ���ϵǸ� �Է��� �߸� �Ǿ��ٴ� �ǹ�
		return INPUT_ERROR;
	}

	return iInput;
}

int OutputMainMenu()
{
	system("cls");
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "********************   �� �� �� ��   ********************" << endl << endl;
	cout << "1. ���� �� �����Ա�" << endl << endl;
	cout << "2. �߽��� ����" << endl << endl;
	cout << "3. �� �� �� ��" << endl << endl;
	cout << "4. �� �� �� ��" << endl << endl << endl << endl;

	cout << "�޴��� �����ϼ��� : ";

	int iMenu = InputInt();

	if (iMenu == INPUT_ERROR || iMenu <= MM_NONE || iMenu > MM_EXIT)
		return INPUT_ERROR;

	return iMenu;
}

int OutputMapMenu()
{
	system("cls");
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "********************  ����  ���Է�  ********************" << endl << endl;

	cout << "1. �������� ����" << endl << endl;
	cout << "2. ������ ��" << endl << endl;
	cout << "3. ������ ����" << endl << endl;
	cout << "4. ������ ���ư���" << endl << endl << endl << endl;

	cout << "������ �����ϼ��� : ";

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
		cout << "******************** ��������  ���� ********************" << endl << endl;
		break;
	case DT_FOREST_FAIRY:
		cout << "*********************** �����ǽ� ***********************" << endl << endl;
		break;
	case DT_CAVE_OF_BOSS:
		cout << "********************* ������  ���� *********************" << endl << endl;
		break;
	}
}

void OutputPlayer(_tagPlayer* pPlayer)
{
	cout << "===================== �У̣��٣ţ� =====================" << endl << endl;
	cout << "��  �� : " << pPlayer->strName << "\t\t\t��  �� : " << pPlayer->strJobName << endl;
	cout << "��  �� : " << pPlayer->iLevel << "\t\t\t����ġ : " << pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;

	// ���ݷ��� ������ �ɷ�ġ�� ������Ѽ� �ٲ��ش�.
	if (pPlayer->bEquip[EQ_WEAPON])
	{
		cout << "���ݷ� : " << pPlayer->iAttackMin << "(+"
			<< pPlayer->tEquip[EQ_WEAPON].iMin << ")"
			<< " - "
			<< pPlayer->iAttackMax << "(+"
			<< pPlayer->tEquip[EQ_WEAPON].iMax << ")"
			<< "\t";
	}
	else
	{
		cout << "���ݷ� : " << pPlayer->iAttackMin << " - " << pPlayer->iAttackMax << "\t\t";
	}

	// ������ ������ �ɷ�ġ�� ������Ѽ� �ٲ��ش�.
	if (pPlayer->bEquip[EQ_ARMOR])
	{
		cout << "���� : " << pPlayer->iArmorMin << "(+"
			<< pPlayer->tEquip[EQ_ARMOR].iMin << ")"
			<< " - "
			<< pPlayer->iArmorMax << "(+"
			<< pPlayer->tEquip[EQ_ARMOR].iMax << ")"
			<< endl;
	}
	else
	{
		cout << "���� : " << pPlayer->iArmorMin << " - " << pPlayer->iArmorMax << endl;
	}

	cout << "ü  �� : " << pPlayer->iHP << " / " << pPlayer->iHPMax
		<< "\t\t��  �� : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;

	// �������� ����ϱ� ���� ���� �������� ǥ�����ش�.

	if (pPlayer->bEquip[EQ_WEAPON])
		cout << "���� ���� : " << pPlayer->tEquip[EQ_WEAPON].strName << "\t\t";

	else
		cout << "���� ���� : ����" << "\t\t";

	if (pPlayer->bEquip[EQ_ARMOR])
		cout << "���� �� : " << pPlayer->tEquip[EQ_ARMOR].strName << endl;

	else
		cout << "���� �� : ����" << endl;


	cout << "������ : " << pPlayer->tInventory.iGold << " Gold" << endl << endl;
}

void OutputMonster(_tagMonster* pMonster)
{
	cout << "==================== �ͣϣΣӣԣţ� ====================" << endl << endl;
	cout << "��  �� : " << pMonster->strName << "\t\t\t��  �� : " << pMonster->iLevel << endl;
	cout << "���ݷ� : " << pMonster->iAttackMin << " - " << pMonster->iAttackMax
		<< "\t\t���� : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "ü  �� : " << pMonster->iHP << " / " << pMonster->iHPMax
		<< "\t\t��  �� : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;

	cout << "��� ����ġ : " << pMonster->iExp
		<< "\t\t��� ��� : " << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl << endl << endl;
}

int OutputBattleMenu()
{
	cout << "1. �����ϱ�" << endl;
	cout << "2. ��������" << endl << endl;

	cout << "�ൿ�� �����ϼ��� : ";

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

	// ���׿����� : ���ǽ� ? true�� : false��

	iDamage = iDamage < 1 ? 1 : iDamage;

	/*if (iDamage < 1)
		iDamage = 1;*/

	pMonster->iHP -= iDamage;

	cout << endl << pPlayer->strName << "��(��) " << pMonster->strName << "���� " << iDamage << " ���ظ� �������ϴ�." << endl;

	// ���Ͱ� ������� ���
	if (pMonster->iHP <= 0)
	{
		cout << endl << pMonster->strName << " ���Ͱ� ����Ͽ����ϴ�." << endl << endl;

		pPlayer->iExp += pMonster->iExp;

		int iGold = rand() % (pMonster->iGoldMax - pMonster->iGoldMin + 1) + pMonster->iGoldMin;
		pPlayer->tInventory.iGold += iGold;

		cout << pMonster->iExp << " Exp ����ġ�� ȹ���Ͽ����ϴ�." << endl;
		cout << iGold << " Gold�� ȹ���Ͽ����ϴ�." << endl;

		pMonster->iHP = pMonster->iHPMax;
		pMonster->iMP = pMonster->iMPMax;

		cout << endl;

		// ������ �ߴ��� üũ�Ѵ�.
		if (pPlayer->iExp >= g_iLevelUpExp[pPlayer->iLevel - 1])
		{
			// �÷��̾� ����ġ�� �������� �ʿ��� ����ġ��ŭ �����Ѵ�.
			pPlayer->iExp -= g_iLevelUpExp[pPlayer->iLevel - 1];

			// ������ ���� �����ش�.
			++pPlayer->iLevel;
			cout << "Level UP !!!!!!!!!" << endl << endl;

			// �ɷ�ġ�� ��½�Ų��.
			int iJobIndex = pPlayer->eJob - 1;

			int iHPUp = rand() % (g_tLvUpTable[iJobIndex].iHPMax - g_tLvUpTable[iJobIndex].iHPMin + 1) + g_tLvUpTable[iJobIndex].iHPMin;
			int iMPUp = rand() % (g_tLvUpTable[iJobIndex].iMPMax - g_tLvUpTable[iJobIndex].iMPMin + 1) + g_tLvUpTable[iJobIndex].iMPMin;

			pPlayer->iAttackMin += g_tLvUpTable[iJobIndex].iAttackMin;
			pPlayer->iAttackMax += g_tLvUpTable[iJobIndex].iAttackMax;
			pPlayer->iArmorMin += g_tLvUpTable[iJobIndex].iArmorMin;
			pPlayer->iArmorMax += g_tLvUpTable[iJobIndex].iArmorMax;

			pPlayer->iHPMax += iHPUp;
			pPlayer->iMPMax += iMPUp;

			// ü�°� ������ ȸ����Ų��.
			pPlayer->iHP = pPlayer->iHPMax;
			pPlayer->iMP = pPlayer->iMPMax;
		}

		return;
	}

	// ���Ͱ� �����ϴ� �κе� ������ ����Ͽ� �����Ѵ�.

	// ���Ͱ� ������� ���
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

	// Player�� HP�� ���ҽ�Ų��.
	pPlayer->iHP -= iDamage;

	cout << pMonster->strName << "��(��) " << pPlayer->strName << "���� " << iDamage << " ���ظ� �������ϴ�." << endl << endl;

	// �÷��̾� �����
	if (pPlayer->iHP <= 0)
	{
		cout << pPlayer->strName << "��(��) ����Ͽ����ϴ�." << endl << endl;

		int iExp = pPlayer->iExp * 0.1f;
		int iGold = pPlayer->tInventory.iGold * 0.1f;

		pPlayer->iExp -= iExp;
		pPlayer->tInventory.iGold -= iGold;

		cout << iExp << " Exp ����ġ�� �Ҿ����ϴ�." << endl;
		cout << iGold << " Gold�� �Ҿ����ϴ�." << endl;

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
		cout << "********************  ĳ����  ����  ********************" << endl << endl;

		cout << "1. ��    ��" << endl << endl;
		cout << "2. ��    ��" << endl << endl;
		cout << "3. �� �� ��" << endl << endl << endl << endl;

		cout << "������ �����ϼ��� : ";

		iJob = InputInt();

		if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}

	return iJob;
}

void SetPlayer(_tagPlayer* pPlayer)
{
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "********************  ĳ����  ����  ********************" << endl << endl;

	cout << "����� �̸��� �Է����ּ��� : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);

	pPlayer->eJob = static_cast<JOB>(SelectJob());

	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 300000;

	switch (pPlayer->eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "��    ��");
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
		strcpy_s(pPlayer->strJobName, "��    ��");
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
		strcpy_s(pPlayer->strJobName, "�� �� ��");
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
	pMonsterArr[0] = CreateMonster("������", 20, 30, 2, 5, 100, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster("������", 80, 130, 60, 90, 2000, 100, 5, 7000, 600, 8000);
	pMonsterArr[2] = CreateMonster("�ڡ���", 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 50000);
}

void SetLvUpStatusTable()
{
	g_tLvUpTable[JOB_KNIGHT - 1] = CreateLvUpStatus(10, 15, 15, 25, 50, 100, 10, 20);
	g_tLvUpTable[JOB_ARCHER - 1] = CreateLvUpStatus(20, 25, 10, 15, 30, 60, 30, 50);
	g_tLvUpTable[JOB_WIZARD - 1] = CreateLvUpStatus(30, 45, 2, 5, 20, 40, 50, 90);
}

int main()
{
	srand(time(NULL));

	// �÷��̾� ������ �����Ѵ�.
	_tagPlayer	tPlayer = {};
	SetPlayer(&tPlayer);

	// ���� ������ �����Ѵ�.
	_tagMonster tMonsterArr[DT_BACK - 1] = {};
	SetMonster(tMonsterArr);

	SetLvUpStatusTable();

	bool bLoop = true;
	while (bLoop)
	{
		switch (OutputMainMenu())
		{
		case MM_MAP:
			RunMap(&tPlayer, tMonsterArr);
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}

	}

	return 0;
}