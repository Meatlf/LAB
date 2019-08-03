#pragma once
/*
功能：

说明：


函数：

作者：

参考资料：数据结构教程（第5版）第5章 递归
日期：
2019-06-
*/
#include"link_list.h"
namespace RECURSION {

	// 算n的阶乘（假设n不为0）
	// 递归模型：
	// f(1) = 1         ,  当 n == 1
	// f(n) = f(n-1) * 1， 当 n != 1
	int factorial(int n);

	/* 面10 斐波拉契数列
	   求斐波拉契数列的第n项*/
	// 方法1：递归法
	// 算法时间复杂度：O(n^2)
	// 评价：有大量重复计算，性能低
	long long fibonacciRecursiveMethod(unsigned int n);
	// 方法2：迭代法
	// 算法时间复杂度：O(n)
	long long fibonacciIterativeMethod(unsigned int n);

	// 采用递归和非递归方法求解Handoi问题
	// 目的：领会基本递归算法设计和递归到非递归的转换方法
	// 内容：采用递归和非递归方法求解Hanoi问题，输出3个盘片的移动过程
	// 算法复杂度：O(n^2)
	void Hanoil(int n, char X, char Y, char Z);

	// 上楼可以一步上一阶，也可以一步上两阶，设计一个递归算法，计算共用多少种不同的走法
	long long stepFibonacci(unsigned int n);

	// 设计一个算法求正整数n的位数
	int integerNumber(unsigned int n);

	// 设计一个递归算法，利用顺序串的基本运算求串s的逆序
	// ToDo

	// 设计一个不带表头节点的单链表L，设计一个递归算法count(L)求以L为首结点指针的单链表的结点个数
	int count(ListNode* L);

	// 设有一个不带表头节点的单链表L，设计两个递归算法，traverse(L)正向输出单链表L的所有结点值，
	// traverseR(L)反向输出单链表L的所有结点值。
	void traverse(ListNode* L);

	// 采用递归算法求实数数组A[0..n-1]中的最小值
	int minValue(int iArray[], int n);
}