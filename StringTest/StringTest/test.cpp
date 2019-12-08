/*
华为上机测试
*/
#include<iostream>
#include<string>

void main()
{
	int iInputNumber;
	std::cin >> iInputNumber;
	std::string a;
	std::cin >> a;

	int i=0;

	int iNumber = 0;

	if (a == "")
	{
		return;
	}

	while (iNumber != iInputNumber)
	{
		if (a[i] == '\0')
			return;
		if (a[i] == ';') {
			iNumber++;
		}
		i++;
	}

	while (a[i] != ';' && a[i] != '\0' && i<a.length())
	{
		std::cout << a[i];
		i++;
	}
}