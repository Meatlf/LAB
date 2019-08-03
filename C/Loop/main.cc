#include <stdio.h>

int main()
{
	/* 局部变量定义 */
	int a = 10;

	/* do 循环执行 */
	do
	{
		if (a == 15)
		{
			/* 跳过迭代 */
			a++;
			continue;
		}
		printf("a's value: %d\n", a);
		a++;
	} while (a < 20);
	printf("\n");

	/* 局部变量定义 */
	int b = 20;

	for (int i = 0; i < 3; i++) {
		do
		{
			if (b == 22)
			{
				/* 跳过迭代 */
				b++;
				break;
			}
			printf("b's value: %d\n", b);
			b++;

		} while (b < 30);
		printf("\n");
	}

	return 0;
}