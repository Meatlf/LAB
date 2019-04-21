#ifndef EXPLICIT_CONSTRUCTOR_EFFECTOR_H
#define EXPLICIT_CONSTRUCTOR_EFFECTOR_H
// ��6�� C++������� ������19 explicit���캯��������

#include<iostream>

class Number
{
public:
	std::string type;
	
	Number();
	explicit Number(short):type("short"){}
	Number(int):type("int"){}
	~Number();

private:

};

Number::Number() : type("void") {}


Number::~Number()
{
}

void Show(const Number& n) { std::cout << "hello" << std::endl; }
#endif