#ifndef _COPY_CONSTRUCTOR_H
#define _COPY_CONSTRUCTOR_H

class TestCopyConstructor
{
public:
	TestCopyConstructor(int x);
	TestCopyConstructor(const TestCopyConstructor& test);
	~TestCopyConstructor();

private:
	int a;
};

void fun1(TestCopyConstructor test);

TestCopyConstructor fun2();
#endif