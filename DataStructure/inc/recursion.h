#pragma once
/*
���ܣ�

˵����


������

���ߣ�

�ο����ϣ����ݽṹ�̳̣���5�棩��5�� �ݹ�
���ڣ�
2019-06-
*/
#include"link_list.h"
namespace RECURSION {

	// ��n�Ľ׳ˣ�����n��Ϊ0��
	// �ݹ�ģ�ͣ�
	// f(1) = 1         ,  �� n == 1
	// f(n) = f(n-1) * 1�� �� n != 1
	int factorial(int n);

	/* ��10 쳲���������
	   ��쳲��������еĵ�n��*/
	// ����1���ݹ鷨
	// �㷨ʱ�临�Ӷȣ�O(n^2)
	// ���ۣ��д����ظ����㣬���ܵ�
	long long fibonacciRecursiveMethod(unsigned int n);
	// ����2��������
	// �㷨ʱ�临�Ӷȣ�O(n)
	long long fibonacciIterativeMethod(unsigned int n);

	// ���õݹ�ͷǵݹ鷽�����Handoi����
	// Ŀ�ģ��������ݹ��㷨��ƺ͵ݹ鵽�ǵݹ��ת������
	// ���ݣ����õݹ�ͷǵݹ鷽�����Hanoi���⣬���3����Ƭ���ƶ�����
	// �㷨���Ӷȣ�O(n^2)
	void Hanoil(int n, char X, char Y, char Z);

	// ��¥����һ����һ�ף�Ҳ����һ�������ף����һ���ݹ��㷨�����㹲�ö����ֲ�ͬ���߷�
	long long stepFibonacci(unsigned int n);

	// ���һ���㷨��������n��λ��
	int integerNumber(unsigned int n);

	// ���һ���ݹ��㷨������˳�򴮵Ļ���������s������
	// ToDo

	// ���һ��������ͷ�ڵ�ĵ�����L�����һ���ݹ��㷨count(L)����LΪ�׽��ָ��ĵ�����Ľ�����
	int count(ListNode* L);

	// ����һ��������ͷ�ڵ�ĵ�����L����������ݹ��㷨��traverse(L)�������������L�����н��ֵ��
	// traverseR(L)�������������L�����н��ֵ��
	void traverse(ListNode* L);

	// ���õݹ��㷨��ʵ������A[0..n-1]�е���Сֵ
	int minValue(int iArray[], int n);
}