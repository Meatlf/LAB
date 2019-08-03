#include <stdio.h>

void __stdcall swap(int& a, int& b);

int main(int argc, char* argv)
{
	int a = 1, b = 2;
	printf("before swap: a = %d, b = %d\r\n", a, b);
	swap(a, b);
	printf("after swap: a = %d, b = %d\r\n", a, b);
}

void __stdcall swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}