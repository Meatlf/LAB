#include<iostream>
#include"gtest\gtest.h"
#include"define_function.h"
#include"array.h"
#include"link_list.h"
#include"recursion.h"
#include"binary_tree.h"
#include"binary_tree.h"
#include"myString.h"
#include"baseAlg.h"
#include"stack.h"
#define ArraySize 6

TEST(paritySortArray, case0)
{
	std::cout << "面试题21：" << std::endl;
	int iArrayInput[5] = { 1,2,3,4,5 };
	int iArrayOutput[5] = { 1,5,3,4,2 };
	int iLength = 5;
	ARRAY::paritySortArray(iArrayInput, iLength);
	for (int i = 0;i < iLength;i++)
		EXPECT_EQ(iArrayOutput[i], iArrayInput[i]);
}

TEST(paritySortArray, case1)
{
	int* iArrayInput = NULL;
	int iLength = 0;
	ARRAY::paritySortArray(iArrayInput, iLength);
	EXPECT_EQ(NULL, iArrayInput);
}

TEST(paritySortArray, case2)
{
	int iArrayInput[5] = { 1,5,3,4,2 };
	int iArrayOutput[5] = { 1,5,3,4,2 };
	int iLength = 5;
	ARRAY::paritySortArray(iArrayInput, iLength);
	for (int i = 0;i < iLength;i++)
		EXPECT_EQ(iArrayOutput[i], iArrayInput[i]);
}

TEST(paritySortArray, case3)
{
	int iArrayInput[5] = { 2,4,1,3,5 };
	int iArrayOutput[5] = { 5,3,1,4,2 };
	int iLength = 5;
	ARRAY::paritySortArray(iArrayInput, iLength);
	for (int i = 0;i < iLength;i++)
		EXPECT_EQ(iArrayOutput[i], iArrayInput[i]);
}

TEST(paritySortArray, case4)
{
	int iArrayInput[5] = { 1,2,3,4,5 };
	int iArrayOutput[5] = { 1,5,3,4,2};
	int iLength = 5;
	ARRAY::paritySortArray(iArrayInput, iLength);
	for (int i = 0;i < iLength;i++)
		EXPECT_EQ(iArrayOutput[i], iArrayInput[i]);
}

TEST(paritySortArray, case5)
{
	int iArrayInput[5] = { 2,4,1,3,5 };
	int iArrayOutput[5] = { 5,3,1,4,2 };
	int iLength = 5;
	ARRAY::paritySortArrayOpt1(iArrayInput, iLength,ARRAY::isEven);
	for (int i = 0;i < iLength;i++)
		EXPECT_EQ(iArrayOutput[i], iArrayInput[i]);
}

void  test_array()
{
	std::vector<int> v;
	for (int i = 1; i <= 6; i++)
		v.push_back(i);
	std::cout << "LeetCode 209 长度最小的子数组:" << std::endl;
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

void test_stack()
{
	std::string s = "[[]])";
	std::cout << SQSTACK::isValid(s) << std::endl;
}

void test_my_string()
{
	const char* pcStr = "0123___";
	const char** ppStr = &pcStr;

	std::cout << STRING::scanUnsignedInteger(ppStr)
		<< std::endl;
}

int fun(int a, int b)
{
	return (a - b);
}

TEST(fun, case1)
{
	EXPECT_LT(-2, fun(1, 2));
	EXPECT_EQ(-1, fun(1, 2));
	ASSERT_LT(-2, fun(1, 2));
	ASSERT_EQ(-1, fun(1, 2));
}

int main(int argc, char* argv[]) {
	//test_replace_blank();
	//test_link_list();
	//test_recursion();
	//test_binary_tree();
	test_array();
	//test_stack();
	//test_my_string();
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}