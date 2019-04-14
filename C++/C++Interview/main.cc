/*

作者：tztang

参考资料：
[C和C++程序员面试秘笈]

日期：
2019-04-14
*/

#include <iostream>
#include"diff_class_and_struct.h"


using namespace std;

int main(void) {
	CPoint cpt(1, 2);

	//SPoint spt(3, 4);

	// std::cout << cpt.x << " " << cpt.y << std::endl;	// 编译错误
	// cpt.print();	// 编译错误
	cpt.print1();	// 合法

					//spt.print();	// 合法
					//spt.print1();	// 编译错误
					//std::cout << spt.x << " " << spt.y << std::endl;	// 合法

	return 0;
}