#include "baseAlg.h"
#include "..\DataStructure\baseAlg.h"

double BASEALG::power(double base, int exponent)
{
	double result = 1.0;
	for (int i = 1;i <= exponent;++i)
		result *= base;
	return result;
}

bool bInvalidInput = false;
double BASEALG::powerOpt1(double base, int exponent)
{
	bInvalidInput = false;

	if (base == 0.0 && exponent < 0)
	{
		bInvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = powerWithUnsignedExponent(base, exponent);

	if (exponent < 0)
		result = 1.0 / result;
	return result;
}

double BASEALG::powerOpt2(double base, int exponent)
{

	return 0.0;
}

double BASEALG::powerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = powerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}

void BASEALG::print1ToMaxOfNDigits(int n)
{
	int number = 1;
	int i = 0;
	while (i++ < n)
		number *= 10;

	for (i = 1;i < number;++i)
		std::cout << i;
}

void BASEALG::printToMaxOfNDigitsOpt1(int n)
{
	if (n <= 0)
		return;

	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!increment(number))
	{
		printNumber(number);
	}
	delete[]number;
}

/*
�����������Ĺ�ϵ��
�±꣺[0][1][2]
 ֵ��  9  8 \n
��λ����λ��
��ʾ������Ϊ98.
*/
bool BASEALG::increment(char * number)
{
	bool isOverflow = false;				// �����־λ
	int nTakeOver = 0;						// ��λ
	int nLength = strlen(number);			// �ַ����ĳ��ȣ�������'\0'��

	// �ӵ�λ����λ�����ַ���
	for (int i = nLength - 1;i >= 0;i--)
	{
		int nSum = number[i] - '0' + nTakeOver;

		// ���λ
		if (i == nLength - 1)
			nSum++;

		// ��λ
		if (nSum >= 10)
		{
			// ���λ�Ľ�λ��ʾ���
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}

void BASEALG::printNumber(char * number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0;i < nLength;++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}
	printf("\t");
}

void BASEALG::printToMaxOfNDigitsOpt2(int n)
{
	if (n <= 0)
		return;

	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0;i < 10;++i)
	{
		number[0] = i + '0';
		print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[]number;
}

void BASEALG::print1ToMaxOfNDigitsRecursively(char * number, int length, int index)
{
	if (index == length - 1)
	{
		printNumber(number);
		return;
	}

	for (int i = 0;i < 10;++i)
	{
		number[index + 1] = i + '0';
		print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}