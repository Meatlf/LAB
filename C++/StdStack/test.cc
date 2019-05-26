/*
���ܣ�
C++ std::Stack�Ļ���ʹ��ʵ��
˵����

������

ʱ�临�Ӷȣ�

���ߣ�tztang

�ο����ϣ�
[C++����std::Stack](https://blog.csdn.net/zy2317878/article/details/79739922)
���ڣ�
2019-05-26
*/

#include<iostream>
#include<stack>
#include<vector>
#include<deque>

int main()
{
	std::deque<int> mydeque(3, 100);	// deque with 3 elements
	std::vector<int> myvector(2, 200);	// vector with 2 elements

	std::stack<int> first;				// empty stack
	std::stack<int> second(mydeque);	// stack initialized to copy of deque

	std::stack<int, std::vector<int>>third;	// empty stack using vector
	std::stack<int, std::vector<int>>fourth(myvector);

	std::cout << "size of first:" << first.size() << '\n';
	std::cout << "size of second:" << second.size() << '\n';
	std::cout << "size of third:" << third.size() << '\n';
	std::cout << "size of fourth:" << fourth.size() << '\n';

	return 0;
}