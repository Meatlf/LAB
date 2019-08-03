#include<iostream>
#include "array.h"

int ARRAY::repeatNumber(int iArray[], int size)
{
	int i;
	int iTemp;
	if (iArray == NULL || size <= 0)
		return -1;

	for (i = 0;i < size;++i)
		if (iArray[i]<0 || iArray[i]>size - 1)
			return -1;

	for (i = 0;i < size;i++)
	{
		while (iArray[i] != i)
		{
			if (iArray[i] == iArray[iArray[i]])
			{
				return iArray[i];
			}
			iTemp = iArray[i];
			iArray[i] = iArray[iTemp];
			iArray[iTemp] = iTemp;
		}
	}
	return -1;
}

int ARRAY::minSubArrayLen(int s, std::vector<int>& nums)
{
	int minLength = INT_MAX;
	int n = nums.size();

	for (int i = 0;i < n;i++)
	{
		int sum = 0;
		for (int j = i;j < n;j++)
		{
			sum += nums[j];
			if (sum >= s)
			{
				minLength = std::min(minLength, j - i + 1);
				break;
			}
		}
	}
	return minLength != INT_MAX ? minLength : 0;
}

int ARRAY::minSubArrayLenOpt1(int s, std::vector<int>& nums)
{
	return 0;
}

void ARRAY::paritySortArray(int * iArray, int iLength)
{
	if (iArray == NULL || iLength == 0)
		return;

	int* p = iArray;
	int* q = iArray + iLength - 1;

	while (p < q)		// 同类型指针可以直接比较大小
	{
		while (p < q && ((*p) & 0x01))	// 使用位的与运算取代取余运算能提高性能
		{
			p++;
		}

		while (p < q && !((*q) & 0x01))
		{
			q--;
		}

		if (p < q)
		{
			*p = *p + *q;
			*q = *p - *q;
			*p = *p - *q;
		}
		p++;
		q--;
	}
}

void ARRAY::paritySortArrayOpt1(int * iArray, int iLength, bool(*isEven)(int))
{
	if (iArray == NULL || iLength == 0)
		return;

	int* p = iArray;
	int* q = iArray + iLength - 1;

	while (p < q)		// 同类型指针可以直接比较大小
	{
		while (p < q && !isEven(*p))
		{
			p++;
		}

		while (p < q && isEven(*q))
		{
			q--;
		}

		if (p < q)
		{
			*p = *p + *q;
			*q = *p - *q;
			*p = *p - *q;
		}
		p++;
		q--;
	}
}

bool ARRAY::isEven(int n)
{
	return (n & 1) == 0;
}
