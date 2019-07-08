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
	double result;
	
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
	if (exponent & 0x1 == 1)
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