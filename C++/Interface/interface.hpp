// Shape��Ϊ���࣬����������getArea()���麯��Ҳ�ǳ�����
// ˽�б�����width��height
// ���г�Ա������
// getArea()	// ���麯��	
// setWidth()	// ���ÿ��
// setHeight()	// ���ø߶�
class Shape
{
public:
	// �ṩ�ӿڿ�ܵĴ��麯��
	virtual int getArea() = 0;
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

// RectangleΪ����Shape��������
// getArea()ʵ���˾�������ļ���
class Rectangle : public Shape
{
public:
	int getArea()
	{
		return (width * height);
	}
};

// TriangleΪ����Shape��������
// getArea()ʵ��������������ļ���
class Triangle : public Shape
{
public:
	int getArea()
	{
		return (width * height) / 2;
	}
};
