#ifndef COPY_CONSTRUCTOR_H
#define COPY_CONSTRUCTOR_H
// ��6�� C++������� ������22 ���ƹ��캯����ʲô��ʲô����ȸ��ƺ�ǳ����

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