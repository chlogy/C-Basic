#include <iostream>

using namespace std;

/*
	�Լ� :	����� ������ش�.	������ ����� �� �ִ� ����� ������شٰ� �� �� �ִ�.
			Ư�� ��Ȳ�� ���� ���ϴ� ����� �����ϵ��� �����ϴ� �ڵ带 ����� ���̴�.

	���� :	����Ÿ�� �Լ���(�Ű����� == parameter == ����) {}�� ���·� ������ �ȴ�.
	
	����Ÿ�� :	�� �ش� �Լ��� �ǵ��� ����� �����ϰ� �׿� ���� ����� ��ȯ�ؾ� �� �� �� ������ Ÿ�Կ� �µ��� �������ش�.			
				������ ��ȯ�ؾ��� ���� int Type, �Ǽ��� ��ȯ�ؾ� �� ���� float, double ��� ���� ���� �ʿ��� ������ Ÿ�Կ� �°� �������ش�.

	�Լ��� :	�Լ��� �̸��� �ǹ��Ѵ�.
			�Լ��� �̸��� ���� ������ �� �Լ��� �ϴ� ���� ��Ȯ�ϰ� ǥ���� �ִ� ���� ����.

	�Ű�����, �Ķ���� :	�ش� �Լ��� ����� �� �Ѱ��� ���� �ִ� ��� �Ķ���͸� Ȱ���Ѵ�.

	�ش� �Լ��� ȣ���ϸ� �ڵ�� �ȿ� �ִ� �ڵ尡 ���۵ȴ�.
*/

int Sum(int x, int y)
{
	cout << x + y << endl;
	return x + y;
}

void OutputText()
{
	cout << "Hello World" << endl;
}

void __Print(const char* _Text)
{
	cout << _Text << endl;
}

void ChangeNumber(int iNumber)		// Call by Value
{
	iNumber = 9999;
}

int ChangeNumber3(int iNumber)	// Call by Value
{
	iNumber = 9999;

	return iNumber;
}

void ChangeNumber(int* pNumber)	// Call by Address
{
	*pNumber = 9999;
}

void Output(int iNum1, int iNum2 = 30)
{
	cout << iNum1 << endl;
	cout << iNum2 << endl;
}

void Output(int iNum1)
{
	cout << iNum1 << endl;
}



int main()
{
	// �Լ��� ȣ���� ���� �Լ���(�Ű�����); �� ���·� ȣ���ϰ� �ȴ�.

	cout << Sum(10, 20) << endl;

	Sum(20, 40);

	OutputText();

	__Print("������ �ȳ�");

	int iNumber = 0;
	iNumber = ChangeNumber3(iNumber);
	// ChangeNumber2(&iNumber);
	
	
	ChangeNumber(&iNumber);
	cout << iNumber << endl;

	/*
		�Լ� �����ε� : ���� �̸��� �Լ��� ����� �ٸ� �Լ��� �������ؼ� ����� ��.

		�����ε��� ���� : ������ ���� Ȥ�� Ÿ���� �޶�� �����ε��� �����ȴ�.
						 �߿��� �� : return type�� ������ ���� �ʴ´�.
	*/

	/*
		�Լ��� ����Ʈ ���� :	�Ķ���ʹ� �⺻������ ���� �Ѱܹް� ����Ǿ� �ִ�.
							�׷��� ���ڿ� �⺻���� �����صθ� ���ڸ� �Ѱ����� ���� ��� �⺻ ������ ���� �ǰ�,
							���ڸ� �Ѱ��� ��� �Ѱܹ��� ������ ���ڸ� �����ϴ� ����̴�.

							����Ʈ ���ڴ� ���� �����ʺ��� �Ѱ���� �Ѵ�.

	*/

	Output(10, 20);
	// Output(10);

	return 0;
}