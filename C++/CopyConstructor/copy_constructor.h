#ifndef _COPY_CONSTRUCTOR_H
#define _COPY_CONSTRUCTOR_H
#include <iostream>

using namespace std;

class Line
{
public:
	int getLength(void);
	Line(int len);             // �򵥵Ĺ��캯��
	Line(const Line &obj);      // �������캯��
	~Line();                     // ��������

private:
	int *ptr;
};
void display(Line obj);
#endif