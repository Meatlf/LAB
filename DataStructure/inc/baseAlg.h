#pragma once
#include<iostream>
namespace BASEALG
{
	// 面试题16：数值的整数次方
	// 题目：实现函数 
	// double power(double base, int exponent),
	// 求base的exponent次方。
	// 不得使用库函数，同时不需要考虑大数问题。

	// 一般情况：指数为正整数
	double power(double base, int exponent);

	// 分类讨论：
	//  （1）指数为正整数；
	//	（2）指数为负整数；特殊处理：底数为0，指数为负
	double powerOpt1(double base, int exponent);


	// 递归法：
	// a^n = a^(n/2) * a^(n/2)	n为偶数
	// a^n = a^((n-1)/2) * a^((n-1)/2) * a n为奇数
	// 基本情况：
	// a^0 = 1
	// a^1 = a
	// 时间复杂度：O(log n)
	double powerOpt2(double base, int exponent);

	double powerWithUnsignedExponent(double base,
		unsigned int exponent);

	// 面试题17：打印从1到最大的n位数
	// 题目：输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1、2、3一直到最大的3位数999。
	/*
	解题：
	*/
	/*
	方法1：暴力法
	评价：会造成溢出，健壮性差的代码
	*/
	void print1ToMaxOfNDigits(int n);

	/*
	方法2：用字符串来解决大数问题
	解法：
		首先把字符串中的每一个数字都初始化为'0'，然后每一次为字符串表示的数字加1，再打印出来。
		要做两件事：一是在字符串表达的数字上模拟加法；二是把字符串表达的数字打印出来。
	*/
	void printToMaxOfNDigitsOpt1(int n);
	/*
	功能：函数increment()实现在表示的字符串number上增加1
	输入：用字符串表示的整数
	输出：溢出标志
	知识点：字符运算
	*/
	bool increment(char* number);
	void printNumber(char* number);

	/*
	方法3：递归法
	*/
	void printToMaxOfNDigitsOpt2(int n);
	void print1ToMaxOfNDigitsRecursively(char* number, int length, int index);
}