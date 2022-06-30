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

	// �������� �ʿ��� ����ġ ����� �����.
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
	cout << "********************  ĳ����  ����  ********************" << endl << endl;

	cout << "����� �̸��� �Է����ּ��� : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

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
		strcpy_s(tPlayer.strJobName, "��    ��");
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
		strcpy_s(tPlayer.strJobName, "��    ��");
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
		strcpy_s(tPlayer.strJobName, "�� �� ��");
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

	// ������
	strcpy_s(tMonsterArr[DT_CAVE_OF_SLIME - 1].strName, "������");
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

	// ����
	strcpy_s(tMonsterArr[DT_FOREST_FAIRY - 1].strName, "��  ��");
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

	// ����
	strcpy_s(tMonsterArr[DT_CAVE_OF_BOSS - 1].strName, "��  ��");
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

	// ���� ���� ����
	strcpy_s(tStoreWeapon[0].strName, "�񡡰�");
	strcpy_s(tStoreWeapon[0].strTypeName, "������");
	strcpy_s(tStoreWeapon[0].strDesc, "���谡 ��Ƹ��� ���");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 10;
	tStoreWeapon[0].iMax = 15;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;

	strcpy_s(tStoreWeapon[1].strName, "�롡��");
	strcpy_s(tStoreWeapon[1].strTypeName, "������");
	strcpy_s(tStoreWeapon[1].strDesc, "������ ������ ��� ���");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 40;
	tStoreWeapon[1].iPrice = 7000;
	tStoreWeapon[1].iSell = 3500;

	strcpy_s(tStoreWeapon[2].strName, "��  ��");
	strcpy_s(tStoreWeapon[2].strTypeName, "������");
	strcpy_s(tStoreWeapon[2].strDesc, "���谡 �Ĵ� �� ��.");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 10;
	tStoreWeapon[2].iMax = 15;
	tStoreWeapon[2].iPrice = 1000;
	tStoreWeapon[2].iSell = 500;

	strcpy_s(tStoreWeapon[3].strName, "��  ��");
	strcpy_s(tStoreWeapon[3].strTypeName, "������");
	strcpy_s(tStoreWeapon[3].strDesc, "������ ����̴�.");
	tStoreWeapon[3].eType = IT_WEAPON;
	tStoreWeapon[3].iMin = 20;
	tStoreWeapon[3].iMax = 40;
	tStoreWeapon[3].iPrice = 7000;
	tStoreWeapon[3].iSell = 3500;

	strcpy_s(tStoreWeapon[4].strName, "������");
	strcpy_s(tStoreWeapon[4].strTypeName, "������");
	strcpy_s(tStoreWeapon[4].strDesc, "���谡 �����ؿ� ������. �������� ������ �ִ�.");
	tStoreWeapon[4].eType = IT_WEAPON;
	tStoreWeapon[4].iMin = 10;
	tStoreWeapon[4].iMax = 15;
	tStoreWeapon[4].iPrice = 1000;
	tStoreWeapon[4].iSell = 500;

	strcpy_s(tStoreWeapon[5].strName, "������");
	strcpy_s(tStoreWeapon[5].strTypeName, "������");
	strcpy_s(tStoreWeapon[5].strDesc, "���谡 ���� ���� �����̶�� �Ѵ�..");
	tStoreWeapon[5].eType = IT_WEAPON;
	tStoreWeapon[5].iMin = 20;
	tStoreWeapon[5].iMax = 40;
	tStoreWeapon[5].iPrice = 7000;
	tStoreWeapon[5].iSell = 3500;

	// õ ����, ���ð���, õ �尩, �� �尩, õ �κ�, �����κ� 


	// �� ���� ����
	strcpy_s(tStoreArmor[0].strName, "õ ����");
	strcpy_s(tStoreArmor[0].strTypeName, "��");
	strcpy_s(tStoreArmor[0].strDesc, "�⺻���� õ ����");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 10;
	tStoreArmor[0].iMax = 15;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;

	strcpy_s(tStoreArmor[1].strName, "���ð���");
	strcpy_s(tStoreArmor[1].strTypeName, "��");
	strcpy_s(tStoreArmor[1].strDesc, "���ð� �����ִ�.");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 20;
	tStoreArmor[1].iMax = 40;
	tStoreArmor[1].iPrice = 7000;
	tStoreArmor[1].iSell = 3500;

	strcpy_s(tStoreArmor[2].strName, "õ �尩");
	strcpy_s(tStoreArmor[2].strTypeName, "��");
	strcpy_s(tStoreArmor[2].strDesc, "�Ͼ�� õ �尩.");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 10;
	tStoreArmor[2].iMax = 15;
	tStoreArmor[2].iPrice = 1000;
	tStoreArmor[2].iSell = 500;

	strcpy_s(tStoreArmor[3].strName, "�� �尩");
	strcpy_s(tStoreArmor[3].strTypeName, "��");
	strcpy_s(tStoreArmor[3].strDesc, "�߰����� �ʼ�ǰ.");
	tStoreArmor[3].eType = IT_ARMOR;
	tStoreArmor[3].iMin = 20;
	tStoreArmor[3].iMax = 40;
	tStoreArmor[3].iPrice = 7000;
	tStoreArmor[3].iSell = 3500;

	strcpy_s(tStoreArmor[4].strName, "õ �κ�");
	strcpy_s(tStoreArmor[4].strTypeName, "��");
	strcpy_s(tStoreArmor[4].strDesc, "�м����� õ �κ�");
	tStoreArmor[4].eType = IT_ARMOR;
	tStoreArmor[4].iMin = 10;
	tStoreArmor[4].iMax = 15;
	tStoreArmor[4].iPrice = 1000;
	tStoreArmor[4].iSell = 500;

	strcpy_s(tStoreArmor[5].strName, "���� �κ�");
	strcpy_s(tStoreArmor[5].strTypeName, "��");
	strcpy_s(tStoreArmor[5].strDesc, "������ ��� �κ�.");
	tStoreArmor[5].eType = IT_ARMOR;
	tStoreArmor[5].iMin = 20;
	tStoreArmor[5].iMax = 40;
	tStoreArmor[5].iPrice = 7000;
	tStoreArmor[5].iSell = 3500;


	while (true)
	{
		system("cls");
		cout << "____________________ CHANWOOL WORLD ____________________" << endl;
		cout << "********************   �� �� �� ��   ********************" << endl << endl;
		cout << "1. ���� �� �����Ա�" << endl << endl;
		cout << "2. �߽��� ����" << endl << endl;
		cout << "3. �� �� �� ��" << endl << endl;
		cout << "4. �� �� �� ��" << endl << endl << endl << endl;

		cout << "�޴��� �����ϼ��� : ";

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
				cout << "********************  ����  ���Է�  ********************" << endl << endl;

				cout << "1. �������� ����" << endl << endl;
				cout << "2. ������ ��" << endl << endl;
				cout << "3. ������ ����" << endl << endl;
				cout << "4. ������ ���ư���" << endl << endl << endl << endl;

				cout << "������ �����ϼ��� : ";

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
						cout << "******************** ��������  ���� ********************" << endl << endl;
						break;
					case DT_FOREST_FAIRY:
						cout << "*********************** �����ǽ� ***********************" << endl << endl;
						break;
					case DT_CAVE_OF_BOSS:
						cout << "********************* ������  ���� *********************" << endl << endl;
						break;
					}

					cout << "===================== �У̣��٣ţ� =====================" << endl << endl;
					cout << "��  �� : " << tPlayer.strName << "\t\t\t��  �� : " << tPlayer.strJobName << endl;
					cout << "��  �� : " << tPlayer.iLevel << "\t\t\t����ġ : " << tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1] << endl;

					// ���ݷ��� ������ �ɷ�ġ�� ������Ѽ� �ٲ��ش�.
					if (tPlayer.bEquip[EQ_WEAPON])
					{
						cout << "���ݷ� : " << tPlayer.iAttackMin << "(+"
							<< tPlayer.tEquip[EQ_WEAPON].iMin << ")"
							<< " - "
							<< tPlayer.iAttackMax << "(+"
							<< tPlayer.tEquip[EQ_WEAPON].iMax << ")"
							<< "\t";
					}
					else
					{
						cout << "���ݷ� : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax << "\t\t";
					}

					// ������ ������ �ɷ�ġ�� ������Ѽ� �ٲ��ش�.
					if (tPlayer.bEquip[EQ_ARMOR])
					{
						cout << "���� : " << tPlayer.iArmorMin << "(+"
							<< tPlayer.tEquip[EQ_ARMOR].iMin << ")"
							<< " - "
							<< tPlayer.iArmorMax << "(+"
							<< tPlayer.tEquip[EQ_ARMOR].iMax << ")"
							<< endl;
					}
					else
					{
						cout << "���� : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					}

					cout << "ü  �� : " << tPlayer.iHP << " / " << tPlayer.iHPMax
						<< "\t\t��  �� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

					// �������� ����ϱ� ���� ���� �������� ǥ�����ش�.

					if (tPlayer.bEquip[EQ_WEAPON])
						cout << "���� ���� : " << tPlayer.tEquip[EQ_WEAPON].strName << "\t\t";

					else
						cout << "���� ���� : ����" << "\t\t";

					if (tPlayer.bEquip[EQ_ARMOR])
						cout << "���� �� : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;

					else
						cout << "���� �� : ����" << endl;


					cout << "������ : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;


					cout << "==================== �ͣϣΣӣԣţ� ====================" << endl << endl;
					cout << "��  �� : " << tMonster.strName << "\t\t\t��  �� : " << tMonster.iLevel << endl;
					cout << "���ݷ� : " << tMonster.iAttackMin << " - " << tMonster.iAttackMax
						<< "\t\t���� : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
					cout << "ü  �� : " << tMonster.iHP << " / " << tMonster.iHPMax
						<< "\t\t��  �� : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;

					cout << "��� ����ġ : " << tMonster.iExp
						<< "\t\t��� ��� : " << tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl << endl << endl;


					cout << "1. �����ϱ�" << endl;
					cout << "2. ��������" << endl << endl;

					cout << "�ൿ�� �����ϼ��� : ";

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
						// ���⸦ �����ϰ� ���� ��� ������ Min, Max�� �����ش�.

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

						// ���׿����� : ���ǽ� ? true�� : false��

						iDamage = iDamage < 1 ? 1 : iDamage;

						/*if (iDamage < 1)
							iDamage = 1;*/

						tMonster.iHP -= iDamage;

						cout << endl << tPlayer.strName << "��(��) " << tMonster.strName << "���� " << iDamage << " ���ظ� �������ϴ�." << endl;

						// ���Ͱ� ������� ���
						if (tMonster.iHP <= 0)
						{
							cout << endl << tMonster.strName << " ���Ͱ� ����Ͽ����ϴ�." << endl << endl;

							tPlayer.iExp += tMonster.iExp;

							int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " Exp ����ġ�� ȹ���Ͽ����ϴ�." << endl;
							cout << iGold << " Gold�� ȹ���Ͽ����ϴ�." << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							cout << endl;

							// ������ �ߴ��� üũ�Ѵ�.
							if (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1])
							{
								// �÷��̾� ����ġ�� �������� �ʿ��� ����ġ��ŭ �����Ѵ�.
								tPlayer.iExp -= iLevelUpExp[tPlayer.iLevel - 1];

								// ������ ���� �����ش�.
								++tPlayer.iLevel;
								cout << "Level UP !!!!!!!!!" << endl << endl;							
							
								// �ɷ�ġ�� ��½�Ų��.
								int iJobIndex = tPlayer.eJob - 1;

								int iHPUp = rand() % (tLvUpTable[iJobIndex].iHPMax - tLvUpTable[iJobIndex].iHPMin + 1) + tLvUpTable[iJobIndex].iHPMin;
								int iMPUp = rand() % (tLvUpTable[iJobIndex].iMPMax - tLvUpTable[iJobIndex].iMPMin + 1) + tLvUpTable[iJobIndex].iMPMin;

								tPlayer.iAttackMin += tLvUpTable[iJobIndex].iAttackMin;
								tPlayer.iAttackMax += tLvUpTable[iJobIndex].iAttackMax;
								tPlayer.iArmorMin += tLvUpTable[iJobIndex].iArmorMin;
								tPlayer.iArmorMax += tLvUpTable[iJobIndex].iArmorMax;

								tPlayer.iHPMax += iHPUp;
								tPlayer.iMPMax += iMPUp;

								// ü�°� ������ ȸ����Ų��.
								tPlayer.iHP = tPlayer.iHPMax;
								tPlayer.iMP = tPlayer.iMPMax;
							}

							system("pause");
							break;
						}

						// ���Ͱ� �����ϴ� �κе� ������ ����Ͽ� �����Ѵ�.

						// ���Ͱ� ������� ���
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

						// Player�� HP�� ���ҽ�Ų��.
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << "��(��) " << tPlayer.strName << "���� " << iDamage << " ���ظ� �������ϴ�." << endl << endl;

						// �÷��̾� �����
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << "��(��) ����Ͽ����ϴ�." << endl << endl;

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " Exp ����ġ�� �Ҿ����ϴ�." << endl;
							cout << iGold << " Gold�� �Ҿ����ϴ�." << endl;

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
				cout << "*****************  ��ο� ���� �ް��  *****************" << endl << endl;

				cout << "1. ����� ���尣" << endl;
				cout << "2. �м��� ������" << endl;
				cout << "3. ���� �������� ���ư���" << endl << endl;

				cout << "������ �����ϼ��� : ";

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
						cout << "*******************   ����� ���尣   *******************" << endl << endl;

						// �Ǹ� ����� ���
						for (int i = 0; i < STORE_WEAPON_MAX; i++)
						{
							cout << endl << i + 1 << ". �� ������ ������" << endl;
							cout << "��  �� : " << tStoreWeapon[i].strName << "\t\t\t��  �� : " << tStoreWeapon[i].strTypeName << endl;
							cout << "���ݷ� : " << tStoreWeapon[i].iMin << " - " << tStoreWeapon[i].iMax << endl;
							cout << "�ǸŰ� : " << tStoreWeapon[i].iPrice << "\t\t\t���Ű� : " << tStoreWeapon[i].iSell << endl << endl;
							cout << "��  �� : " << tStoreWeapon[i].strDesc << endl << endl;
							cout << "______________________________________________" << endl;
						}

						cout << endl << endl;
						cout << STORE_WEAPON_MAX + 1 << ". ���尣���� ������" << endl << endl << endl;

						cout << "������ : " << tPlayer.tInventory.iGold << " Gold" << endl;
						cout << "����� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << "ĭ" << endl << endl << endl;

						cout << "������ �������� �����ϼ��� : ";

						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						// �ڷΰ��� ���
						else if (iMenu == STORE_WEAPON_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_WEAPON_MAX + 1)
						{
							cout << "���谡 �װ� �Ĵ°� �ƴ϶�� �մϴ�." << endl << endl;
							system("pause");
							continue;
						}

						// ���� �Ǹ� ��� �迭�� �ε����� �����ش�.
						int iWeaponIndex = iMenu - 1;

						// �κ��丮�� ������ �ִ��� �˻��Ѵ�.
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "����ǰ ������ �����ϴ�." << endl << endl;
							system("pause");
							continue;
						}

						// ���� ������ ���
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "�������� �����մϴ�." << endl << endl;
							system("pause");
							continue;
						}

						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iWeaponIndex];

						++tPlayer.tInventory.iItemCount;

						// ��带 �����Ѵ�.
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						cout << tStoreWeapon[iWeaponIndex].strName << " �������� �����Ͽ����ϴ�." << endl << endl;

						system("pause");
					}

					break;

				case SM_ARMOR:
					while (true)
					{
						system("cls");
						cout << "____________________ CHANWOOL WORLD ____________________" << endl;
						cout << "*******************   �м��� ������   *******************" << endl << endl;

						// �Ǹ� ����� ���
						for (int i = 0; i < STORE_ARMOR_MAX; i++)
						{
							cout << endl << i + 1 << ". �� ������ ������" << endl;
							cout << "��  �� : " << tStoreArmor[i].strName << "\t\t\t��  �� : " << tStoreArmor[i].strTypeName << endl;
							cout << "���� : " << tStoreArmor[i].iMin << " - " << tStoreArmor[i].iMax << endl;
							cout << "�ǸŰ� : " << tStoreArmor[i].iPrice << "\t\t\t���Ű� : " << tStoreArmor[i].iSell << endl << endl;
							cout << "��  �� : " << tStoreArmor[i].strDesc << endl << endl;
							cout << "______________________________________________" << endl;
						}

						cout << endl << endl;
						cout << STORE_ARMOR_MAX + 1 << ". ���������� ������" << endl << endl << endl;

						cout << "������ : " << tPlayer.tInventory.iGold << " Gold" << endl;
						cout << "����� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << "ĭ" << endl << endl << endl;

						cout << "������ �������� �����ϼ��� : ";

						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						// �ڷΰ��� ���
						else if (iMenu == STORE_ARMOR_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_ARMOR_MAX + 1)
						{
							cout << "�м��̰� �װ� �Ĵ°� �ƴ϶�� �մϴ�." << endl << endl;
							system("pause");
							continue;
						}

						// ���� �Ǹ� ��� �迭�� �ε����� �����ش�.
						int iArmorIndex = iMenu - 1;

						// �κ��丮�� ������ �ִ��� �˻��Ѵ�.
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "����ǰ ������ �����ϴ�." << endl << endl;
							system("pause");
							continue;
						}

						// ���� ������ ���
						else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
						{
							cout << "�������� �����մϴ�." << endl << endl;
							system("pause");
							continue;
						}

						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iArmorIndex];

						++tPlayer.tInventory.iItemCount;

						// ��带 �����Ѵ�.
						tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;

						cout << tStoreArmor[iArmorIndex].strName << " �������� �����Ͽ����ϴ�." << endl << endl;

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
				cout << "********************   �� �� �� ��   ********************" << endl << endl;

				cout << "===================== �У̣��٣ţ� =====================" << endl << endl;
				cout << "��  �� : " << tPlayer.strName << "\t\t\t��  �� : " << tPlayer.strJobName << endl;
				cout << "��  �� : " << tPlayer.iLevel << "\t\t\t����ġ : " << tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1] << endl;

				// ���ݷ��� ������ �ɷ�ġ�� ������Ѽ� �ٲ��ش�.
				if (tPlayer.bEquip[EQ_WEAPON])
				{
					cout << "���ݷ� : " << tPlayer.iAttackMin << "(+"
						<< tPlayer.tEquip[EQ_WEAPON].iMin << ")"
						<< " - "
						<< tPlayer.iAttackMax << "(+"
						<< tPlayer.tEquip[EQ_WEAPON].iMax << ")"
						<< "\t";
				}
				else
				{
					cout << "���ݷ� : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax << "\t\t";
				}

				// ������ ������ �ɷ�ġ�� ������Ѽ� �ٲ��ش�.
				if (tPlayer.bEquip[EQ_ARMOR])
				{
					cout << "���� : " << tPlayer.iArmorMin << "(+"
						<< tPlayer.tEquip[EQ_ARMOR].iMin << ")"
						<< " - "
						<< tPlayer.iArmorMax << "(+"
						<< tPlayer.tEquip[EQ_ARMOR].iMax << ")"
						<< endl;
				}
				else
				{
					cout << "���� : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
				}

				cout << "ü  �� : " << tPlayer.iHP << " / " << tPlayer.iHPMax
					<< "\t\t��  �� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

				// �������� ����ϱ� ���� ���� �������� ǥ�����ش�.

				if (tPlayer.bEquip[EQ_WEAPON])
					cout << "���� ���� : " << tPlayer.tEquip[EQ_WEAPON].strName << "\t\t";

				else
					cout << "���� ���� : ����" << "\t\t";

				if (tPlayer.bEquip[EQ_ARMOR])
					cout << "���� �� : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;

				else
					cout << "���� �� : ����" << endl;


				cout << "������ : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;

				for (int i = 0; i < tPlayer.tInventory.iItemCount; i++)
				{
					cout << endl << i + 1 << ". �� ������" << endl;
					cout << "��  �� : " << tPlayer.tInventory.tItem[i].strName << "\t\t\t��  �� : " << tPlayer.tInventory.tItem[i].strTypeName << endl;

					switch (tPlayer.tInventory.tItem[i].eType)
					{
					case IT_WEAPON:
						cout << "���ݷ� : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
						break;
					case IT_ARMOR:
						cout << "���� : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
						break;
					}

					cout << "�ǸŰ� : " << tPlayer.tInventory.tItem[i].iPrice << "\t\t\t���Ű� : " << tPlayer.tInventory.tItem[i].iSell << endl << endl;
					cout << "��  �� : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
					cout << "______________________________________________" << endl;
				}

				cout << endl << endl;
				cout << tPlayer.tInventory.iItemCount + 1 << ". �ڷΰ���" << endl << endl;

				cout << "������ �������� �����ϼ��� : ";
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
					cout << "�߸� �����Ͽ����ϴ�." << endl << endl;
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
					�������� �̹� �����Ǿ� ���� ���
					�����Ǿ� �ִ� �����۰� ������ �������� ��ü���־�� �Ѵ�.
					Swap �˰����� Ȱ��
				*/
				if (tPlayer.bEquip[eq])
				{
					_tagItem tSwap = tPlayer.tEquip[eq];
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
					tPlayer.tInventory.tItem[idx] = tSwap;
				}

				/*
					�����Ǿ����� ���� �����̾��� ��� �κ��丮�� �������� ���� â���� �ű�� �κ��丮 1ĭ ������� �ȴ�.
				*/
				else
				{
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

					for (int i = idx; i < tPlayer.tInventory.iItemCount; i++)
					{
						tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
					}

					--tPlayer.tInventory.iItemCount;


					// �����߱� ������ �ش� ������ true�� ������ش�.
					tPlayer.bEquip[eq] = true;
				}

				cout << tPlayer.tEquip[eq].strName << " �������� �����Ͽ����ϴ�." << endl << endl;

				system("pause");
			}
			break;
		case MM_EXIT:
			break;
		default:
			cout << "�߸� �����Ͽ����ϴ�." << endl;
			break;
		}

	}

	cout << endl << "������ �����մϴ�." << endl << endl;

	return 0;
}