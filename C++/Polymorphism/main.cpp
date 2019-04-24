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

#include <iostream> 
using namespace std;

class Shape {
protected:
	int width, height;
public:
	Shape(int a = 0, int b = 0)
	{
		width = a;
		height = b;
	}
	int area()
	{
		cout << "Parent class area :" << endl;
		return 0;
	}
};
class Rectangle : public Shape {
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		cout << "Rectangle class area :" << endl;
		return (width * height);
	}
};
class Triangle : public Shape {
public:
	Triangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		cout << "Triangle class area :" << endl;
		return (width * height / 2);
	}
};
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