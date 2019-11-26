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

	// �������л�������
	//  3 -> 2 -> 4 ->5
	//  ����2Ϊ�����
	ListNode* createNodeWithRing();

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

	/*
	 ��6����β��ͷ��ӡ����
	 ��Ŀ������һ�������ͷ�ڵ㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ
	 ����˼·�����ϡ�����ȳ�����ջģ�ͣ�ʹ��ջ��ʵ�ִ�β��ͷ��ӡ����
	 ˵������������ͷ�ڵ�
	*/
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
	ListNode* kToLastNode(ListNode* pHeadNode, int k);

	/*
	��23�������л�����ڽڵ�
	��Ŀ�����һ�������а�����������ҳ�������ڽڵ㣿
	����˼·��
		1��ʹ�á�����ָ�롱�Ĳ��ԣ�
		2���ֽ�Ϊ��������Ҫ�㣬1���ж��Ƿ��л���2������л���������ڵ������
		3��Q������ж������Ƿ��������
			A����ָ����2������ָ����1���������ָ��׷������ָ�룬���������
		4��Q������ҳ�������ڽڵ㣿
			A����ڵ����ƶ����еĽڵ������������ڵ��ٴ�����ʱ�������ĵ�ַ���ǻ�����ڽڵ㡣
		5��Q�����ȷ�����нڵ����Ŀ��
			A������ָ�������ĵط�һ���ڻ��У����Դ������Ľڵ������һ���ƶ�һ�߼��������ٴλص�����ڵ�ʱ���Ϳ��Եõ����нڵ����ˡ�
	*/
	ListNode* entryPointNode(ListNode* pHeadNode);

	// ����ָ�������Ľڵ�
	ListNode* meetPointNode(ListNode* pHeadNode);

	/*
	��24����ת����
	��Ŀ������һ������������һ�������ͷ�ڵ㣬��ת�����������ת�������ͷ�ڵ㡣
	����˼·��
		1��ʹ��3��ָ������ɷ�ת����
	*/
	ListNode* reverseNode(ListNode* pHeadNode);

	/*
	��25���ϲ��������������
	��Ŀ������������������������ϲ�����������ʹ�������еĽڵ���Ȼ�ǵ�������ġ�
	����˼·��
		��������������
			����1��1 -> 3 -> 5 -> 7
			����2��2 -> 4 -> 6 -> 8
		�����ϲ���������Ĺ��̣����Ⱥϲ�����1������2��ͷ�ڵ�õ�����1��Ϊͷ�ڵ㣬�ڶ��κϲ�ʣ��Ľڵ�ʱ������2���ӵ�ͷ�ڵ�ĺ��档��Ȼ�ڶ��κϲ����һ�κϲ���ȫһ�����������ʹ�õݹ鷨ʵ�֡�
	*/
	ListNode* mergeNode(ListNode* pHeadNode0, ListNode* pHeadNode1);
}