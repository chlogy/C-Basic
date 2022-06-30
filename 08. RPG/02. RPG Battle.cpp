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
	// todo


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
					
					cout << "********************* �У̣��٣ţ� *********************" << endl << endl;
					cout << "��  �� : " << tPlayer.strName << "\t\t\t��  �� : " << tPlayer.strJobName << endl;
					cout << "��  �� : " << tPlayer.iLevel << "\t\t\t����ġ : " << tPlayer.iExp << endl;
					cout << "���ݷ� : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax
						<< "\t\t���� : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					cout << "ü  �� : " << tPlayer.iHP << " / " << tPlayer.iHPMax
						<< "\t\t��  �� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

					cout << "������ : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;


					cout << "******************** �ͣϣΣӣԣţ� ********************" << endl << endl;
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
						// Min 5
						// Max 15
						
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin;
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
							cout << endl<< tMonster.strName << " ���Ͱ� ����Ͽ����ϴ�." << endl << endl;

							tPlayer.iExp += tMonster.iExp;

							int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " Exp ����ġ�� ȹ���Ͽ����ϴ�." << endl;
							cout << iGold << " Gold�� ȹ���Ͽ����ϴ�." << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							cout << endl;
							system("pause");
							break;
						}

						// ���Ͱ� ������� ���
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;

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
			cout << "�߸� �����Ͽ����ϴ�." << endl;
			break;
		}

	}

	cout << endl << "������ �����մϴ�." << endl << endl;

	return 0;
}