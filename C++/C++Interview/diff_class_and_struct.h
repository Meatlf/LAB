#ifndef _DIFF_CLASS_AND_STRUCT_H
#define _DIFF_CLASS_AND_STRUCT_H

#include<iostream>

class CPoint
{
public:
	CPoint(int x,int y);
	~CPoint();
	void print1();	
private:
	int x;
	int y;
};

//struct SPonit
//{
//	int x;
//	int y;
//	void print() {
//		std::cout << "SPoint: (" << x << ", " << y << ")" << std::endl;
//	}
//	SPonit(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//private:
//	void print1() {
//		std::cout << "SPoint: (" << x << ", " << y << ")" << std::endl;
//	}
//};

#endif