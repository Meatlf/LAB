#include"string_class.h"

StringClass::StringClass(const char* str){
	std::cout << "Constructing" << std::endl;
	if (str == NULL) {				// ���strΪNULL������ַ���""
		m_String = new char[1];
		*m_String = '\0';
	}
	else
	{
		m_String = new char[strlen(str) + 1];
		strcpy(m_String, str);
	}
}

StringClass::StringClass(const StringClass& other){
	std::cout << "Constructing Copy" << std::endl;
	m_String = new char[strlen(other.m_String) + 1];	// ����ռ�����str����
	strcpy(m_String, other.m_String);
}

StringClass & StringClass::operator = (const StringClass& other) {
	std::cout << "Operate = Function" << std::endl;
	if (this == &other) {			// ���������other��ͬһ������ֱ�ӷ��ر���
		return *this;
	}
	delete[] m_String;				// �ͷŶ��ڴ�
	m_String = new char[strlen(other.m_String) + 1];
	strcpy(m_String, other.m_String);

	return *this;
}

StringClass::~StringClass()
{
	std::cout << "Destructing" << std::endl;
	if (m_String != NULL) {
		delete[] m_String;
		m_String = '\0';
	}
}
