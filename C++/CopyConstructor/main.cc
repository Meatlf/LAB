/*
���ܣ�
C++�������캯���Ļ���ʹ��ʵ��
˵����
��1��֪ʶ������������캯���������������ʹ�ã�
��2������ʹ�õ����������鿴����ִ�����̡�
������

���ߣ�tztang

�ο����ϣ�
[C++ �������캯��](http://www.runoob.com/cplusplus/cpp-copy-constructor.html)

���ڣ�
2019-04-13
*/

#include <iostream>

using namespace std;

class Line
{
public:
	int getLength(void);
	Line(int len);             // �򵥵Ĺ��캯��
	Line(const Line &obj);      // �������캯��
	~Line();                     // ��������

private:
	int *ptr;
};

// ��Ա�������壬�������캯��
Line::Line(int len)
{
	cout << "���ù��캯��" << endl;
	// Ϊָ������ڴ�
	ptr = new int;
	*ptr = len;
}

Line::Line(const Line &obj)
{
	cout << "���ÿ������캯����Ϊָ�� ptr �����ڴ�" << endl;
	ptr = new int;
	*ptr = *obj.ptr; // ����ֵ
}

Line::~Line(void)
{
	cout << "�ͷ��ڴ�" << endl;
	delete ptr;
}
int Line::getLength(void)
{
	return *ptr;
}

void display(Line obj)
{
	cout << "line ��С : " << obj.getLength() << endl;
}

int main()
{
	Line line1(10);
	Line line2 = line1;	// ����Ҳ�����˿������캯��

	display(line1);
	display(line2);

	return 0;
}