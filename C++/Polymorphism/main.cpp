/*
功能：
	C++多态的基本使用实例
说明：
	可以通过单步调试和查看“参考资料”学习或复习C++多态
函数：

作者：tztang

参考资料：
[C++ 多态](http://www.runoob.com/cplusplus/cpp-polymorphism.html)

日期：
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
// 程序的主函数
int main()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle  tri(10, 5);

	// 存储矩形的地址
	shape = &rec;
	// 调用矩形的求面积函数 area
	shape->area();

	// 存储三角形的地址
	shape = &tri;
	// 调用三角形的求面积函数 area
	shape->area();

	return 0;
}