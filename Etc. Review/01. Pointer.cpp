#include <stdio.h>

int main()
{
	int		iNumber;
	int*    pNumber;
	int**	ppNumber;

	iNumber = 100;
	pNumber = &iNumber;
	ppNumber = &pNumber;

	printf("iNumber = %d\n", iNumber);
	printf("&iNumber = %d %x\n\n", &iNumber, &iNumber);			// ���� iNumber�� �ּҰ�


	printf("*pNumber = %d\n", *pNumber);					// ������ pNumber�� ����Ű�� �ִ°��� ����� ��
	printf("pNumber = %d %x\n", pNumber, pNumber);				// ������ pNumber�� ����� �ּҰ�(iNumber�� �ּҰ�)
	printf("&pNumber = %d %x\n\n", &pNumber, &pNumber);			// ������ pNumber�� �ּҰ�

	printf("*ppNumber = %d %x\n", *ppNumber, *ppNumber);			// ������ ppNumber�� ����Ű�� �ִ°��� ����� ��
	printf("ppNumber = %d %x\n", ppNumber, ppNumber);				// ������ ppNumber�� ����� �ּҰ�(������ pNumber�� �ּҰ�)
	printf("&ppNumber = %d %x\n\n", &ppNumber, &ppNumber);		// ������ ppNumber�� �ּҰ�

	printf("&*ppNumber = %d %x\n", &*ppNumber, &*ppNumber);		// ������ ppNumber�� ����Ű�� �ִ°��� �ּ�(������ pNumber�� �ּҰ�)
	printf("&**ppNumber = %d %x\n\n", &**ppNumber, &**ppNumber);	// iNumber�� �ּҰ�

												// ���� iNumber�� ����� ���� �����ϴ� ���
	printf("iNumber = %d\n", iNumber);
	printf("*pNumber = %d\n", *pNumber);
	printf("**ppNumber = %d\n\n", **ppNumber);

	return 0;
}