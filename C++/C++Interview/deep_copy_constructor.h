#ifndef DEEP_COPY_CONSTRUCTOR_H
#define DEEP_COPY_CONSTRUCTOR_H
// ��6�� C++������� ������22 ���ƹ��캯����ʲô��ʲô����ȸ��ƺ�ǳ����

class DeepCopyConstructor
{
public:
	DeepCopyConstructor();
	DeepCopyConstructor(const DeepCopyConstructor& test);
	DeepCopyConstructor(const char* str);
	~DeepCopyConstructor();
	char* buf;

private:
};
#endif