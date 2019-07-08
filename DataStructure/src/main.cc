#include<iostream>
#include"define_function.h"
#include"array.h"
#include"link_list.h"
#include"recursion.h"
#include"binary_tree.h"
#include"binary_tree.h"
#include"myString.h"
#include"baseAlg.h"
#define ArraySize 6

void  test_array()
{
	std::vector<int> v;
	for (int i = 1; i <= 6; i++)
		v.push_back(i);
	std::cout << ARRAY::minSubArrayLen(15, v) << std::endl;
}

void test_replace_blank()
{
	char string[] = "Hello wro ld!";
	int length = 14;
	std::cout << string << std::endl;
	int temp_length = STRING::temp_string_length(string, length);

	char* stringReplaceTemp = (char*)malloc(18 * sizeof(char));
	int lengthRepalceTemp = STRING::replace_blank(string, length, temp_length, stringReplaceTemp);
	std::cout << stringReplaceTemp << std::endl;
	free(stringReplaceTemp);
}

void test_link_list()
{
	ListNode* pHeadNode = LISTNODE::createNode();
	LISTNODE::printNode(pHeadNode);
	bool value = LISTNODE::isEmptyLinkList(pHeadNode);
	std::cout << "Value  = " << value << std::endl;
	std::cout << "Link list's length = " << LISTNODE::linkListLength(pHeadNode) << std::endl;

	int iPosition = 5;
	ListNode* findNode = (ListNode*)malloc(sizeof(ListNode));
	findNode = LISTNODE::searchNode(pHeadNode, iPosition);
	if (findNode != NULL)
		std::cout << "Search for " << iPosition << "th node, the node value is " << findNode->iVal << std::endl;
	LISTNODE::insertNode(pHeadNode, 3, 2);
	LISTNODE::printNode(pHeadNode);
	findNode = LISTNODE::searchNode(pHeadNode, iPosition);
	if (findNode != NULL)
		std::cout << "Search for " << iPosition << "th node, the node value is " << findNode->iVal << std::endl;
	LISTNODE::deleteNode(pHeadNode, iPosition);
	LISTNODE::printNode(pHeadNode);
	LISTNODE::printListReversely(pHeadNode);
}

void test_recursion()
{
	std::cout << RECURSION::factorial(5) << std::endl;

	std::cout << RECURSION::fibonacciRecursiveMethod(10) << std::endl;
	std::cout << RECURSION::fibonacciIterativeMethod(10) << std::endl;

	std::cout << RECURSION::stepFibonacci(3) << std::endl;
	std::cout << RECURSION::integerNumber(150) << std::endl;

	ListNode* pHeadNode = LISTNODE::createNodeWithoutHead();
	LISTNODE::printNode(pHeadNode);
	std::cout << RECURSION::count(pHeadNode) << std::endl;
	RECURSION::traverse(pHeadNode);

	int iArray[10] = { 3, -2, 4, 1, 5, 9, 10, 11, 1, 12 };
	std::cout << RECURSION::minValue(iArray, 10);
}

void test_binary_tree()
{
	BTNode* b = (BTNode*)malloc(sizeof(BTNode));
	ElemType x;
	int h;

	b->data = 3;
	b->lchild = NULL;
	b->rchild = NULL;
	char* str = "A(B(D(,G)),C(E,F))";

	BINARYTREE::createBTree(b, str);

	printf("b:");BINARYTREE::dispBTree(b);printf("\n");

	BINARYTREE::preOrder(b);printf("\n");

	BINARYTREE::inOrder(b);printf("\n");

	BINARYTREE::postOrder(b);printf("\n");

	printf("结点值：");
	scanf_s("%c", &x);
	h = BINARYTREE::BTLevel(b, x, 1);
	if (h == 0)
		printf("b中不存在%c结点\n", x);
	else
	{
		printf("在b中%c结点的层次为%d\n", x, h);
	}
	BINARYTREE::destroyBTree(b);
}

int main(int argc, char* argv[]) {
	//test_replace_blank();
	//test_link_list();
	//test_recursion();
	//test_binary_tree();
	test_array();
	return 0;
}