#include"define.h"

void Const()
{
	const int x = 1;
	int b = 10;
	int c = 20;

	// 修饰指针指向的变量，即指针指向的值常量
	const int* a1 = &b;	

	// 修饰指针本身，即指针本身为常量
	int* const a2 = &b;

	// 表示不仅指针本身不能修改，并且其指向的内容也不能修改
	const int* const a3 = &b;

	// 常量不可以再赋值
	// x = 2;

	printf("*a1 = %d,a1 = %p\n", *a1, a1);

	a1 = &c;
	// *a1 = 1;
	printf("*a1 = %d,a1 = %p\n", *a1, a1);

	// a2 = &c;
	*a2 = 1;
	printf("*a2 = %d,a2 = %p\n", *a2, a2);

	// a3 = &c;
	// *a3 = 1;
}