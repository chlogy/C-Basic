#include <stdio.h>	// ������� ���� ��ó����ɹ�

void main()
{
	char str1[9] = "Computer";
	const char* str2 = "Computer";

	printf("str1 = %s\n", str1);
	printf("str2 = %s\n\n", str2);

	str2 = "Science";
	//str1 = "Science";  // ���� �Ұ���

	printf("str1 = %s\n", str1);
	printf("str2 = %s\n\n", str2);

	str1[0] = 'c';
	//str2[0] = 'c';  // ���� �Ұ���

	printf("str1 = %s\n", str1);
	printf("str2 = %s\n\n", str2);

}
