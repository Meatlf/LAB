#pragma once
namespace STRING
{
	/*
	面试题5：替换空格
	题目：请实现一个函数，把字符串中的每个空格替换成"%20"，例如，输入"We are happy."，则输出"We%20are%20happy."。

	函数：
		先用temp_string_length()函数计算出字符串经过"替换空格"后的长度，
		然后用replace_blank()从尾到头"替换空格"

	要点：
		（1）字符串的定义；
		（2）字符串中元素的赋值；
		（3）用地址的值判断字符串的起始位置；
		（4）"逆向思维"。

	时间复杂度：O(n)

	作者：tztang

	参考资料：
	[剑指offer_第二版 面试题5：替换空格]

	日期：
	2019-05-26
	3019-07-02
	*/
	int temp_string_length(const char* string, int length);
	int replace_blank(const char* string, int length, int lengthTemp, char* replaceBlankString);
}