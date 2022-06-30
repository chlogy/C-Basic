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

int OutputStoreMenu()
{
	system("cls");
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "*****************  ��ο� ���� �ް��  *****************" << endl << endl;

	cout << "1. ����� ���尣" << endl;
	cout << "2. �м��� ������" << endl;
	cout << "3. ���� �������� ���ư���" << endl << endl;

	cout << "������ �����ϼ��� : ";

	int iMenu = InputInt();

	if (iMenu <= SM_NONE || iMenu > SM_BACK)
		return INPUT_ERROR;

	return iMenu;
}

int OutputStoreItemList(_tagInventory* pInventroy, _tagItem* pStore, int iStoreType, int iItemCount)
{
	// �Ǹ� ����� ���
	for (int i = 0; i < iItemCount; i++)
	{
		cout << endl << i + 1 << ". �� ������ ������" << endl;
		cout << "��  �� : " << pStore[i].strName << "\t\t\t��  �� : " << pStore[i].strTypeName << endl;
		
		switch (iStoreType)
		{
		case SM_WEAPON:
			cout << "���ݷ� : " << pStore[i].iMin << " - " << pStore[i].iMax << endl;
			break;
		case SM_ARMOR:
			cout << "���� : " << pStore[i].iMin << " - " << pStore[i].iMax << endl;
			break;
		}

		cout << "�ǸŰ� : " << pStore[i].iPrice << "\t\t\t���Ű� : " << pStore[i].iSell << endl << endl;
		cout << "��  �� : " << pStore[i].strDesc << endl << endl;
		cout << "______________________________________________" << endl;
	}

	cout << endl << endl;
	cout << iItemCount + 1 << ". ���尣���� ������" << endl << endl << endl;

	cout << "������ : " << pInventroy->iGold << " Gold" << endl;
	cout << "����� : " << INVENTORY_MAX - pInventroy->iItemCount << "ĭ" << endl << endl << endl;

	cout << "������ �������� �����ϼ��� : ";

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
			cout << "*******************   ����� ���尣   *******************" << endl << endl;
			break;
		case SM_ARMOR:
			cout << "*******************   �м��� ������   *******************" << endl << endl;
			break;
		}

		int iInput = OutputStoreItemList(pInventory, pStore, iStoreType, iItemCount);
		
		if (iInput == INPUT_ERROR)
		{
			cout << "�߸� �Է��Ͽ����ϴ�." << endl;
			system("pause");
			continue;
		}

		// �ڷΰ��� ���
		else if (iInput == iItemCount + 1)
			break;

		// ���� �Ǹ� ��� �迭�� �ε����� �����ش�.
		int iIndex = iInput - 1;

		// �κ��丮�� ������ �ִ��� �˻��Ѵ�.
		if (pInventory->iItemCount == INVENTORY_MAX)
		{
			cout << "����ǰ ������ �����ϴ�." << endl << endl;
			system("pause");
			continue;
		}

		// ���� ������ ���
		else if (pInventory->iGold < pStore[iIndex].iPrice)
		{
			cout << "�������� �����մϴ�." << endl << endl;
			system("pause");
			continue;
		}

		pInventory->tItem[pInventory->iItemCount] = pStore[iIndex];

		++pInventory->iItemCount;

		// ��带 �����Ѵ�.
		pInventory->iGold -= pStore[iIndex].iPrice;

		cout << pStore[iIndex].strName << " �������� �����Ͽ����ϴ�." << endl << endl;

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
		strcpy_s(tItem.strTypeName, "������");
		break;
	case IT_ARMOR:
		strcpy_s(tItem.strTypeName, "��");
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
	pWeapon[0] = CreateItem("�񡡰�", "���谡 ��Ƹ��� ���", IT_WEAPON, 10, 15, 1000, 500);
	pWeapon[1] = CreateItem("��  ��", "���谡 �Ĵ� �� ��.", IT_WEAPON, 10, 15, 1000, 500);
	pWeapon[2] = CreateItem("������", "���谡 �����ؿ� ������. �������� ������ �ִ�..", IT_WEAPON, 10, 15, 1000, 500);

	pArmor[0] = CreateItem("õ ����", "�⺻���� õ ����.", IT_ARMOR, 10, 15, 1000, 500);
	pArmor[1] = CreateItem("õ �尩", "�Ͼ�� õ �尩.", IT_ARMOR, 10, 15, 1000, 500);
	pArmor[2] = CreateItem("õ �κ�", "������ ��� �κ�", IT_ARMOR, 10, 15, 1000, 500);
}

int OutputInventory(_tagPlayer* pPlayer)
{
	system("cls");
	cout << "____________________ CHANWOOL WORLD ____________________" << endl;
	cout << "********************   �� �� �� ��   ********************" << endl << endl;

	OutputPlayer(pPlayer);

	for (int i = 0; i < pPlayer->tInventory.iItemCount; i++)
	{
		cout << endl << i + 1 << ". �� ������" << endl;
		cout << "��  �� : " << pPlayer->tInventory.tItem[i].strName << "\t\t\t��  �� : " << pPlayer->tInventory.tItem[i].strTypeName << endl;

		switch (pPlayer->tInventory.tItem[i].eType)
		{
		case IT_WEAPON:
			cout << "���ݷ� : " << pPlayer->tInventory.tItem[i].iMin << " - " << pPlayer->tInventory.tItem[i].iMax << endl;
			break;
		case IT_ARMOR:
			cout << "���� : " << pPlayer->tInventory.tItem[i].iMin << " - " << pPlayer->tInventory.tItem[i].iMax << endl;
			break;
		}

		cout << "�ǸŰ� : " << pPlayer->tInventory.tItem[i].iPrice << "\t\t\t���Ű� : " << pPlayer->tInventory.tItem[i].iSell << endl << endl;
		cout << "��  �� : " << pPlayer->tInventory.tItem[i].strDesc << endl << endl;
		cout << "______________________________________________" << endl;
	}

	cout << endl << endl;
	cout << pPlayer->tInventory.iItemCount + 1 << ". �ڷΰ���" << endl << endl;

	cout << "������ �������� �����ϼ��� : ";
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
			cout << "�߸� �����Ͽ����ϴ�." << endl << endl;
			system("pause");
			continue;
		}

		int idx = iInput - 1;

		EQUIP	eq = ComputeEquipType(pPlayer->tInventory.tItem[idx].eType);

		/*
			�������� �̹� �����Ǿ� ���� ���
			�����Ǿ� �ִ� �����۰� ������ �������� ��ü���־�� �Ѵ�.
			Swap �˰����� Ȱ��
		*/
		if (pPlayer->bEquip[eq])
		{
			_tagItem tSwap = pPlayer->tEquip[eq];
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];
			pPlayer->tInventory.tItem[idx] = tSwap;
		}

		/*
			�����Ǿ����� ���� �����̾��� ��� �κ��丮�� �������� ���� â���� �ű�� �κ��丮 1ĭ ������� �ȴ�.
		*/
		else
		{
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];

			for (int i = idx; i < pPlayer->tInventory.iItemCount; i++)
			{
				pPlayer->tInventory.tItem[i] = pPlayer->tInventory.tItem[i + 1];
			}

			--pPlayer->tInventory.iItemCount;


			// �����߱� ������ �ش� ������ true�� ������ش�.
			pPlayer->bEquip[eq] = true;
		}

		cout << pPlayer->tEquip[eq].strName << " �������� �����Ͽ����ϴ�." << endl << endl;

		system("pause");
	}
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