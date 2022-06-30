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

		cout << "1. 학생정보 등록" << endl;
		cout << "2. 학생정보 삭제" << endl;
		cout << "3. 학생정보 검색" << endl;
		cout << "4. 전체학생 출력" << endl;
		cout << "5. 프로그램 종료" << endl << endl;

		cout << "메뉴를 선택하세요 : ";

		int iMenu;
		cin >> iMenu;

		/*
			cin은 오른쪽에 오는 변수가 int type이라면 int type의 변수를 받아야 한다.
			오른쪽 변수 타입에 맞춰서 값을 입력해야 하는데
			실수로 정수가 아닌 문자를 입력할 경우 에러가 발생한다.

			그렇기 때문에 예외처리로 에러가 발생했는지 여기서 체크하여 에러가 발생하면 cin 내부에 에러버퍼를 지워줍니다.

			cin 내부에 입력버퍼가 있는데 입력버퍼는 입력한 값을 저장해놓고 그 값을 변수에 넣어주는 역할을 합니다.
			이 입력버퍼에 \n이 남아있으므로 버퍼를 순회하여 개행이 남아있는지 지워준다.

			buffer : 임시 저장 공간.

			먼저 에러를 체크한다.
			cin.fail()을 했을 때 입력 에러가 발생했을 경우 true를 반환한다.
		*/

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			/*
				입력버퍼에 \n이 남아있으므로 입력버퍼를 검색하여 \n을 지워준다.
				첫 번째에는 검색하고자 하는 버퍼의 크기를 지정한다.
				넉넉하게 1024 바이트를 지정해준 상황이다.

				두 번째에는 찾고자 하는 문자를 넣어준다.
				그래서 입력버퍼 처음부터 \n이 있는 곳 까지 찾아서 그 부분을 모두 지워줘서 다시 입력받을 수 있도록 해준다.
			*/
			continue;


		}

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			cout << "____________ 학생 정보 추가 ____________" << endl << endl;

			if (iStudentCount == STUDENT_MAX)
				break;

			cout << "이  름 : ";
			cin >> tStudentArr[iStudentCount].strName;

			cin.ignore(1024, '\n');
			cout << "주  소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "연락처 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_LENGTH);

			cout << "성  별 (M/F) : ";
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

			cout << "국  어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영  어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수  학 : ";
			cin >> tStudentArr[iStudentCount].iMath;

			// 총점
			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;

			// 평균
			tStudentArr[iStudentCount].fAverage = tStudentArr[iStudentCount].iTotal / 3.f;

			// 성적
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


			// 학번
			tStudentArr[iStudentCount].iNumber = iStdNumber;

			++iStdNumber;
			++iStudentCount;

			break;
		case MENU_DELETE:
			system("cls");
			cout << "____________ 학생 정보 삭제 ____________" << endl << endl;
			cout << "삭제할 이름을 입력해주세요 : ";
			cin.ignore(1024, '\n');
			cin.getline(strName, NAME_SIZE);

			// =========== 삭제 구현
			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "이  름 : " << tStudentArr[i].strName << endl;
					cout << "학  번 : " << tStudentArr[i].iNumber << endl;
					cout << "주  소 : " << tStudentArr[i].strAddress << endl;
					cout << "연락처 : " << tStudentArr[i].strPhoneNumber << endl;

					switch (tStudentArr[i].eSex)
					{
					case MALE:
						cout << "성  별 : 남" << endl;
						break;
					case FEMALE:
						cout << "성  별 : 여" << endl;
						break;
					}

					cout << "성  적 : " << tStudentArr[i].cGrade << endl;
					cout << "국  어 : " << tStudentArr[i].iKor << "\t";
					cout << "영  어 : " << tStudentArr[i].iEng << "\t";
					cout << "수  학 : " << tStudentArr[i].iMath << endl;
					cout << "총  점 : " << tStudentArr[i].iTotal << "\t";
					cout << "평  균 : " << tStudentArr[i].fAverage << endl << endl << endl;


					cout << "해당 학생을 삭제하시겠습니까? (Y/N) : ";

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

							cout << strName << " 학생을 삭제하였습니다." << endl;
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
			cout << "____________ 학생 정보 검색 ____________" << endl << endl;
			cout << "검색할 이름을 입력해주세요 : ";
			cin.ignore(1024, '\n');
			cin.getline(strName, NAME_SIZE);

			// =========== 검색 구현
			system("cls");
			cout << "____________ 학생 검색 결과 ____________" << endl << endl;

			for (int i = 0; i < iStudentCount; i++)
			{
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "이  름 : " << tStudentArr[i].strName << endl;
					cout << "학  번 : " << tStudentArr[i].iNumber << endl;
					cout << "주  소 : " << tStudentArr[i].strAddress << endl;
					cout << "연락처 : " << tStudentArr[i].strPhoneNumber << endl;

					switch (tStudentArr[i].eSex)
					{
					case MALE:
						cout << "성  별 : 남" << endl;
						break;
					case FEMALE:
						cout << "성  별 : 여" << endl;
						break;
					}

					cout << "성  적 : " << tStudentArr[i].cGrade << endl;
					cout << "국  어 : " << tStudentArr[i].iKor << "\t";
					cout << "영  어 : " << tStudentArr[i].iEng << "\t";
					cout << "수  학 : " << tStudentArr[i].iMath << endl;
					cout << "총  점 : " << tStudentArr[i].iTotal << "\t";
					cout << "평  균 : " << tStudentArr[i].fAverage << endl << endl << endl;
				}
			}


			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "____________ 전체 학생 출력 ____________" << endl << endl;

			for (int i = 0; i < iStudentCount; i++)
			{
				cout << "이  름 : " << tStudentArr[i].strName << endl;
				cout << "학  번 : " << tStudentArr[i].iNumber << endl;
				cout << "주  소 : " << tStudentArr[i].strAddress << endl;
				cout << "연락처 : " << tStudentArr[i].strPhoneNumber << endl;

				switch (tStudentArr[i].eSex)
				{
				case MALE:
					cout << "성  별 : 남" << endl;
					break;
				case FEMALE:
					cout << "성  별 : 여" << endl;
					break;
				}

				cout << "성  적 : " << tStudentArr[i].cGrade << endl;
				cout << "국  어 : " << tStudentArr[i].iKor << "\t";
				cout << "영  어 : " << tStudentArr[i].iEng << "\t";
				cout << "수  학 : " << tStudentArr[i].iMath << endl;
				cout << "총  점 : " << tStudentArr[i].iTotal << "\t";
				cout << "평  균 : " << tStudentArr[i].fAverage << endl << endl << endl;
			}

			break;
		default:
			cout << "메뉴를 잘못 선택하였습니다." << endl;
			break;
		}

		system("pause");

	}

	cout << endl << "프로그램을 종료합니다." << endl << endl;

	return 0;
}