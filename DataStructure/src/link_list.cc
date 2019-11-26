#include<stack>
#include"link_list.h"
#define ARRAYSIZE  3

ListNode * LISTNODE::createNode()
{
	ListNode* pHeadNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* pTailNode = pHeadNode;

	if (NULL == pHeadNode)
	{
		std::cout << "�ڴ����ʧ�ܣ�\n";
		exit(EXIT_FAILURE);
	}

	pHeadNode->iVal = 0;
	pHeadNode->pNext = NULL;

	int iArrayNodeValue[5] = { 3,2,4,5,0 };
	int i = 0;
	for (;i < 5;i++)
	{
		if (iArrayNodeValue[i] == 0)
			break;
		ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
		pNewNode->iVal = iArrayNodeValue[i];

		pTailNode->pNext = pNewNode;
		pTailNode = pTailNode->pNext;
		pTailNode->pNext = NULL;
	}
	std::cout << std::endl;
	return pHeadNode;
}

ListNode * LISTNODE::createNodeWithoutHead()
{
	ListNode* firstNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tailNode = firstNode;

	firstNode->iVal = 3;
	firstNode->pNext = NULL;

	int iArray[ARRAYSIZE] = { 2,4,5 };

	for (int i = 0; i < ARRAYSIZE;i++)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->iVal = iArray[i];
		newNode->pNext = NULL;
		tailNode->pNext = newNode;
		tailNode = newNode;
	}
	return firstNode;
}

ListNode * LISTNODE::createNodeWithRing()
{
	ListNode* pHeadNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* pTailNode = pHeadNode;
	ListNode* pRingEntryNode = (ListNode*)malloc(sizeof(ListNode));

	if (NULL == pHeadNode)
	{
		std::cout << "�ڴ����ʧ�ܣ�\n";
		exit(EXIT_FAILURE);
	}

	pHeadNode->iVal = 0;
	pHeadNode->pNext = NULL;

	int iArrayNodeValue[5] = { 3,2,4,5,0 };
	int i = 0;
	for (;i < 5;i++)
	{
		if (iArrayNodeValue[i] == 0)
			break;
		ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
		pNewNode->iVal = iArrayNodeValue[i];

		if (pNewNode->iVal == 2)
			pRingEntryNode = pNewNode;

		pTailNode->pNext = pNewNode;
		pTailNode = pTailNode->pNext;
		pTailNode->pNext = NULL;
	}
	pTailNode->pNext = pRingEntryNode;
	std::cout << std::endl;
	return pHeadNode;
}

void LISTNODE::printNode(ListNode * pHeadNode)
{
	ListNode* pCurNode = pHeadNode->pNext;
	std::cout << "Print list pNode��" << std::endl;
	while (pCurNode != NULL)
	{
		std::cout << pCurNode->iVal << "->";
		pCurNode = pCurNode->pNext;
	}
	std::cout << "NULL";
	putchar('\n');
}

bool LISTNODE::isEmptyLinkList(ListNode * pNode)
{
	if (pNode->pNext == NULL)
		return false;
	return true;
}

int LISTNODE::linkListLength(ListNode * pNode)
{
	int length = 0;
	while (pNode->pNext != NULL)
	{
		pNode = pNode->pNext;
		length++;
	}
	return length;
}

void LISTNODE::InsertNode(ListNode * pHeadNode, int iData)
{

}

ListNode * LISTNODE::searchNode(ListNode * pHeadNode, int iPoisition)
{
	if (iPoisition < 0)
	{
		std::cout << "Incorrect position to search node!\n";
		return NULL;
	}

	if (iPoisition == 0)
	{
		return pHeadNode;
	}

	if (pHeadNode == NULL)
	{
		std::cout << "Link is empty!\n";
		return NULL;
	}

	ListNode* pCurNode = pHeadNode;
	while (--iPoisition)		//  ͨ����������ȷ�������� --iPoisiton ���� iPoisiton 
	{
		pCurNode = pCurNode->pNext;
		if (pCurNode == NULL)
		{
			std::cout << "Incorrect position to search node!\n";
			return NULL;
		}
	}
	return pCurNode;
}

ListNode * LISTNODE::insertNode(ListNode * pHeadNode, int iPoistion, int iVal)
{
	if (iPoistion < 0)
	{
		std::cout << "Please input correct poistion!" << std::endl;
		return NULL;
	}

	ListNode* insertNode = (ListNode*)malloc(sizeof(ListNode));
	insertNode->iVal = iVal;
	insertNode->pNext = NULL;

	if (iPoistion == 0)
	{
		pHeadNode->pNext = insertNode;
		return pHeadNode;
	}

	ListNode* findNode = searchNode(pHeadNode, iPoistion);

	if (findNode != NULL)
	{
		insertNode->pNext = findNode->pNext;
		findNode->pNext = insertNode;
	}
	return pHeadNode;
}

ListNode * LISTNODE::deleteNode(ListNode * pHeadNode, int iPoistion)
{
	if (pHeadNode == NULL)
	{
		std::cout << "The list is empty!" << std::endl;
		return NULL;
	}

	if (iPoistion == 0 || iPoistion == 1)
		return pHeadNode;

	ListNode* pPreNode = searchNode(pHeadNode, iPoistion);
	ListNode* pCurNode = (ListNode*)malloc(sizeof(ListNode));

	if (pPreNode != NULL && pPreNode->pNext != NULL)
	{
		pCurNode = pPreNode->pNext;
		pPreNode->pNext = pCurNode->pNext;
		free(pCurNode);
	}
	return pHeadNode;
}

void LISTNODE::printListReversely(ListNode * pHeadNode)
{
	if (pHeadNode == NULL || pHeadNode->pNext == NULL)
		std::cout << "The list is empty!" << std::endl;
	else if (pHeadNode->pNext->pNext == NULL)
	{
		std::cout << "Print list reversely!" << std::endl;
		std::cout << pHeadNode->pNext->iVal << std::endl;
	}

	// ջ�Ķ���
	std::stack<ListNode*> stackList;

	// �����������Ԫ����ջ����
	ListNode* pTempNode = pHeadNode->pNext;
	while (pTempNode != NULL)
	{
		stackList.push(pTempNode);
		pTempNode = pTempNode->pNext;
	}

	std::cout << "Print list reversely!" << std::endl;
	// ջ��������ջ����
	while (!stackList.empty())
	{
		std::cout << stackList.top()->iVal << " ";
		stackList.pop();
	}
	std::cout << std::endl;
}

/*
��18��ɾ������Ľڵ�
��Ŀ���������������ͷָ���һ���ڵ�ָ�룬����һ��������O(1)ʱ����ɾ���ýڵ�
���룺������ɾ���Ľڵ�
���������
����˼·��
һ�������Ҫɾ���Ľڵ㲻��β�ڵ㣺����Ҫɾ��i�ڵ㣬ʹ��i�ڵ����һ�ڵ�j�����滻��i�ڵ㣬����ɾ��ԭʼ��j�ڵ㣻
�����������1������ֻ��һ���ڵ㣻
��2��Ҫɾ���Ľڵ�Ϊβ�ڵ㡣
*/

/*
Q����ν��и��Ʋ��滻�ڵ㣿

Q�����ɾ���ڵ㣿
A�� delete pNext;
	pNext = NULL;

Q������ж�����ֻ��һ���ڵ㣿
A��pNode->pNext != NULL && pNode->pNext->pNext == NULL

Q������ж��Ƿ�Ϊβ�ڵ㣿
A��
*/
void LISTNODE::deleteNode(ListNode * pNode, ListNode * pToBeDeletedNode)
{
	// �����Ϸ��Բ���
	if (pNode == NULL || pToBeDeletedNode == NULL)
		return;

	// Ҫɾ���Ľڵ㲻��β�ڵ�
	if (pToBeDeletedNode->pNext != NULL)
	{
		ListNode* pNextNode = pToBeDeletedNode->pNext;
		pToBeDeletedNode->iVal = pNextNode->iVal;
		pToBeDeletedNode->pNext = pNextNode->pNext;
		delete(pNextNode);
		pNextNode->pNext = NULL;
		return;
	}

	// ����ֻ��һ���ڵ㣬ɾ��ͷ�ڵ㣨Ҳ��β�ڵ㣩
	if (pNode->pNext != NULL && pNode->pNext->pNext == NULL)
	{
		delete(pNode->pNext);
		pNode->pNext->pNext = NULL;
		pNode->pNext = NULL;
		return;
	}

	// �������ж���ڵ㣬ɾ��β�ڵ�
	if (pToBeDeletedNode != NULL && pToBeDeletedNode->pNext == NULL)
	{
		ListNode* pCurNode = pNode->pNext;
		while (pCurNode->pNext != pToBeDeletedNode)
		{
			pCurNode = pCurNode->pNext;
		}
		pCurNode->pNext = NULL;
		delete(pToBeDeletedNode);
		pToBeDeletedNode->pNext = NULL;
		return;
	}
}

ListNode * LISTNODE::kToLastNode(ListNode * pHeadNode, int k)
{
	ListNode* pFastNode = pHeadNode;
	ListNode* pSlowNode = pHeadNode;

	if (pHeadNode == NULL)
		return pHeadNode;

	if (k < 1)
		return pHeadNode;

	for (int i = k - 1;i > 0;--i)
	{
		pFastNode = pFastNode->pNext;
	}

	if (pFastNode->pNext == NULL)
		return pHeadNode;

	while (pFastNode->pNext != NULL)
	{
		pFastNode = pFastNode->pNext;
		pSlowNode = pSlowNode->pNext;
	}

	return pSlowNode;
}

ListNode* LISTNODE::entryPointNode(ListNode * pHeadNode)
{
	ListNode* pMeetPointNode = meetPointNode(pHeadNode);
	int num;

	if (pMeetPointNode == NULL)
		return NULL;
	else
	{
		ListNode* pTestNumPointNode = pMeetPointNode->pNext;
		num = 1;
		while (pTestNumPointNode != pMeetPointNode)
		{
			pTestNumPointNode = pTestNumPointNode->pNext;
			num++;
		}

	}

	ListNode* pFastNode = pHeadNode;
	ListNode* pSlowNode = pHeadNode;

	for (int i = num;i > 0;--i)
	{
		pFastNode = pFastNode->pNext;
	}

	while (pFastNode != pSlowNode)
	{
		pFastNode = pFastNode->pNext;
		pSlowNode = pSlowNode->pNext;
	}
	return pSlowNode;
}

ListNode * LISTNODE::meetPointNode(ListNode * pHeadNode)
{
	ListNode* pFastNode = pHeadNode;
	ListNode* pSlowNode = pHeadNode;

	while (pFastNode->pNext != NULL)
	{
		pFastNode = pFastNode->pNext->pNext;
		pSlowNode = pSlowNode->pNext;
		if (pFastNode == pSlowNode)
			return pSlowNode;
	}
	return NULL;
}

ListNode * LISTNODE::reverseNode(ListNode * pHeadNode)
{
	ListNode* pReversedHeadNode = NULL;	// ���ڱ�������ת֮���ͷ�ڵ�
	ListNode* pCurNode = pHeadNode;
	ListNode* pPreNode = NULL;

	while (pCurNode != NULL)
	{
		ListNode* pNextNode = pCurNode->pNext;	// pNextNode�ڵ���whileѭ���ڳ�ʼ��

		if (pNextNode == NULL)
			pReversedHeadNode = pCurNode;
		pCurNode->pNext = pPreNode;
		pPreNode = pCurNode;
		pCurNode = pNextNode;
	}

	return pReversedHeadNode;
}

ListNode * LISTNODE::mergeNode(ListNode * pHeadNode0, ListNode * pHeadNode1)
{
	if (pHeadNode0 == NULL)
		return pHeadNode1;
	else if(pHeadNode1 == NULL)
	{
		return pHeadNode0;
	}

	ListNode* pMergedNode = (ListNode*)malloc(sizeof(ListNode));

	if (pHeadNode0->pNext->iVal < pHeadNode1->pNext->iVal)
	{
		pMergedNode = pHeadNode0;
		pMergedNode->pNext = mergeNode(pHeadNode0->pNext, pHeadNode1);
	}
	else
	{
		pMergedNode = pHeadNode1;
		pMergedNode->pNext = mergeNode(pHeadNode0, pHeadNode1->pNext);
	}
	return pMergedNode;
}
