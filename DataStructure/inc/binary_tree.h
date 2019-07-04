#pragma once

typedef char ElemType;
#define MaxSize 4

struct BTNode
{
	ElemType	data;			// ����Ԫ��
	BTNode*		lchild;			// ָ�����ӽ��
	BTNode*		rchild;			// ָ���Һ��ӽ��
	BTNode*		pParent;
};

namespace BINARYTREE
{
	// ����������
	void createBTree(BTNode* &b, char* str);

	// ���ٶ�����
	void destroyBTree(BTNode* &b);

	// ���ҽ��
	BTNode* findNode(BTNode* b, ElemType x);

	// �Һ��ӽ��
	BTNode* lchildNode(BTNode* b);
	BTNode* rchildNode(BTNode* b);

	// ��߶�
	int BTHeight(BTNode* b);

	void dispBTree(BTNode* b);

	// �������
	void preOrder(BTNode* b);

	// �������
	void inOrder(BTNode* b);

	// �������
	void postOrder(BTNode* b);

	// ����һ�Ÿ��������������н�����
	int BTNodeNumber(BTNode* b);

	// ���һ�ø���������������Ҷ�ӽ��
	void dispLeaf(BTNode* b);

	// ����ֵΪx�Ľ�����ڵĲ��
	int BTLevel(BTNode* b, ElemType x, int h);

	// ������7���ؽ�������
	// �ɶ�������ǰ���������������ؽ�������
	BTNode* constructCore(int* startPrecorder, int* endPreorder,
		int* startInorder, int* endInorder);

	// ������8������������һ�����
	// ����һ�Ŷ����������е�һ����㣬�ҳ�����������е���һ��
	// ���
	BTNode* getNextNode(BTNode* pNode);
}