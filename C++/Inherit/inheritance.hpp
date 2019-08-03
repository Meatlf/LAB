#ifndef INHERITANCE_H
#define INHERITANCE_H

// ����
// ������Shape
// �๦�ܣ����þ��εĳ��Ϳ�
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
// ������PaintCost
// �๦�ܣ������������Ϳ���÷�
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

#endif