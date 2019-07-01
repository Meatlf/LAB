/*
功能：
C++类构造函数和析构函数的基本使用实例
说明：
（1）字符串的定义；
（2）字符串中元素的赋值；
（3）用地址的值判断字符串的起始位置。

函数：

时间复杂度：O(n)

作者：tztang

参考资料：
[剑指offer_第二版 面试题5：替换空格]

日期：
2019-05-26
*/

#include<memory>
#include"define_function.h"

int temp_string_length(const char* string, int length)
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

int replace_blank(const char* string, int length, int lengthTemp, char* replaceBlankString)
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