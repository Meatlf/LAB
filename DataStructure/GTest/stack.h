#pragma once
#include<stack>
typedef char ElemType;
#define MaxSize 4

typedef struct
{
	ElemType data[MaxSize];		// ���ջ�е�����Ԫ��
	int top;					// ջ��ָ�룬�����ջ��Ԫ����data�����е��±�
}SqStack;						// ˳��ջ����

namespace SQSTACK {
	// ��ʼ��ջ
	void initStack(SqStack* &s);

	// ����ջ
	// �������ͷ�˳��ջsռ�õĴ洢�ռ�
	void destoryStack(SqStack* &s);

	// �ж�ջ�Ƿ�Ϊ��
	bool empthStack(SqStack* s);

	// ��ջ
	// ��ջ�������������Ƚ�ջ��ָ����1��Ȼ���ڸ�λ���ϲ���Ԫ��e���������棻���򷵻ؼ١�
	bool pushStack(SqStack* &s, ElemType e);
}

// ������9��������ջʵ�ֶ���
// ��Ŀ��������ջʵ��һ�����С�
// ���е��������£���ʵ��������������
// appendTail��deleteHead���ֱ�����ڶ���β��
// ��������ڶ���ͷ��ɾ�����Ĺ��ܡ�
// ��������������ջstack1��stack2
template <typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	// �ڶ���ĩβ���һ�����
	void appendTail(const T& element);

	// ɾ�����е�ͷ���
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