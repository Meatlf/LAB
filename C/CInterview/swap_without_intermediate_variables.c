#include"define.h"

void SwapWithoutIntermediateVariables()
{
	int a=3, b=4;
	int temp = a;	//ʹ�þֲ�����temp��ɽ���
	a = b;
	b = temp;
	printf("a = %d, b = %d\n", a, b);

	a = a + b;	//ʹ�üӼ�������ɽ���
	b = a - b;
	a = a - b;
	printf("a = %d, b = %d\n", a, b);

	a ^= b;
	b ^= a;
	a ^= b;
	printf("a = %d, b = %d\n", a, b);
}