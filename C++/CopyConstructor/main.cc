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
2019-04-16
*/

#include"copy_constructor.h"

int main()
{
	Line line1(10);
	Line line2 = line1;	// �������ÿ������캯��

	display(line1);		// �������ÿ������캯��
	display(line2);		// �������ÿ������캯��

	return 0;
}