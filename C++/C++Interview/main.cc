/*

���ߣ�tztang

�ο����ϣ�
[C��C++����Ա��������]

���ڣ�
2019-04-14
*/

#include <iostream>
#include"diff_class_and_struct.h"
#include"static_memory.h"
#include"global_object.h"
#include"constructor_explicit.h"
#include"explicit_constructor_effect.h"

using namespace std;

Test a;			// ȫ�ֱ���

int main(void) {
	CPoint cpt(1, 2);

	//SPoint spt(3, 4);

	// std::cout << cpt.x << " " << cpt.y << std::endl;	// �������
	// cpt.print();	// �������
	cpt.print1();	// �Ϸ�

					//spt.print();	// �Ϸ�
					//spt.print1();	// �������
					//std::cout << spt.x << " " << spt.y << std::endl;	// �Ϸ�

	test t(2);
	t.func1();
	t.func2();

	std::cout << "main() start" << std::endl;
	Test b;	// �ֲ�����

	Test1 t1 = 12;	// ��ʽ�����乹�캯�����ɹ�
	//Test2 t2 = 12;	// ������󣬲�����ʽ�����乹�캯��
	Test2 t3(12);	// ��ʾ���óɹ�

	short s = 42;
	Show(s);

	return 0;
}