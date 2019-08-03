#include<iostream>
#include "search.h"

bool SERACH::rotate_array(int iArray[], int length, int* value)
{
	if (iArray == NULL || length < 0)
		return false;

	int* ptr0 = iArray;
	int* ptr1 = iArray + length - 1;

	while (ptr1 - ptr0 > 1)
	{
		int middle = (ptr1 - ptr0) >> 1;
		if (*(ptr0 + middle) > *ptr0)
			ptr0 = ptr0 + middle;
		else
		{
			ptr1 = ptr0 + middle;
		}
	}
	value = ptr1;
	return true;
}
