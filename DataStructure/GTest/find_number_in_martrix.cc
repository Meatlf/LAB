#include"define_function.h"

bool find_number_in_martrix(int* matrix, int row, int column,
	int number, int* location)
{
	int i = column - 1, j = 0;
	while (i>-1 && j<row + 1)
	{
		if (number == matrix[i + j*column])
		{
			location = matrix + i + j*column;
			return true;
		}
		else if (number < matrix[i + j*column])
		{
			i--;
		}
		else
		{
			j++;
		}
	}
	return false;
}