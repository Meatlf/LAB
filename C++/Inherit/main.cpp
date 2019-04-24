/*
功能：
C++继承的基本使用实例
说明：
可以通过单步调试和查看“参考资料”学习或复习C++重载
函数：

作者：tztang

参考资料：
[C++ 继承](http://www.runoob.com/cplusplus/cpp-inheritance.html)

日期：
2019-04-24
*/

#include <iostream>

using namespace std;

// 基类
class Shape
{
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
protected:
	int width;
	int height;
};

// 基类 PaintCost
class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 70;
	}
};

// 派生类
class Rectangle : public Shape, public PaintCost
{
public:
	int getArea()
	{
		return (width * height);
	}
};

int main(void)
{
	Rectangle Rect;
	int area;

	Rect.setWidth(5);
	Rect.setHeight(7);

	area = Rect.getArea();

	// 输出对象的面积
	cout << "Total area: " << area << endl;

	cout << "Total paint cost: $" << Rect.getCost(area) << endl;

	return 0;
}