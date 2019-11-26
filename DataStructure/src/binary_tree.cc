#include<iostream>
#include "binary_tree.h"

void BINARYTREE::createBTree(BTNode *& b, char * str)
{
	BTNode* St[MaxSize], *p;	// St������Ϊ˳��ջ
	int top = -1, k, j = 0;		// topΪջ��ָ��
	char ch;
	b = NULL;					// ��ʼʱ������Ϊ��
	ch = str[j];

	while (ch != '\0')			// ѭ��ɨ��str�е�ÿ���ֽ�
	{
		switch (ch)
		{
		case'(':				// ��ʼ�������ӽ��
			top++;
			St[top] = p;
			k = 1;
			break;
		case')':				// ջ�����������������
			top--;
			break;
		case',':				// ��ʼ�����Һ��ӽ��
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));	// ����һ����㣬��pָ����
			p->data = ch;							// ��Ž��ֵ
			p->lchild = p->rchild = NULL;			// ����ָ�붼����Ϊ��

			if (b == NULL)							// ����δ���������
				b = p;								// p��ָ������Ϊ�����
			else                                    // �ѽ��������������
			{
				switch (k)
				{
				case 1:St[top]->lchild = p;break;	// �½������Ϊջ����������
				case 2:St[top]->rchild = p;break;	// �½������Ϊջ�������Һ���
				}
			}										// �ѽ��������������
		}
		j++;										// ����ɨ��str
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
�������b�ĸ߶ȵĵݹ�ģ��f(b)���£�
f(b) = 0					�� b = NULL
f(b) = MAX{f(b->lchild),f(b->rchild)} + 1			�������
*/
int BINARYTREE::BTHeight(BTNode * b)
{
	int leftChildHeight, rightChildHeight;
	if (b == NULL)return 0;																				// �����ĸ߶�Ϊ0
	else
	{
		leftChildHeight = BTHeight(b->lchild);															// ���������ĸ߶�Ϊlchild
		rightChildHeight = BTHeight(b->rchild);															// ���������ĸ߶�Ϊrchild
		return(leftChildHeight > rightChildHeight) ? (leftChildHeight + 1) : (rightChildHeight + 1);	// �á���ȸ���ɡ�ȷ��������Ҫ"+ 1"		
	}
	return 0;
}

// ���ܣ���������ʾ�����������
// �ݹ�ģ�ͣ�
//	���ڷǿն�����b
//		�������Ԫ��ֵ
//		���������ӻ��Һ��ӽ��ʱ
//			���һ����("����
//			�ݹ鴦��������
//			������������ʱ�����һ����,"����
//			�ݹ鴦��������
//			������һ��","����
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
�ݹ�ģ�ͣ�
 ��1) ���������
	f(b) = 0 ,										�� b =NULL
 ��2���ݹ��ϵ��
	f(b) = f(b->lchild) + f(b->rchild) + 1			�������
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

// ���ܣ����һ�Ÿ���������������Ҷ�ӽ��
// �ݹ�ģ�ͣ�
//			ʲô������			����b = NULL
//			���Ҷ�ڵ�ֵ		������Ҷ�ӽ��
//			����������е�Ҷ�ӽ��
//			����������е�Ҷ�ӽ��
void BINARYTREE::dispLeaf(BTNode * b)
{
	if (b != NULL)
	{
		if (b->lchild == NULL&&b->rchild == NULL)
			printf("%c", b->data);					// ����Ҷ�ӽ��
		dispLeaf(b->lchild);						// ����������е�Ҷ�ӽ��
		dispLeaf(b->rchild);						// ����������е�Ҷ�ӽ��
	}
}

int BINARYTREE::BTLevel(BTNode * b, ElemType x, int h)	// h�ó�ֵ1
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
		level = BTLevel(b->lchild, x, h + 1);			// ���������в���
		if (level != 0)
			return level;								// �����������ҵ��ˣ�����1
		else                                            // ��������δ�ҵ��������������в���
		{
			return(BTLevel(b->rchild, x, h + 1));
		}
	}
}

BTNode * BINARYTREE::constructCore(int * startPrecorder, int * endPreorder, int * startInorder, int * endInorder)
{
	// ǰ��������еĵ�һ�������Ǹ�����ֵ
	int rootValue = startPrecorder[0];
	BTNode* root = new BTNode();
	root->data = rootValue;
	root->lchild = root->rchild = NULL;

	// ֻ��һ��Ԫ�ص����
	if (startPrecorder == endPreorder)
	{
		if (startInorder == endInorder
			&& *startPrecorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}

	// ����������������ҵ�������λ��
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder 
		!= rootValue)
		++rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");

	// �������ĳ���
	int leftLength = rootInorder - startInorder;

	// ǰ�����ʱ���������һ��Ԫ�ص�λ��
	int* leftPreorderEnd = startPrecorder + leftLength;

	if (leftLength > 0)
	{
		// ����������
		root->lchild = constructCore(startPrecorder + 1,
			leftPreorderEnd, startInorder, rootInorder - 1);
	}

	if (leftLength < endPreorder - startPrecorder)
	{
		// ����������
		root->rchild = constructCore(leftPreorderEnd + 1,
			endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

BTNode* BINARYTREE::getNextNode(BTNode* pNode)
{
		// �ж��Ƿ�Ϊ����
		if (pNode == NULL)
			return NULL;

		BTNode* pNextNode = NULL;

		// ���һ�����������������ô������һ����������������
		// ���е������ӽ��
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