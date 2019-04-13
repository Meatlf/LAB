/*
功能：
C++拷贝构造函数的基本使用实例
说明：
（1）知识点包括拷贝构造函数的声明、定义和使用；
（2）建议使用单步调试来查看程序执行流程。
函数：

作者：tztang

参考资料：
[C++ 拷贝构造函数](http://www.runoob.com/cplusplus/cpp-copy-constructor.html)

日期：
2019-04-13
*/

#include <iostream>

using namespace std;

class Line
{
public:
	int getLength(void);
	Line(int len);             // 简单的构造函数
	Line(const Line &obj);      // 拷贝构造函数
	~Line();                     // 析构函数

private:
	int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
	cout << "调用构造函数" << endl;
	// 为指针分配内存
	ptr = new int;
	*ptr = len;
}

Line::Line(const Line &obj)
{
	cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
	ptr = new int;
	*ptr = *obj.ptr; // 拷贝值
}

Line::~Line(void)
{
	cout << "释放内存" << endl;
	delete ptr;
}
int Line::getLength(void)
{
	return *ptr;
}

void display(Line obj)
{
	cout << "line 大小 : " << obj.getLength() << endl;
}

int main()
{
	Line line1(10);
	Line line2 = line1;	// 这里也调用了拷贝构造函数

	display(line1);
	display(line2);

	return 0;
}