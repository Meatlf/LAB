/*
���ܣ�
	C++��̬�Ļ���ʹ��ʵ��
˵����
	����ͨ���������ԺͲ鿴���ο����ϡ�ѧϰ��ϰC++��̬
������

���ߣ�tztang

�ο����ϣ�
[C++ ��̬](http://www.runoob.com/cplusplus/cpp-polymorphism.html)

���ڣ�
2019-04-24
*/
#include"polymorphism.hpp"

// �����������
int main()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle  tri(10, 5);

	// �洢���εĵ�ַ
	shape = &rec;
	// ���þ��ε���������� area
	shape->area();

	// �洢�����εĵ�ַ
	shape = &tri;
	// ���������ε���������� area
	shape->area();

	return 0;
}