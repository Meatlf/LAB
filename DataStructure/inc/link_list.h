#pragma once
#include<iostream>

// Definition for singly-linked list.
struct ListNode {
	int iVal;
	ListNode *pNext;
	ListNode(int x) : iVal(x), pNext(NULL){}
};

namespace LISTNODE {

	// 创建单向链表
	ListNode* createNode();

	// 创建不带头节点的链表
	ListNode* createNodeWithoutHead();

	// 打印单向链表
	void printNode(ListNode* pHeadNode);

	// 判断单向链表是否为空
	bool isEmptyLinkList(ListNode* pNode);

	// 计算单向链表的长度
	int linkListLength(ListNode* pNode);

	// 向单向链表插入节点
	void InsertNode(ListNode* pNode, int iData);

	// 单链表节点的查找
	ListNode* searchNode(ListNode* pHeadNode, int iPoisition);

	// 从单向链表插入节点
	ListNode* insertNode(ListNode* pHeadNode, int iPoistion, int iVal);

	// 从单向链表删除节点
	ListNode* deleteNode(ListNode* pHeadNode, int iPoistion);

	// 删除整个链表，释放内存

	// 面6：从尾到头打印链表
	// 题目：输入一个链表的头节点，从尾到头反过来打印出每个节点的值
	// 解题关键：符合栈模型，使用栈来实现从尾到头打印链表
	void printListReversely(ListNode* pHeadNode);

	/*
	 面18：删除链表的节点
	 题目：给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点
	 输入：链表、待删除的节点
	 输出：链表
	 解题思路：
		一般情况：假设要删除i节点，使用i节点的下一节点j复制替换掉i节点，并且删掉原始的j节点；
		特殊情况：（1）链表只有一个节点；
				  （2）要删除的节点为尾节点。
	*/
	void deleteNode(ListNode* pNode, ListNode* toBeDeletedNode);

	//ListNode* reverseList(ListNode* head);
	//// 876.链表的中间节点
	//ListNode* middleNode(ListNode* head);
	//// 21.合并两个有序链表
	//ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
	////83. 删除排序链表中的重复元素
	//ListNode* deleteDuplicates(ListNode* head);

	////24. 两两交换链表中的节点
	////1）构建头节点
	//ListNode* swapPairs(ListNode* head);
}