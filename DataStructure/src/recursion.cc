#include<iostream>
#include<algorithm>
#include"recursion.h"

int RECURSION::factorial(int n)
{
	if (n == 1)
		return 1;
	else
	{
		return factorial(n - 1) * n;
	}
}

long long RECURSION::fibonacciRecursiveMethod(unsigned int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fibonacciRecursiveMethod(n - 1) + fibonacciRecursiveMethod(n - 2);
}

long long RECURSION::fibonacciIterativeMethod(unsigned int n)
{
	int iResult[2] = { 0,1 };
	if (n < 2)
		return iResult[n];
	long long llFibMinusOne = 1;
	long long llFibMinusTwo = 0;
	long long llFibResult = 0;
	for (unsigned int i = 2;i <= n;++i)
	{
		llFibResult = llFibMinusOne + llFibMinusTwo;
		llFibMinusTwo = llFibMinusOne;
		llFibMinusOne = llFibResult;
	}
	return llFibResult;
}

void RECURSION::Hanoil(int n, char X, char Y, char Z)
{
}

long long RECURSION::stepFibonacci(unsigned int n)
{
	long long iResult[2] = { 1,2 };
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		return stepFibonacci(n - 1) + stepFibonacci(n - 2);
	}
}

int RECURSION::integerNumber(unsigned int n)
{
	if (n == 0)
		return 0;
	else if (n > 0)
	{
		return (integerNumber(n / 10) + 1);
	}
}

int RECURSION::count(ListNode * L)
{
	if (L == NULL)
		return 0;
	return count(L->pNext) + 1;
}

void RECURSION::traverse(ListNode * L)
{
	if (L == NULL)
	{
		std::cout << "NULL" << std::endl;
		return;
	}
	std::cout << L->iVal << "->";
	return traverse(L->pNext);
}

int RECURSION::minValue(int iArray[], int n)
{
	if (n == 0)
		return iArray[0];
	return std::min(minValue(iArray, n -1), iArray[n - 1]);
}
