#include <stdio.h>

int main()
{
	/* �ֲ��������� */
	int a = 10;

	/* do ѭ��ִ�� */
	do
	{
		if (a == 15)
		{
			/* �������� */
			a++;
			continue;
		}
		printf("a's value: %d\n", a);
		a++;
	} while (a < 20);
	printf("\n");

	/* �ֲ��������� */
	int b = 20;

	for (int i = 0; i < 3; i++) {
		do
		{
			if (b == 22)
			{
				/* �������� */
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