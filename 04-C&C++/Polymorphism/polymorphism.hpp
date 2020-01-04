#ifndef POLYMORPHISM
#define POLYMORPHISM

#include <iostream> 

// ��̬���������˼���Ƕ�����̬������֮����ڲ�νṹ��������֮����ͨ���̳й���ʱ���ͻ��õ���̬��

// ����
class Shape {
protected:
	int width, height;
public:
	Shape(int a = 0, int b = 0)
	{
		width = a;
		height = b;
	}
	virtual int area()	// ��̬��һ��ʹ�÷�ʽ
	{
		std::cout << "Parent class area :" << std::endl;
		return 0;
	}
};

class Rectangle : public Shape {
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		std::cout << "Rectangle class area :" << std::endl;
		return (width * height);
	}
};

class Triangle : public Shape {
public:
	Triangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		std::cout << "Triangle class area :" << std::endl;
		return (width * height / 2);
	}
};
#endif