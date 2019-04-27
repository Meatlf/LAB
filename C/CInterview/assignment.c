#include<stdio.h>
#include"define.h"

// 主要理解按位与和逻辑与的区别
void Assignment() 
{
	int x = 3, y, z;

	x *= (y = z = 4);
	printf("z = %d\n", z);
	printf("y = %d\n", y);
	printf("x = %d\n", x);

	x = (y = z);printf("x = %d\n", x);
	x = (y == z);printf("x = %d\n", x);
	x = (y & z);printf("x = %d\n", x);	// 按位与
	z = 3;
	x = (y & z);printf("x = %d\n", x);
	x = (y && z);printf("x = %d\n", x);	// 逻辑与

	y = 4;
	x = (y | z);printf("x = %d\n", x);
	x = (y || z);printf("x = %d\n", x);

	x = (y == z) ? 4 : 5;
	printf("x = %d\n", x);

	x = (y == z) ? 1 : (y < z) ? 2 : 3;
	printf("x = %d\n", x);
}