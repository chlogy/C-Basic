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
	printf("&iNumber = %d %x\n\n", &iNumber, &iNumber);			// 변수 iNumber의 주소값


	printf("*pNumber = %d\n", *pNumber);					// 포인터 pNumber가 가리키고 있는곳에 저장된 값
	printf("pNumber = %d %x\n", pNumber, pNumber);				// 포인터 pNumber에 저장된 주소값(iNumber의 주소값)
	printf("&pNumber = %d %x\n\n", &pNumber, &pNumber);			// 포인터 pNumber의 주소값

	printf("*ppNumber = %d %x\n", *ppNumber, *ppNumber);			// 포인터 ppNumber가 가리키고 있는곳에 저장된 값
	printf("ppNumber = %d %x\n", ppNumber, ppNumber);				// 포인터 ppNumber에 저장된 주소값(포인터 pNumber의 주소값)
	printf("&ppNumber = %d %x\n\n", &ppNumber, &ppNumber);		// 포인터 ppNumber의 주소값

	printf("&*ppNumber = %d %x\n", &*ppNumber, &*ppNumber);		// 포인터 ppNumber가 가리키고 있는곳의 주소(포인터 pNumber의 주소값)
	printf("&**ppNumber = %d %x\n\n", &**ppNumber, &**ppNumber);	// iNumber의 주소값

												// 변수 iNumber에 저장된 값에 접근하는 방법
	printf("iNumber = %d\n", iNumber);
	printf("*pNumber = %d\n", *pNumber);
	printf("**ppNumber = %d\n\n", **ppNumber);

	return 0;
}