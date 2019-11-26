#include<iostream>
#include "binary_tree.h"

void BINARYTREE::createBTree(BTNode *& b, char * str)
{
	BTNode* St[MaxSize], *p;	// St数组作为顺序栈
	int top = -1, k, j = 0;		// top为栈顶指针
	char ch;
	b = NULL;					// 初始时二叉树为空
	ch = str[j];

	while (ch != '\0')			// 循环扫描str中的每个字节
	{
		switch (ch)
		{
		case'(':				// 开始处理左孩子结点
			top++;
			St[top] = p;
			k = 1;
			break;
		case')':				// 栈顶结点的子树处理完毕
			top--;
			break;
		case',':				// 开始处理右孩子结点
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));	// 创建一个结点，由p指向它
			p->data = ch;							// 存放结点值
			p->lchild = p->rchild = NULL;			// 左、右指针都设置为空

			if (b == NULL)							// 若尚未建立根结点
				b = p;								// p所指结点就作为根结点
			else                                    // 已建立二叉树根结点
			{
				switch (k)
				{
				case 1:St[top]->lchild = p;break;	// 新建结点作为栈顶结点的左孩子
				case 2:St[top]->rchild = p;break;	// 新建结点作为栈顶结点的右孩子
				}
			}										// 已建立二叉树根结点
		}
		j++;										// 继续扫描str
		ch = str[j];
	}
}

void BINARYTREE::createBTreeUsingRecursion(BTNode *& pBTNode)
{
}

void BINARYTREE::destroyBTree(BTNode *& b)
{
	if (b != NULL)
	{
		destroyBTree(b->lchild);
		destroyBTree(b->rchild);
		free(b);
	}
}

BTNode * BINARYTREE::findNode(BTNode * b, ElemType x)
{
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = findNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return findNode(b->rchild, x);
	}
}

BTNode * BINARYTREE::lchildNode(BTNode * b)
{
	return b->lchild;
}

BTNode * BINARYTREE::rchildNode(BTNode * b)
{
	return b->rchild;
}

/*
求二叉树b的高度的递归模型f(b)如下：
f(b) = 0					若 b = NULL
f(b) = MAX{f(b->lchild),f(b->rchild)} + 1			其他情况
*/
int BINARYTREE::BTHeight(BTNode * b)
{
	int leftChildHeight, rightChildHeight;
	if (b == NULL)return 0;																				// 空树的高度为0
	else
	{
		leftChildHeight = BTHeight(b->lchild);															// 求左子树的高度为lchild
		rightChildHeight = BTHeight(b->rchild);															// 求右子树的高度为rchild
		return(leftChildHeight > rightChildHeight) ? (leftChildHeight + 1) : (rightChildHeight + 1);	// 用“麻雀定律”确定这里需要"+ 1"		
	}
	return 0;
}

// 功能：用括弧表示法输出二叉树
// 递归模型：
//	对于非空二叉树b
//		先输出其元素值
//		当存在左孩子或右孩子结点时
//			输出一个“("符号
//			递归处理左子树
//			当存在右子树时，输出一个”,"符号
//			递归处理右子树
//			最后输出一个","符号
void BINARYTREE::dispBTree(BTNode * b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			dispBTree(b->lchild);
			if (b->rchild != NULL)printf(",");
			dispBTree(b->rchild);
			printf(")");
		}
	}
}

void BINARYTREE::preOrder(BTNode * b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		preOrder(b->lchild);
		preOrder(b->rchild);
	}
}

void BINARYTREE::inOrder(BTNode * b)
{
	if (b != NULL)
	{
		preOrder(b->lchild);
		printf("%c", b->data);
		preOrder(b->rchild);
	}
}

void BINARYTREE::postOrder(BTNode * b)
{
	if (b != NULL)
	{
		postOrder(b->lchild);
		postOrder(b->rchild);
		printf("%c", b->data);
	}
}

/*
递归模型：
 （1) 基本情况：
	f(b) = 0 ,										若 b =NULL
 （2）递归关系：
	f(b) = f(b->lchild) + f(b->rchild) + 1			其他情况
*/
int BINARYTREE::BTNodeNumber(BTNode * b)
{
	if (b == NULL)
		return 0;
	else
	{
		return BTNodeNumber(b->lchild) + BTNodeNumber(b->rchild) + 1;
	}
}

// 功能：输出一颗给定二叉树的所有叶子结点
// 递归模型：
//			什么都不做			；若b = NULL
//			输出叶节点值		；访问叶子结点
//			输出左子树中的叶子结点
//			输出右子树中的叶子结点
void BINARYTREE::dispLeaf(BTNode * b)
{
	if (b != NULL)
	{
		if (b->lchild == NULL&&b->rchild == NULL)
			printf("%c", b->data);					// 访问叶子结点
		dispLeaf(b->lchild);						// 输出左子树中的叶子结点
		dispLeaf(b->rchild);						// 输出右子树中的叶子结点
	}
}

int BINARYTREE::BTLevel(BTNode * b, ElemType x, int h)	// h置初值1
{
	int level;
	if (b == NULL)
		return 0;
	else if (b->data == x)
	{
		return h;
	}
	else
	{
		level = BTLevel(b->lchild, x, h + 1);			// 在左子树中查找
		if (level != 0)
			return level;								// 在左子树中找到了，返回1
		else                                            // 在左子树未找到，再在右子树中查找
		{
			return(BTLevel(b->rchild, x, h + 1));
		}
	}
}

BTNode * BINARYTREE::constructCore(int * startPrecorder, int * endPreorder, int * startInorder, int * endInorder)
{
	// 前序遍历序列的第一个数字是根结点的值
	int rootValue = startPrecorder[0];
	BTNode* root = new BTNode();
	root->data = rootValue;
	root->lchild = root->rchild = NULL;

	// 只有一个元素的情况
	if (startPrecorder == endPreorder)
	{
		if (startInorder == endInorder
			&& *startPrecorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}

	// 在中序遍历序列中找到根结点的位置
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder 
		!= rootValue)
		++rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");

	// 左子树的长度
	int leftLength = rootInorder - startInorder;

	// 前序遍历时左子树最后一个元素的位置
	int* leftPreorderEnd = startPrecorder + leftLength;

	if (leftLength > 0)
	{
		// 构建左子树
		root->lchild = constructCore(startPrecorder + 1,
			leftPreorderEnd, startInorder, rootInorder - 1);
	}

	if (leftLength < endPreorder - startPrecorder)
	{
		// 构建右子树
		root->rchild = constructCore(leftPreorderEnd + 1,
			endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

BTNode* BINARYTREE::getNextNode(BTNode* pNode)
{
		// 判断是否为空树
		if (pNode == NULL)
			return NULL;

		BTNode* pNextNode = NULL;

		// 如果一个结点有右子树，那么它的下一个结点就是它的右子
		// 树中的最左子结点
		if (pNode->rchild != NULL)
		{
			BTNode* pRightNode = pNode->rchild;
			while (pRightNode->lchild != NULL)
			{
				pRightNode = pRightNode->lchild;
			}
			pNextNode = pRightNode;
		}
		else if (pNode->pParent != NULL)
		{
			BTNode* pCurrent = pNode;
			BTNode* pParent = pNode->pParent;
			while (pParent != NULL && pCurrent == pParent->rchild)
			{
				pCurrent = pParent;
				pParent = pParent->pParent;
			}

			pNextNode = pParent;
		}
		return pNextNode;
}