/*
功能：
C++ this指针的基本使用实例
说明：
知识点包括this 指针的声明、定义和使用。
函数：

作者：tztang

参考资料：
[C++ this指针](http://www.runoob.com/cplusplus/cpp-this-pointer.html)

日期：
2019-04-14
*/

#include <iostream>

using namespace std;

class Box
{
public:
	// 构造函数定义
	Box(double l = 2.0, double b = 2.0, double h = 2.0)
	{
		cout << "Constructor called." << endl;
		length = l;
		breadth = b;
		height = h;
	}
	double Volume()
	{
		return length * breadth * height;
	}
	int compare(Box box)
	{
		return this->Volume() > box.Volume();
	}
private:
	double length;     // Length of a box
	double breadth;    // Breadth of a box
	double height;     // Height of a box
};

int main(void)
{
	Box Box1(3.3, 1.2, 1.5);    // Declare box1
	Box Box2(8.5, 6.0, 2.0);    // Declare box2

	if (Box1.compare(Box2))
	{
		cout << "Box2 is smaller than Box1" << endl;
	}
	else
	{
		cout << "Box2 is equal to or larger than Box1" << endl;
	}
	return 0;
}