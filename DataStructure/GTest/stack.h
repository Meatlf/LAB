#pragma once
#include<stack>
typedef char ElemType;
#define MaxSize 4

typedef struct
{
	ElemType data[MaxSize];		// 存放栈中的数据元素
	int top;					// 栈顶指针，即存放栈顶元素在data数组中的下标
}SqStack;						// 顺序栈类型

namespace SQSTACK {
	// 初始化栈
	void initStack(SqStack* &s);

	// 销毁栈
	// 该运算释放顺序栈s占用的存储空间
	void destoryStack(SqStack* &s);

	// 判断栈是否为空
	bool empthStack(SqStack* s);

	// 进栈
	// 在栈不满的条件下先将栈顶指针增1，然后在该位置上插入元素e，并返回真；否则返回假。
	bool pushStack(SqStack* &s, ElemType e);
}

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。
// 队列的声明如下，请实现它的两个函数
// appendTail和deleteHead，分别完成在队列尾部
// 插入结点和在队列头部删除结点的功能。
// 分析：声明两个栈stack1和stack2
template <typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	// 在队列末尾添加一个结点
	void appendTail(const T& element);

	// 删除队列的头结点
	T deleteHead();

private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template<typename T>
inline CQueue<T>::CQueue(void)
{
}

template<typename T>
inline CQueue<T>::~CQueue(void)
{
}

template<typename T>
inline void CQueue<T>::appendTail(const T & element)
{
	stack1.push(element);
}

template<typename T>
inline T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw new exception("queue is empth");

	T head = stack2.top();
	stack2.pop();

	return head;
}