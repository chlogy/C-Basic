#include <iostream>

using namespace std;
/*
1. �������� 2�ܺ��� 9�ܱ��� ����ϴ� ��ø for���� �����

2. ���� �Ʒ��� ���·� ��µǰ� �Ѵ�.
*
**
***
****
*****

3. ���� �Ʒ��� ���·� ��µǰ� �Ѵ�.
*****
****
***
**
*

4. ���� �Ʒ��� ���·� ��µǰ� �Ѵ�.
   *
  ***
 *****
*******
*/
int main()
{
	cout << "1. ===================" << endl;

	for (int i = 1; i <= 9; i++)
	{
		cout << i << "��" << endl;
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << endl;
	}

	cout << endl;
	cout << "2. ===================" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
	cout << "3. ===================" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
	cout << "4. ===================" << endl;

	// ���� : 3, 2, 1
	// �� : 1 3 5 7 

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < i * 2 + 1; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;
	cout << "5. ===================" << endl;
	/*
		2��	3��	4��
		5��	6��	7��
		8��	9��	10��
	*/

	for (int i = 2; i < 11; i += 3)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i * j << "\t";
			cout << i + 1 << " * " << j << " = " << (i + 1) * j << "\t";
			cout << i + 2 << " * " << j << " = " << (i + 2) * j << endl;
		}
		cout << endl;
	}


	cout << endl;
	cout << "6. ===================" << endl;
/*
	   *
	  ***
	 *****
	******* 
	 *****
	  ***
	   *
*/

	
	int iLine = 7;
	int iCount = 0;

	cout << "Line�� �Է��ϼ��� : ";
	cin >> iLine;
	
	if (iLine % 2 == 0)
		iLine++;

	for (int i = 0; i < iLine; i++)
	{
		// ���� : 3 2 1 0 1 2 3
		//   �� : 1 3 5 7 5 3 1

		iCount = i;

		if (i > iLine / 2)
			iCount = iLine - 1 - i;

		for (int j = 0; j < iLine - iCount; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < iCount * 2 + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}