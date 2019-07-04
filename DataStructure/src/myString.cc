#include<memory>
#include"myString.h"

int STRING::temp_string_length(const char* string, int length)
{
	int num = 0;
	int i = 0;
	for (;i < length;i++)
	{
		if (string[i] == ' ')
			num++;
	}
	return length + 2 * num;
}

int STRING::replace_blank(const char* string, int length, int lengthTemp, char* replaceBlankString)
{
	char* p0 = (char*)(string + length - 1);
	char* p1 = replaceBlankString + lengthTemp - 1;

	do{
		if (*p0 == ' ')
		{
			p0--;
			*p1-- = '0';
			*p1-- = '2';
			*p1-- = '%';
		}
		else
		{
			*p1 = *p0;
			p1--;
			p0--;
		}
	} while (p0 >= string);
	return lengthTemp;
}