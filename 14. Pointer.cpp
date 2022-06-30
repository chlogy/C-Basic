#include <iostream>

using namespace std;

int main()
{
	/*
		Pointer :	����Ű��. �Ϲ� ������ �Ϲ����� ���� ����������, ������ ������ �޸� �ּҸ� �����ϰ� �ȴ�.
					��� ���� Ÿ���� ������ Ÿ������ ������ �� �ִ�.

					int ������ �ּҴ� int Pointer ������ ������ �ؾ��Ѵ�.
					�����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������ �޸� �ּҴ� x86 (32��Ʈ), x64(64��Ʈ)�� ������ �Ǵµ�
					
					���� x86���� ������ �� ������ 4byte
					x64�� ������ ���� 8byte�� ���´�.

					�����ʹ� �ڱ� ������ �ƹ��� �ϵ� �� �� ����.
					�ݵ�� �ٸ� ������ �޸� �ּҸ� ������ �־�� ���� �� �� �ִµ� ������ �ִ� �� �޸� �ּҿ� �����ؼ� ���� ������ �� �ִ�.

		���� : ����Ÿ�� * ������; �� ���·� �����Ѵ�.
	*/

	int iNumber = 100;

	/*
		���� ����� *�� �ٿ��ָ� �ش� Ÿ���� ������ ������ ����ȴ�.
		���� �տ� &�� �ٿ��ָ� �ش� ������ �޸� �ּҰ� �ȴ�.
		pNum�� iNumber ������ �޸� �ּҸ� ������ ���� �ȴ�.
		�׷��Ƿ� pNum�� �̿��ؼ� iNumber�� ���� ������ �� �ִ�.
	*/
	int* pNum = &iNumber;
	
	cout << sizeof(int*) << endl;		// 4
	cout << sizeof(char*) << endl;		// 4
	cout << sizeof(double) << endl;		// 8
	cout << sizeof(double*) << endl;	// 4

	/*
		16��Ʈ : 65536
		32��Ʈ : 4,294,967,296
		64��Ʈ : 1800�� ��
	*/
	
	*pNum = 300;

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Address : " << &pNum << endl;

	/*
		pNum�� �̿��ؼ� iNumber�� ���� �����غ���.
		�������� �̿��ؼ� ���� �����ų� ������ �� �ִ�.
		�������� ������ ���� �տ� *�� ���̰� �Ǹ� �������� �ȴ�.
	*/

	/*
		Ư���� ������ : ����������, char*, void*, func*

		�����Ϳ� �迭�� ���� : �迭���� �������̴�.
	*/
	int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int* pArray = iArray;

	cout << "iArray Address : " << iArray << endl;
	cout << "Arr[0] Address : " << &iArray[0] << endl;	
	cout << "Array ptr Data : " << pArray << endl;

	cout << "iArray �� ���� : " << iArray[2] << endl;
	cout << "pArray �� ���� : " << pArray[2] << endl;

	/*
		������ ���� : +, - ������ �����Ѵ�. �׷��� ������ ++, -- ���� ������ �����ϴ�.
					 1�� �����ϰ� �Ǹ� �ܼ��� �޸� �ּҰ��� 1���� �ϴ� ���� �ƴϴ�.
					 int Pointer�� ��� int Type�� �޸� �ּҸ� ���ԵǴµ�, �޸� �ּҿ� 1�� �����ָ�
					 1 ������ �ƴ� ����Ű�� �ش� �����Ͱ� ����Ű�� ���� Ÿ���� ũ�⸸ŭ �����ϰ� �ȴ�.
					 int Pointer�� int�� ũ�⸸ŭ 4��ŭ ���� �����ϰ� �ȴ�.
	*/

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;


	return 0;
}