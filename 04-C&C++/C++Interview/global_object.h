#ifndef GLOBAL_OBJECT_H
#define GLOBAL_OBJECT_H
// ��6�� C++������� ������13 main����ִ��ǰ����ִ��ʲô���룿
#include<iostream>

class Test
{
public:
	Test();
	~Test();

private:

};

Test::Test()
{
	std::cout << "constructor of Test" << std::endl;
}

Test::~Test()
{
}
#endif