#include<iostream>
#include<string>	
#define MAX 5
//#undef MAX

// 移位的四舍五日运算
#define CV_DESCALE(x,n)	(((x)+( 1<<( (n) - 1 ) ))>>(n))

void main() {

	char name[MAX] = "abcd";
	std::cout << "MAX = " << MAX << std::endl;
	for (int i = 0;i < MAX;i++)
		std::cout << name << std::endl;
	
	std::cout << "val0 = CV_DESCALE(3, 2) = " << CV_DESCALE(3, 2) << std::endl;
	std::cout << "val1 = CV_DESCALE(10, 3) = " << CV_DESCALE(10, 3) << std::endl;
	std::cout << "val2 = CV_DESCALE(7, 5) = " << CV_DESCALE(7, 5) << std::endl;
	std::cout << "val3 = CV_DESCALE(9, 4) = " << CV_DESCALE(9, 4) << std::endl;
}