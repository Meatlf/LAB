#ifndef CONSTRUCTOR_EXPLICIT_H
#define CONSTRUCTOR_EXPLICIT_H
// ��6�� C++������� ������18 ���캯��explicit����ͨ���캯��������

class CommonConstructor1
{
public:
	CommonConstructor1(int n);
	~CommonConstructor1();

private:
	int num;
};

class ExplicitConstructor2
{
public:
	explicit ExplicitConstructor2(int n);		// explicit(��ʾ�����캯��
	~ExplicitConstructor2();

private:
	int num;
};
#endif