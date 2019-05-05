/*

�ο����ϣ�
[C��C++����Ա��������]

���ߣ�tztang

���ڣ�
2019-05-02
*/

#include <iostream>
#include"diff_class_and_struct.h"
#include"static_memory.h"
#include"global_object.h"
#include"constructor_explicit.h"
#include"explicit_constructor_effect.h"
#include"copy_constructor.h"
#include"deep_copy_constructor.h"
#include"string_class.h"

using namespace std;

Test a;			// ȫ�ֱ���

int main(void) {
	//CPoint cpt(1, 2);

	////SPoint spt(3, 4);

	//// std::cout << cpt.x << " " << cpt.y << std::endl;	// �������
	//// cpt.print();	// �������
	//cpt.print1();	// �Ϸ�

	//				//spt.print();	// �Ϸ�
	//				//spt.print1();	// �������
	//				//std::cout << spt.x << " " << spt.y << std::endl;	// �Ϸ�

	//test t(2);
	//t.func1();
	//t.func2();

	//std::cout << "main() start" << std::endl;
	//Test b;	// �ֲ�����

	// ��6�� C++������� ������18 ���캯��explicit����ͨ���캯��������
	CommonConstructor1 common_constructor1 = 12;	// ��ʽ�����乹�캯�����ɹ�
	//ExplicitConstructor2 t2 = 12;	// ������󣬲�����ʽ�����乹�캯��
	ExplicitConstructor2 explicit_constructor2(12);	// ��ʾ���óɹ�

	// ��6�� C++������� ������19 explicit���캯��������
	short s = 42;
	Show(s);

	// ��6�� C++������� ������22 ���ƹ��캯����ʲô��ʲô����ȸ��ƺ�ǳ����
	TestCopyConstructor test_copy_constructor_1(1);
	TestCopyConstructor test_copy_constructor_2 = test_copy_constructor_1;	// ���ø��ƹ��캯��
	std::cout << "Before fun1()..." << std::endl;
	fun1(test_copy_constructor_1);	// ���ø��ƹ��캯��

	TestCopyConstructor test_copy_constructor_3 = fun2();	// ���ø��ƹ��캯��
	std::cout << "After fun2()..." << std::endl;
	
	DeepCopyConstructor deep_copy_constructor_1("hello");	//����Ĭ�ϵĸ��ƹ��캯��
	DeepCopyConstructor deep_copy_constructor_2 = deep_copy_constructor_1;		//����Ĭ�ϵĸ��ƹ��캯��

	std::cout << "(t1.buf == t2.buf) ? " << (deep_copy_constructor_1.buf == deep_copy_constructor_2.buf ? "yes":"no") << std::endl;

	// ��6�� C++������� ������26 ��д��String�Ĺ��캯�������������͸�ֵ����
	StringClass a("hello");		// ������ͨ���캯��
	StringClass b("world");		// ������ͨ���캯��
	StringClass c(a);			// ���ø�ֵ����
	c = b;

	return 0;
}