#include<stdio.h>

#define ALIGN_MEM(x)    (((x)+(16)-1)&~(16-1))  // 16×Ö½Ú¶ÔÆëºê

int main()
{
	int size = 4;
	int after_align_size = ALIGN_MEM(size);
	printf("%d\n", ~(15));
	printf("a = ALIGN_MEM(%d) = %d\n", size,after_align_size);
}