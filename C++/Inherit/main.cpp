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
2019-04-24
*/

#include <iostream>

using namespace std;

// ����
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

// ���� PaintCost
class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 70;
	}
};

// ������
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

	// �����������
	cout << "Total area: " << area << endl;

	cout << "Total paint cost: $" << Rect.getCost(area) << endl;

	return 0;
}