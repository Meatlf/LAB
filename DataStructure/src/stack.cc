#include<memory>
#include "stack.h"

void SQSTACK::initStack(SqStack *& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));		// ����һ��˳��ջ�ռ䣬�׵�ַ�����s��
	s->top = -1;								// ջ��ָ����Ϊ-1
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
	s->top++;									// ջ��ָ����1
	s->data[s->top] = e;						// Ԫ��e����ջ��ָ�봦
	return true;
}
