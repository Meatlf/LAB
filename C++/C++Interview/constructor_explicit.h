#ifndef CONSTRUCTOR_EXPLICIT_H
#define CONSTRUCTOR_EXPLICIT_H
// ��6�� C++������� ������18 ���캯��explicit����ͨ���캯��������

class Test1
{
public:
	Test1(int n);
	~Test1();

private:
	int num;
};

class Test2
{
public:
	explicit Test2(int n) { num = n; };		// explicit(��ʾ�����캯��
	~Test2();

private:
	int num;
};

Test1::Test1(int n): num(n)		// ��ͨ���캯��
{
}

Test1::~Test1()
{
}

Test2::~Test2()
{
}
#endif