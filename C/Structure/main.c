#include <stdio.h>
#pragma pack (4)

struct A {
	int a;
	char b;
	short c;
}A1;

struct B {
	char b;
	int a;
	short c;
}B1;

int main()
{
	printf("A1's address is %x\n", &A1);
	printf("A1.a's address is %x\n", &A1.a);
	printf("A1.a's size is %d\n", (unsigned int)(void*)&A1.b - (unsigned int)(void*)&A1.a);
	printf("A1.b's size is %d\n", (unsigned int)(void*)&A1.c - (unsigned int)(void*)&A1.b);
	printf("A1's size is %d\n", sizeof(A1));

	printf("B1's Bddress is %x\n", &B1);
	printf("B1.b's Bddress is %x\n", &B1.b);
	printf("B1.a's size is %d\n", (unsigned int)(void*)&B1.a - (unsigned int)(void*)&B1.b);
	printf("B1.b's size is %d\n", (unsigned int)(void*)&B1.c - (unsigned int)(void*)&B1.a);
	printf("B1's size is %d\n", sizeof(B1));

	return 0;
}