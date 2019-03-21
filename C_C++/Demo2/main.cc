#include <stdio.h>

int main(void)
{
	char buffer[200], s[] = "HelloWorld!", c = 'l';
	int i = 35, j;
	float fp = 1.7320534f;
	// Format and print various data:
#ifdef _WIN32
	j = sprintf_s(buffer, sizeof(buffer), "A%s\n", s);
	j += sprintf_s(buffer + j, sizeof(buffer)- j, " C%c\n", c);
	j += sprintf_s(buffer + j, sizeof(buffer)- j, " Integer: %d\n", i);
	j += sprintf_s(buffer + j, sizeof(buffer)- j, " Real: %f\n", fp);
	printf_s("Output:\n%s\ncharacter count = %d\n", buffer, j);
#endif

#ifdef linux
	j=snprintf(buffer, sizeof(buffer), "%s\n", s); 
    	printf("%sn\n",buffer);
	printf("%d\n",j);
#endif
	printf("Done!\n");
	return 0;
}
