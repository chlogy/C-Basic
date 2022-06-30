#include <iostream>

#define		NAME_SIZE		32
#define		STUDENT_MAX		10
#define		ADDRESS_SIZE	128
#define		PHONE_LENGTH	14

enum SEX
{
	MALE,
	FEMALE,
};

struct _tagStudent
{
	char	strName[NAME_SIZE];
	char	strAddress[ADDRESS_SIZE];
	char	strPhoneNumber[PHONE_LENGTH];

	SEX		eSex;

	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAverage;

	char	cGrade;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT,
};

using namespace std;

int main()
{
	_tagStudent	tStudentArr[STUDENT_MAX] = {};

	int iStudentCount = 0;
	int iStdNumber = 1;

	char	cSex;
	char	strName[NAME_SIZE] = {};

	while (true)
	{
		system("cls");
		cout << "__________ STUDENT MANAGEMENT __________" << endl << endl;

		cout << "1. �л����� ���" << endl;
		cout << "2. �л����� ����" << endl;
		cout << "3. �л����� �˻�" << endl;
		cout << "4. ��ü�л� ���" << endl;
		cout << "5. ���α׷� ����" << endl << endl;

		cout << "�޴��� �����ϼ��� : ";

		int iMenu;
		cin >> iMenu;

		/*
			cin�� �����ʿ� ���� ������ int type�̶�� int type�� ������ �޾ƾ� �Ѵ�.
			������ ���� Ÿ�Կ� ���缭 ���� �Է��ؾ� �ϴµ�
			�Ǽ��� ������ �ƴ� ���ڸ� �Է��� ��� ������ �߻��Ѵ�.

			�׷��� ������ ����ó���� ������ �߻��ߴ��� ���⼭ üũ�Ͽ� ������ �߻��ϸ� cin ���ο� �������۸� �����ݴϴ�.

			cin ���ο� �Է¹��۰� �ִµ� �Է¹��۴� �Է��� ���� �����س��� �� ���� ������ �־��ִ� ������ �մϴ�.
			�� �Է¹��ۿ� \n�� ���������Ƿ� ���۸� ��ȸ�Ͽ� ������ �����ִ��� �����ش�.

			buffer : �ӽ� ���� ����.

			���� ������ üũ�Ѵ�.
			cin.fail()�� ���� �� �Է� ������ �߻����� ��� true�� ��ȯ�Ѵ�.
		*/

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			/*
				�Է¹��ۿ� \n�� ���������Ƿ� �Է¹��۸� �˻��Ͽ� \n�� �����ش�.
				ù ��°���� �˻��ϰ��� �ϴ� ������ ũ�⸦ �����Ѵ�.
				�˳��ϰ� 1024 ����Ʈ�� �������� ��Ȳ�̴�.

				�� ��°���� ã���� �ϴ� ���ڸ� �־��ش�.
				�׷��� �Է¹��� ó������ \n�� �ִ� �� ���� ã�Ƽ� �� �κ��� ��� �����༭ �ٽ� �Է¹��� �� �ֵ��� ���ش�.
			*/
			continue;


		}

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			cout << "____________ �л� ���� �߰� ____________" << endl << endl;

			if (iStudentCount == STUDENT_MAX)
				break;

			cout << "��  �� : ";
			cin >> tStudentArr[iStudentCount].strName;

			cin.ignore(1024, '\n');
			cout << "��  �� : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "����ó : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_LENGTH);

			cout << "��  �� (M/F) : ";
			cin >> cSex;

			switch (cSex)
			{
			case 'M':
			case 'm':
				tStudentArr[iStudentCount].eSex = MALE;
				break;

			case 'F':
			case 'f':
				tStudentArr[iStudentCount].eSex = FEMALE;
				break;
			}

			cout << "��  �� : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "��  �� : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "��  �� : ";
			cin >> tStudentArr[iStudentCount].iMath;

			// ����
			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;

			// ���
			tStudentArr[iStudentCount].fAverage = tStudentArr[iStudentCount].iTotal / 3.f;

			// ����
			if (tStudentArr[iStudentCount].fAverage >= 90.f)
			{
				tStudentArr[iStudentCount].cGrade = 'A';
			}
			else if (tStudentArr[iStudentCount].fAverage >= 80.f)
			{
				tStudentArr[iStudentCount].cGrade = 'B';
			}
			else if (tStudentArr[iStudentCount].fAverage >= 70.f)
			{
				tStudentArr[iStudentCount].cGrade = 'C';
			}
			else if (tStudentArr[iStudentCount].fAverage >= 50.f)
			{
				tStudentArr[iStudentCount].cGrade = 'D';
			}
			else
			{
				tStudentArr[iStudentCount].cGrade = 'F';
			}

			/*switch ((tStudentArr[iStudentCount].iTotal / 3) / 10)
			{
			case 10:
			case 9:
				tStudentArr[iStudentCount].cGrade = 'A';
				break;

			case 8:
				tStudentArr[iStudentCount].cGrade = 'B';
				break;

			case 7:
				tStudentArr[iStudentCount].cGrade = 'C';
				break;

			case 6:
			case 5:
				tStudentArr[iStudentCount].cGrade = 'D';
				break;

			default:
				tStudentArr[iStudentCount].cGrade = 'F';
				break;
			}*/


			// �й�
			tStudentArr[iStudentCount].iNumber = iStdNumber;

			++iStdNumber;
			++iStudentCount;

			break;
		case MENU_DELETE:
			system("cls");
			cout << "____________ �л� ���� ���� ____________" << endl << endl;
			cout << "������ �̸��� �Է����ּ��� : ";
			cin.ignore(1024, '\n');
			cin.getline(strName, NAME_SIZE);

			// =========== ���� ����
			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "��  �� : " << tStudentArr[i].strName << endl;
					cout << "��  �� : " << tStudentArr[i].iNumber << endl;
					cout << "��  �� : " << tStudentArr[i].strAddress << endl;
					cout << "����ó : " << tStudentArr[i].strPhoneNumber << endl;

					switch (tStudentArr[i].eSex)
					{
					case MALE:
						cout << "��  �� : ��" << endl;
						break;
					case FEMALE:
						cout << "��  �� : ��" << endl;
						break;
					}

					cout << "��  �� : " << tStudentArr[i].cGrade << endl;
					cout << "��  �� : " << tStudentArr[i].iKor << "\t";
					cout << "��  �� : " << tStudentArr[i].iEng << "\t";
					cout << "��  �� : " << tStudentArr[i].iMath << endl;
					cout << "��  �� : " << tStudentArr[i].iTotal << "\t";
					cout << "��  �� : " << tStudentArr[i].fAverage << endl << endl << endl;


					cout << "�ش� �л��� �����Ͻðڽ��ϱ�? (Y/N) : ";

					bool bLoop = true;
					while (bLoop)
					{
						char cInput;
						cin >> cInput;

						switch (cInput)
						{
						case 'Y':
						case 'y':
							for (int j = i; j < iStudentCount - 1; j++)
							{
								tStudentArr[j] = tStudentArr[j + 1];
							}

							--iStudentCount;

							cout << strName << " �л��� �����Ͽ����ϴ�." << endl;
							bLoop = false;
							break;

						case 'N':
						case 'n':
							bLoop = false;
							break;
						}
					}

					break;
				}
			}



			break;
		case MENU_SEARCH:
			system("cls");
			cout << "____________ �л� ���� �˻� ____________" << endl << endl;
			cout << "�˻��� �̸��� �Է����ּ��� : ";
			cin.ignore(1024, '\n');
			cin.getline(strName, NAME_SIZE);

			// =========== �˻� ����
			system("cls");
			cout << "____________ �л� �˻� ��� ____________" << endl << endl;

			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "��  �� : " << tStudentArr[i].strName << endl;
					cout << "��  �� : " << tStudentArr[i].iNumber << endl;
					cout << "��  �� : " << tStudentArr[i].strAddress << endl;
					cout << "����ó : " << tStudentArr[i].strPhoneNumber << endl;

					switch (tStudentArr[i].eSex)
					{
					case MALE:
						cout << "��  �� : ��" << endl;
						break;
					case FEMALE:
						cout << "��  �� : ��" << endl;
						break;
					}

					cout << "��  �� : " << tStudentArr[i].cGrade << endl;
					cout << "��  �� : " << tStudentArr[i].iKor << "\t";
					cout << "��  �� : " << tStudentArr[i].iEng << "\t";
					cout << "��  �� : " << tStudentArr[i].iMath << endl;
					cout << "��  �� : " << tStudentArr[i].iTotal << "\t";
					cout << "��  �� : " << tStudentArr[i].fAverage << endl << endl << endl;
				}
			}


			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "____________ ��ü �л� ��� ____________" << endl << endl;

			for (int i = 0; i < iStudentCount; i++)
			{
				cout << "��  �� : " << tStudentArr[i].strName << endl;
				cout << "��  �� : " << tStudentArr[i].iNumber << endl;
				cout << "��  �� : " << tStudentArr[i].strAddress << endl;
				cout << "����ó : " << tStudentArr[i].strPhoneNumber << endl;

				switch (tStudentArr[i].eSex)
				{
				case MALE:
					cout << "��  �� : ��" << endl;
					break;
				case FEMALE:
					cout << "��  �� : ��" << endl;
					break;
				}

				cout << "��  �� : " << tStudentArr[i].cGrade << endl;
				cout << "��  �� : " << tStudentArr[i].iKor << "\t";
				cout << "��  �� : " << tStudentArr[i].iEng << "\t";
				cout << "��  �� : " << tStudentArr[i].iMath << endl;
				cout << "��  �� : " << tStudentArr[i].iTotal << "\t";
				cout << "��  �� : " << tStudentArr[i].fAverage << endl << endl << endl;
			}

			break;
		default:
			cout << "�޴��� �߸� �����Ͽ����ϴ�." << endl;
			break;
		}

		system("pause");

	}

	cout << endl << "���α׷��� �����մϴ�." << endl << endl;

	return 0;
}