/*
���ܣ�
C++ thisָ��Ļ���ʹ��ʵ��
˵����
֪ʶ�����this ָ��������������ʹ�á�
������

���ߣ�tztang

�ο����ϣ�
[C++ thisָ��](http://www.runoob.com/cplusplus/cpp-this-pointer.html)

����޸����ڣ�
2019-04-20
*/

#include <iostream>
#include"this_point.h"

int main(void)
{
	Box Box1(3.3, 1.2, 1.5);    // Declare box1
	Box Box2(8.5, 6.0, 2.0);    // Declare box2

	if (Box1.compare(Box2))
	{
		std::cout << "Box2 is smaller than Box1" << std::endl;
	}
	else
	{
		std::cout << "Box2 is equal to or larger than Box1" << std::endl;
	}

	// Box* ����ָ��p���ܶ���box��get_address()��Ա�����ķ���ֵ������ӡ
	Box* p = Box1.get_address();
	std::cout << p << std::endl;

	p = Box2.get_address();
	std::cout << p << std::endl;
	return 0;
}