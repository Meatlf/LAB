#pragma once
#include<iostream>

// Definition for singly-linked list.
struct ListNode {
	int iVal = 0;
	ListNode *pNext;
	ListNode(int x) : iVal(x), pNext(NULL){}
};

namespace LISTNODE {

	// ������������
	ListNode* createNode();

	// ��������ͷ�ڵ������
	ListNode* createNodeWithoutHead();

	// ��ӡ��������
	void printNode(ListNode* pHeadNode);

	// �жϵ��������Ƿ�Ϊ��
	bool isEmptyLinkList(ListNode* pNode);

	// ���㵥������ĳ���
	int linkListLength(ListNode* pNode);

	// �����������ڵ�
	void InsertNode(ListNode* pNode, int iData);

	// ������ڵ�Ĳ���
	ListNode* searchNode(ListNode* pHeadNode, int iPoisition);

	// �ӵ����������ڵ�
	ListNode* insertNode(ListNode* pHeadNode, int iPoistion, int iVal);

	// �ӵ�������ɾ���ڵ�
	ListNode* deleteNode(ListNode* pHeadNode, int iPoistion);

	// ɾ�����������ͷ��ڴ�

	// ��6����β��ͷ��ӡ����
	// ��Ŀ������һ�������ͷ�ڵ㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ
	// ����ؼ�������ջģ�ͣ�ʹ��ջ��ʵ�ִ�β��ͷ��ӡ����
	void printListReversely(ListNode* pHeadNode);

	/*
	 ��18��ɾ������Ľڵ�
	 ��Ŀ���������������ͷָ���һ���ڵ�ָ�룬����һ��������O(1)ʱ����ɾ���ýڵ�
	 ���룺������ɾ���Ľڵ�
	 ���������
	 ����˼·��
		һ�����������Ҫɾ��i�ڵ㣬ʹ��i�ڵ����һ�ڵ�j�����滻��i�ڵ㣬����ɾ��ԭʼ��j�ڵ㣻
		�����������1������ֻ��һ���ڵ㣻
				  ��2��Ҫɾ���Ľڵ�Ϊβ�ڵ㡣
	*/
	void deleteNode(ListNode* pNode, ListNode* toBeDeletedNode);

	//ListNode* reverseList(ListNode* head);
	//// 876.������м�ڵ�
	//ListNode* middleNode(ListNode* head);
	//// 21.�ϲ�������������
	//ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
	////83. ɾ�����������е��ظ�Ԫ��
	//ListNode* deleteDuplicates(ListNode* head);

	////24. �������������еĽڵ�
	////1������ͷ�ڵ�
	//ListNode* swapPairs(ListNode* head);

	/*
	��22�������е�����k���ڵ�
	��Ŀ������һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣
	����˼·��
		ʹ�á�����ָ�롱�Ĳ��ԣ�������ָ�����k-1���ڵ㡣
	*/
	ListNode* pKToLastNode(ListNode* pHeadNode, int k);
}