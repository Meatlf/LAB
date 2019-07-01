#include<memory>
#include "stack.h"

void SQSTACK::initStack(SqStack *& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));		// 分配一个顺序栈空间，首地址存放在s中
	s->top = -1;								// 栈顶指针置为-1
}

void SQSTACK::destoryStack(SqStack *& s)
{
	free(s);
}

bool SQSTACK::empthStack(SqStack * s)
{
	return (s->top==-1);
}

bool SQSTACK::pushStack(SqStack *& s, ElemType e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;									// 栈顶指针增1
	s->data[s->top] = e;						// 元素e放在栈顶指针处
	return true;
}
