#include<stdio.h>
#include"define.h"

// ��Ҫ��ⰴλ����߼��������
void Assignment() 
{
	int x = 3, y, z;

	x *= (y = z = 4);
	printf("z = %d\n", z);
	printf("y = %d\n", y);
	printf("x = %d\n", x);

	x = (y = z);printf("x = %d\n", x);
	x = (y == z);printf("x = %d\n", x);
	x = (y & z);printf("x = %d\n", x);	// ��λ��
	z = 3;
	x = (y & z);printf("x = %d\n", x);
	x = (y && z);printf("x = %d\n", x);	// �߼���

	y = 4;
	x = (y | z);printf("x = %d\n", x);
	x = (y || z);printf("x = %d\n", x);

	x = (y == z) ? 4 : 5;
	printf("x = %d\n", x);

	x = (y == z) ? 1 : (y < z) ? 2 : 3;
	printf("x = %d\n", x);
}