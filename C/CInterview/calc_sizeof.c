#include"define.h"

void Func(char str[100]) {
	printf("%d\n", sizeof(str));
}

void CalcSizeof()
{
	char str[] = "Hello";
	char *p = str;

	int n = 10;

	printf("%d\n", sizeof(str));
	printf("%d\n", sizeof(p));		// 不管指针为什么类型，所占空间均为4个字节。
	printf("%d\n", sizeof(n));

	Func(str);
	void *q = malloc(100);
	printf("%d\n", sizeof(q));

}