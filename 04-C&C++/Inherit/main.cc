/*
���ܣ�
C++�̳еĻ���ʹ��ʵ��
˵����
����ͨ���������ԺͲ鿴���ο����ϡ�ѧϰ��ϰC++����
������

���ߣ�tztang

�ο����ϣ�
[C++ �̳�](http://www.runoob.com/cplusplus/cpp-inheritance.html)

���ڣ�
2019-05-03
*/

#include <iostream>
#include"inheritance.hpp"
#include"multiple_inheritance.hpp"

int main(void)
{
	Rectangle Rect;
	int area;

	Rect.setWidth(5);
	Rect.setHeight(7);

	area = Rect.getArea();

	// �����������
	std::cout << "Total area: " << area << std::endl;

	std::cout << "Total paint cost: $" << Rect.getCost(area) << std::endl;

	std::cout << "Hello World!" << std::endl;
	C c;	// D, B, A, C
	std::cout << sizeof(c) << std::endl;
	return 0;
}