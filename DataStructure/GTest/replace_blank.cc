/*
���ܣ�
C++�๹�캯�������������Ļ���ʹ��ʵ��
˵����
��1���ַ����Ķ��壻
��2���ַ�����Ԫ�صĸ�ֵ��
��3���õ�ַ��ֵ�ж��ַ�������ʼλ�á�

������

ʱ�临�Ӷȣ�O(n)

���ߣ�tztang

�ο����ϣ�
[��ָoffer_�ڶ��� ������5���滻�ո�]

���ڣ�
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