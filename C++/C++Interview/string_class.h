#ifndef STRING_CLASS_H
#define STRING_CLASS_H
#include<iostream>
// ��6�� C++������� ������26 ��д��String�Ĺ��캯�������������͸�ֵ����

class StringClass
{
public:
	StringClass(const char* str=NULL);						//��ͨ���캯��
	StringClass(const StringClass &other);					//���ƹ��캯��
	StringClass & operator = (const StringClass &other);	//��ֵ����
	~StringClass();											//��������

private:
	char* m_String;											//�����ַ���
};
#endif