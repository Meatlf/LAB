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
	return (s->top == -1);
}

bool SQSTACK::pushStack(SqStack *& s, ElemType e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;									// ջ��ָ����1
	s->data[s->top] = e;						// Ԫ��e����ջ��ָ�봦
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