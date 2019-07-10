#pragma once
#include<iostream>
namespace BASEALG
{
	// ������16����ֵ�������η�
	// ��Ŀ��ʵ�ֺ��� 
	// double power(double base, int exponent),
	// ��base��exponent�η���
	// ����ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

	// һ�������ָ��Ϊ������
	double power(double base, int exponent);

	// �������ۣ�
	//  ��1��ָ��Ϊ��������
	//	��2��ָ��Ϊ�����������⴦������Ϊ0��ָ��Ϊ��
	double powerOpt1(double base, int exponent);


	// �ݹ鷨��
	// a^n = a^(n/2) * a^(n/2)	nΪż��
	// a^n = a^((n-1)/2) * a^((n-1)/2) * a nΪ����
	// ���������
	// a^0 = 1
	// a^1 = a
	// ʱ�临�Ӷȣ�O(log n)
	double powerOpt2(double base, int exponent);

	double powerWithUnsignedExponent(double base,
		unsigned int exponent);

	// ������17����ӡ��1������nλ��
	// ��Ŀ����������n����˳���ӡ����1������nλʮ����������������3�����ӡ��1��2��3һֱ������3λ��999��
	/*
	���⣺
	*/
	/*
	����1��������
	���ۣ�������������׳�Բ�Ĵ���
	*/
	void print1ToMaxOfNDigits(int n);

	/*
	����2�����ַ����������������
	�ⷨ��
		���Ȱ��ַ����е�ÿһ�����ֶ���ʼ��Ϊ'0'��Ȼ��ÿһ��Ϊ�ַ�����ʾ�����ּ�1���ٴ�ӡ������
		Ҫ�������£�һ�����ַ�������������ģ��ӷ������ǰ��ַ����������ִ�ӡ������
	*/
	void printToMaxOfNDigitsOpt1(int n);
	/*
	���ܣ�����increment()ʵ���ڱ�ʾ���ַ���number������1
	���룺���ַ�����ʾ������
	����������־
	֪ʶ�㣺�ַ�����
	*/
	bool increment(char* number);
	void printNumber(char* number);

	/*
	����3���ݹ鷨
	*/
	void printToMaxOfNDigitsOpt2(int n);
	void print1ToMaxOfNDigitsRecursively(char* number, int length, int index);
}