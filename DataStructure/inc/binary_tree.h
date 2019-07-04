#pragma once

typedef char ElemType;
#define MaxSize 4

struct BTNode
{
	ElemType	data;			// 数据元素
	BTNode*		lchild;			// 指向左孩子结点
	BTNode*		rchild;			// 指向右孩子结点
	BTNode*		pParent;
};

namespace BINARYTREE
{
	// 创建二叉树
	void createBTree(BTNode* &b, char* str);

	// 销毁二叉树
	void destroyBTree(BTNode* &b);

	// 查找结点
	BTNode* findNode(BTNode* b, ElemType x);

	// 找孩子结点
	BTNode* lchildNode(BTNode* b);
	BTNode* rchildNode(BTNode* b);

	// 求高度
	int BTHeight(BTNode* b);

	void dispBTree(BTNode* b);

	// 先序遍历
	void preOrder(BTNode* b);

	// 中序遍历
	void inOrder(BTNode* b);

	// 后序遍历
	void postOrder(BTNode* b);

	// 计算一颗给定二叉树的所有结点个数
	int BTNodeNumber(BTNode* b);

	// 输出一棵给定二叉树的所有叶子结点
	void dispLeaf(BTNode* b);

	// 求结点值为x的结点所在的层次
	int BTLevel(BTNode* b, ElemType x, int h);

	// 面试题7：重建二叉树
	// 由二叉树的前序遍历和中序遍历重建二叉树
	BTNode* constructCore(int* startPrecorder, int* endPreorder,
		int* startInorder, int* endInorder);

	// 面试题8：二叉树的下一个结点
	// 给定一颗二叉树和其中的一个结点，找出中序遍历序列的下一个
	// 结点
	BTNode* getNextNode(BTNode* pNode);
}