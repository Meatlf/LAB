#include<stack>
#include"link_list.h"
#define ARRAYSIZE  4

ListNode * LISTNODE::createNode()
{
	ListNode* pHeadNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* pTailNode = pHeadNode;

	if (NULL == pHeadNode)
	{
		std::cout << "内存分配失败！\n";
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

	int iArray[ARRAYSIZE] = { 1,2,3,4 };

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

void LISTNODE::printNode(ListNode * pHeadNode)
{
	ListNode* pCurNode = pHeadNode->pNext;
	std::cout << "Print list pNode：" << std::endl;
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
	while (--iPoisition)		//  通过具体例子确定到底是 --iPoisiton 还是 iPoisiton 
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
	else if (pHeadNode->pNext->pNext==NULL)
	{
		std::cout << "Print list reversely!" << std::endl;
		std::cout << pHeadNode->pNext->iVal << std::endl;
	}

	std::stack<ListNode*> stackList;
	ListNode* pTempNode = pHeadNode->pNext;

	while (pTempNode != NULL)
	{
		stackList.push(pTempNode);
		pTempNode = pTempNode->pNext;
	}

	std::cout << "Print list reversely!" << std::endl;
	while (!stackList.empty())
	{
		std::cout << stackList.top()->iVal << " ";
		stackList.pop();
	}
	std::cout << std::endl;
}
