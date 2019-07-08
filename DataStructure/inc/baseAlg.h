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
	void print1ToMaxOfNDigits(int n);
}