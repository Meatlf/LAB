#pragma once
namespace STRING
{
	/*
	������5���滻�ո�
	��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"�����磬����"We are happy."�������"We%20are%20happy."��

	������
		����temp_string_length()����������ַ�������"�滻�ո�"��ĳ��ȣ�
		Ȼ����replace_blank()��β��ͷ"�滻�ո�"

	Ҫ�㣺
		��1���ַ����Ķ��壻
		��2���ַ�����Ԫ�صĸ�ֵ��
		��3���õ�ַ��ֵ�ж��ַ�������ʼλ�ã�
		��4��"����˼ά"��

	ʱ�临�Ӷȣ�O(n)

	���ߣ�tztang

	�ο����ϣ�
	[��ָoffer_�ڶ��� ������5���滻�ո�]

	���ڣ�
	2019-05-26
	3019-07-02
	*/
	int temp_string_length(const char* string, int length);
	int replace_blank(const char* string, int length, int lengthTemp, char* replaceBlankString);
}