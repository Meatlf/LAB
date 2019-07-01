#include "pch.h"
#include"../GTest/double_num.cpp"
#include"../GTest/find_number_in_martrix.cpp"
#include"../GTest/replace_blank.cpp"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(DoubleNumTest, positiveValues) {
	ASSERT_EQ(12, double_num(6));
	ASSERT_EQ(4, double_num(2));
	ASSERT_EQ(40,double_num(20));
}

TEST(DoubleNumTest, negativeValues) {
	ASSERT_EQ(-12, double_num(-6));
	ASSERT_EQ(-4, double_num(-2));
	ASSERT_EQ(-40, double_num(-20));
}

TEST(FindNumberInMartrix, 1) {

	int matrix[] = { 1,2,3,4,5,
		             2,3,4,5,6,
		             3,4,5,6,7,
		             4,5,6,7,8,
		             5,6,7,8,9 };

	int row = 5;
	int column = 5;
	int* location = NULL;

	// Ҫ���������������С����ҪС
	int number = 0;
	ASSERT_EQ(false, find_number_in_martrix(matrix,row,column,number,location));
	
	// Ҫ�������Ϊ��������С����
	number = 1;
	ASSERT_EQ(true, find_number_in_martrix(matrix, row, column, number, location));

	// Ҫ�������Ϊ������������
	number = 9;
	ASSERT_EQ(true, find_number_in_martrix(matrix, row, column, number, location));

	// Ҫ���������������С����Ҫ��
	number = 10;
	ASSERT_EQ(false, find_number_in_martrix(matrix, row, column, number, location));


	// ³���Բ��ԣ������ָ��
	int* matrix_null = NULL;
	row = 0;
	column = 0;
	number = 16;
	ASSERT_EQ(false, find_number_in_martrix(matrix_null, row, column, number, location));
}

// �ո����ַ�������
TEST(ReplaceBlank, 1)
{
	const char* string = "Hello Wo ld!";
	char* testString = (char*)malloc(17*sizeof(char*));
	char* vaildString = "Hello%20Wo%20ld!";
	int length = 13;
	int lengthTemp = temp_string_length(string, length);
	ASSERT_STREQ("ADB", "ADB");
	replace_blank(string, length, lengthTemp, testString);
	std::cout << testString;
	ASSERT_STREQ(vaildString, testString);
}

// �ո����ַ����Ľ�β
TEST(ReplaceBlank, 2)
{
	const char* string = "HelloWo ld! ";
	char* testString = (char*)malloc(17 * sizeof(char*));
	char* vaildString = "HelloWo%20ld!%20";
	int length = 13;
	int lengthTemp = temp_string_length(string, length);
	ASSERT_STREQ("ADB", "ADB");
	replace_blank(string, length, lengthTemp, testString);
	std::cout << testString;
	ASSERT_STREQ(vaildString, testString);
}

// �ո����ַ����Ŀ�ͷ
TEST(ReplaceBlank, 3)
{
	const char* string = " HelloWo ld!";
	char* testString = (char*)malloc(17 * sizeof(char*));
	char* vaildString = "%20HelloWo%20ld!";
	int length = 13;
	int lengthTemp = temp_string_length(string, length);
	ASSERT_STREQ("ADB", "ADB");
	replace_blank(string, length, lengthTemp, testString);
	std::cout << testString;
	ASSERT_STREQ(vaildString, testString);
}

// �ַ���Ϊ�ո����
TEST(ReplaceBlank, 4)
{
	const char* string = "  ";
	int length = 3;
	int lengthTemp = temp_string_length(string, length);
	char* testString = (char*)malloc(lengthTemp * sizeof(char*));
	char* vaildString = "%20%20";
	ASSERT_STREQ("ADB", "ADB");
	replace_blank(string, length, lengthTemp, testString);
	std::cout << testString;
	ASSERT_STREQ(vaildString, testString);
}

// �ַ���Ϊ��
TEST(ReplaceBlank, 5)
{
	const char* string = "";
	int length = 0;
	int lengthTemp = temp_string_length(string, length);
	char* testString = (char*)malloc(lengthTemp * sizeof(char*));
	char* vaildString = "";
	ASSERT_STREQ("ADB", "ADB");
	replace_blank(string, length, lengthTemp, testString);
	std::cout << testString;
	ASSERT_STREQ(vaildString, testString);
}