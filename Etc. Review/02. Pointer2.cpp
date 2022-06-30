#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

void allocMemory(int** ptr, int m_size)
{
	*ptr = (int*)malloc(sizeof(int) * m_size);    // ������ ptr�� ����Ű�� �ִ� ���� ����� ��

	for (int i = 0; i < m_size; i++)
	{
		(*ptr)[i] = (i + 1) * 10;
	}

	printf("=== allocMemory �Լ� ������ ��� ===\n");
	for (int i = 0; i < m_size; i++)
	{
		printf("%d\n", (*ptr)[i]);
	}
}

int main()
{
	int* numPtr;
	int size = 10;

	allocMemory(&numPtr, size);						// ������ numPtr�� �ּҰ��� ����

	for (int i = 0; i < size; i++)
	{
		numPtr[i] = numPtr[i] + 1;
	}

	printf("=== main �Լ� ������ ��� ===\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", numPtr[i]);
	}

	free(numPtr);

	return 0;
}

