#pragma once
#include<vector>
#include<algorithm>

namespace ARRAY {
	
	// 面试题3：数组中重复的数字
	// 题目一：找出数组中重复的数字
	// 题目：在一个长度为n的数组里的所有数字都在0-n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，耶不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
	int repeatNumber(int iArray[],int size);

	// LeetCode 209 长度最小的子数组
	// 题目描述：
	// 
	int minSubArrayLen(int s, std::vector<int>& nums);
	
	int minSubArrayLenOpt1(int s, std::vector<int>& nums);
}