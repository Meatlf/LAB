#include"define.h"

void Const()
{
	const int x = 1;
	int b = 10;
	int c = 20;

	// ����ָ��ָ��ı�������ָ��ָ���ֵ����
	const int* a1 = &b;	

	// ����ָ�뱾����ָ�뱾��Ϊ����
	int* const a2 = &b;

	// ��ʾ����ָ�뱾�����޸ģ�������ָ�������Ҳ�����޸�
	const int* const a3 = &b;

	// �����������ٸ�ֵ
	// x = 2;

	printf("*a1 = %d,a1 = %p\n", *a1, a1);

	a1 = &c;
	// *a1 = 1;
	printf("*a1 = %d,a1 = %p\n", *a1, a1);

	// a2 = &c;
	*a2 = 1;
	printf("*a2 = %d,a2 = %p\n", *a2, a2);

	// a3 = &c;
	// *a3 = 1;
}