#ifndef STATIC_MEMORY_H
#define STATIC_MEMORY_H
// ��6�� C++������� ������11 ��̬��Ա�Ĵ���ʹ��
#include<iostream>

class test
{
public:
	static int i;
	int j;

	test(int a);
	void func1();
	static void func2();
	~test();

private:

};
int test::i = 1;

test::test(int a) : j(a) {}

void test::func1() { std::cout << i << ", " << j << std::endl; }
void test::func2() { std::cout << i << /*", " << j <<*/ std::endl; }
test::~test()
{
}
#endif