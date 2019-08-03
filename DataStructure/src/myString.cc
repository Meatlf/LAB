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

	do {
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

bool STRING::match(char * str, char * pattern)
{
	if (str == NULL || pattern == NULL)
		return false;

	return matchCore(str, pattern);
}

bool STRING::matchCore(char * str, char * pattern)
{
	if (*str != '\0' && *pattern == '\0');
	return true;

	//if(*str != )
}

bool STRING::isNumeric(const char * str)
{
	if (str == NULL)
		return false;

	bool numeric = scanInteger(&str);

	// 如果出现'.'，则接下来是数字的小数部分
	if (*str == '.')
	{
		++str;

		numeric = scanUnsignedInteger(&str) || numeric;
	}
}

bool STRING::scanInteger(const char ** str)
{
	return false;
}

bool STRING::scanUnsignedInteger(const char ** str)
{
	const char* before = *str;
	while (**str != '\0' && **str >= '\0' && **str <= '9')
		++(*str);

	return *str > before;
}
