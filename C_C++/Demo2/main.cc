#include <stdio.h>
int main(void)
{
	char buffer[200], s[] = "B", c = 'l';
	int i = 35, j;
	float fp = 1.7320534f;
	// Format and print various data:
	j = sprintf_s(buffer, 200, "A%s\n", s);
	j += sprintf_s(buffer + j, 200 - j, " C%c\n", c);
	j += sprintf_s(buffer + j, 200 - j, " Integer: %d\n", i);
	j += sprintf_s(buffer + j, 200 - j, " Real: %f\n", fp);
	printf_s("Output:\n%s\ncharacter count = %d\n", buffer, j);
	printf("Done!\n");
	return 0;
}
