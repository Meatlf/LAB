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
		while(iArray[i] != i)
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
