/*
���ܣ�
C++�ӿڣ������ࣩ�Ļ���ʹ��ʵ��
˵����
����ͨ���������ԺͲ鿴���ο����ϡ�ѧϰ��ϰC++�ӿڣ������ࣩ
������

���ߣ�tztang

�ο����ϣ�
[C++�ӿڣ������ࣩ](http://www.runoob.com/cplusplus/cpp-interfaces.html)

���ڣ�
2019-05-03
*/
#include <iostream>
#include"interface.hpp"

int main(void)
{
	Rectangle Rect;
	Triangle  Tri;

	Rect.setWidth(5);
	Rect.setHeight(7);
	
	// �����������
	std::cout << "Total Rectangle area: " << Rect.getArea() << std::endl;

	Tri.setWidth(5);
	Tri.setHeight(7);
	
	// �����������
	std::cout << "Total Triangle area: " << Tri.getArea() << std::endl;

	return 0;
}