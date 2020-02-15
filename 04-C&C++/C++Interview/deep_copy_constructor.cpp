#include<iostream>
#include"deep_copy_constructor.h"


DeepCopyConstructor::DeepCopyConstructor()
{
	buf = NULL;
}

DeepCopyConstructor::DeepCopyConstructor(const DeepCopyConstructor & test)
{
	buf = new char[strlen(test.buf) + 1];
}

DeepCopyConstructor::DeepCopyConstructor(const char* str) {
	buf = new char[strlen(str) + 1];	//������ڴ�
	strcpy(buf, str);					//�����ַ���
}

DeepCopyConstructor::~DeepCopyConstructor()
{
	if (buf != NULL) {
		delete buf;		// �ͷ�bufָ��Ķ��ڴ�
	}
}

