/*

作者：tztang

参考资料：
[C和C++程序员面试秘笈]

日期：
2019-04-18
*/

#include <iostream>
#include"diff_class_and_struct.h"
#include"static_memory.h"
#include"global_object.h"
#include"constructor_explicit.h"
#include"explicit_constructor_effect.h"
#include"copy_constructor.h"
#include"deep_copy_constructor.h"

using namespace std;

Test a;			// 全局变量

int main(void) {
	//CPoint cpt(1, 2);

	////SPoint spt(3, 4);

	//// std::cout << cpt.x << " " << cpt.y << std::endl;	// 编译错误
	//// cpt.print();	// 编译错误
	//cpt.print1();	// 合法

	//				//spt.print();	// 合法
	//				//spt.print1();	// 编译错误
	//				//std::cout << spt.x << " " << spt.y << std::endl;	// 合法

	//test t(2);
	//t.func1();
	//t.func2();

	//std::cout << "main() start" << std::endl;
	//Test b;	// 局部变量

	//Test1 t1 = 12;	// 隐式调用其构造函数，成功
	////Test2 t2 = 12;	// 编译错误，不能隐式调用其构造函数
	//Test2 t3(12);	// 显示调用成功

	//short s = 42;
	//Show(s);

	// 第6章 C++面向对象 面试题22 复制构造函数是什么？什么是深度复制和浅复制
	TestCopyConstructor test_copy_constructor_1(1);
	TestCopyConstructor test_copy_constructor_2 = test_copy_constructor_1;	// 调用复制构造函数
	std::cout << "Before fun1()..." << std::endl;
	fun1(test_copy_constructor_1);	// 调用复制构造函数

	TestCopyConstructor test_copy_constructor_3 = fun2();	// 调用复制构造函数
	std::cout << "After fun2()..." << std::endl;
	
	DeepCopyConstructor deep_copy_constructor_1("hello");	//调用默认的复制构造函数
	DeepCopyConstructor deep_copy_constructor_2 = deep_copy_constructor_1;		//调用默认的复制构造函数

	std::cout << "(t1.buf == t2.buf) ? " << (deep_copy_constructor_1.buf == deep_copy_constructor_2.buf ? "yes":"no") << std::endl;
	return 0;
}