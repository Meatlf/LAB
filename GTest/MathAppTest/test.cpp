#include "pch.h"
#include"../GTest/double_num.cpp"

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
