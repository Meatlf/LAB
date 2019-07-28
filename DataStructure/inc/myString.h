#pragma once
namespace STRING
{
	/*
	面5：替换空格
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

	/*
	面19： 正则表达式匹配
	
	题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。
	模式中的'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
	
	解题分析：
		两种数据做对比，一是标准字符串、二是模式字符串

	Q：如何匹配一个字符？
	A：模式中的字符和标准字符串相应位置的字符相同或模式中的字符为'.'
	*/
	bool match(char* str, char* pattern);
	bool matchCore(char* str, char* pattern);

	/*
	面20：表示数值的字符串

	题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串“+100”、“5e2”、“-123”及“-1E-16”都表示数值，但“12e”、“1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是。

	Q：表示数值的字符串遵循模式是什么？
	A：A[.[B]][e|EC]或者.B[e|EC]
	*/
	bool isNumeric(const char* str);
	/*
	函数scanInteger扫描可能可以表示正负的‘+’或者‘-’为起始地0~9的数位（类似于一个可能带正负符号的整数），用来匹配前面数值模式中的A和C部分。
	*/
	bool scanInteger(const char** str);
	/*
	函数scanUnsignedInteger用来扫描字符串中0~9的数位（类似于一个无符号整数），可以用来匹配前面数值模式中的B部分
	*/
	bool scanUnsignedInteger(const char** str);
}