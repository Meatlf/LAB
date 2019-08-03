#include"define.h"

void SwapWithoutIntermediateVariables()
{
	int a=3, b=4;
	int temp = a;	//使用局部变量temp完成交换
	a = b;
	b = temp;
	printf("a = %d, b = %d\n", a, b);

	a = a + b;	//使用加减运算完成交换
	b = a - b;
	a = a - b;
	printf("a = %d, b = %d\n", a, b);

	a ^= b;
	b ^= a;
	a ^= b;
	printf("a = %d, b = %d\n", a, b);
}