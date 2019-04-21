#ifndef CONSTRUCTOR_EXPLICIT_H
#define CONSTRUCTOR_EXPLICIT_H
// 第6章 C++面向对象 面试题18 构造函数explicit与普通构造函数的区别

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
	explicit Test2(int n) { num = n; };		// explicit(显示）构造函数
	~Test2();

private:
	int num;
};

Test1::Test1(int n): num(n)		// 普通构造函数
{
}

Test1::~Test1()
{
}

Test2::~Test2()
{
}
#endif