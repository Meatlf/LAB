/*
���ܣ�
	C++�๹�캯�������������Ļ���ʹ��ʵ��
˵����
     ֪ʶ��������캯������������������������ͳ�ʼ����ʹ�ó�ʼ���б�����ʼ���ֶΡ�
������

���ߣ�tztang

�ο����ϣ�
[C++ �๹�캯�� & ��������](http://www.runoob.com/cplusplus/cpp-constructor-destructor.html)

���ڣ�
2019-04-13
*/

#include <iostream>

using namespace std;

#define UseInitializationList  (1)	// �Ƿ�ʹ�ó�ʼ���б�

class Line
{
public:
	void setLength(double len);
	double getLength(void);
	Line();  // ���ǹ��캯������
	Line(double len);
	~Line();
private:
	double length;
};

// ��Ա�������壬�������캯��
Line::Line(void)
{
	cout << "Object is being created" << endl;
}

#if UseInitializationList 
Line::Line(double len) :length(len) {}
#else
Line::Line(double len) {
	length = len;
}
#endif

Line::~Line(void) {
	cout << "Object is being deleted" << endl;
}

void Line::setLength(double len)
{
	length = len;
}

double Line::getLength(void)
{
	return length;
}

int main()
{
	Line line1;
	Line line2(10.0);

	// ���ó���
	line1.setLength(6.0);
	cout << "Length of line1 : " << line1.getLength() << endl;

	cout << "Length of line2 : " << line1.getLength() << endl;

	line2.setLength(12.0);
	cout << "Length of line2 : " << line2.getLength() << endl;

	return 0;
}