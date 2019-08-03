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
	return (s->top == -1);
}

bool SQSTACK::pushStack(SqStack *& s, ElemType e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;									// 栈顶指针增1
	s->data[s->top] = e;						// 元素e放在栈顶指针处
	return true;
}

bool SQSTACK::isValid(std::string s)
{
	std::stack<char> Stack;

	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			Stack.push(s[i]);
		else
		{
			if (Stack.size() == 0)
				return false;
			char c = Stack.top();
			Stack.pop();

			char match;
			if (s[i] == ')')
				match = '(';
			else if (s[i] == ']')
			{
				match = '[';
			}
			else
			{
				assert(s[i] == '}');
				match = '{';
			}
			if (c != match)
				return false;
		}
	}
	if (Stack.size() != 0)
		return false;
	return true;
}

bool SQSTACK::isValidOpt1(std::string s)
{
	std::stack<char> Stack;

	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			Stack.push(s[i]);
		else
		{
			if (Stack.size() == 0)
				return false;

			if (s[i] == ')' && Stack.top() != '(') return false;
			else if (s[i] == ']' && Stack.top() != '[') return false;
			else if (s[i] == '}'&&Stack.top() != '{')return false;
			Stack.pop();
		}
	}
	return !Stack.size();
}