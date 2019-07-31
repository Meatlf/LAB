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

	// 面试题21：调整数组顺序使奇数位于偶数前面
	// 题目：输入一个整数数组，实现一个函数来调整数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
	// 解题分析：“广义的排序”
	// 解法1：暴力法：从头到尾扫描这个数组，每碰到一个偶数，拿出这个数字，并把位于这个数字后面的所有数字往前挪动一位。
	// 挪完之后在数组的末尾有一个空位，这时把该偶数放入这个空位。由于每碰到一个偶数就需要移动O(n)个数字，因此总的时间复杂度是O(n^2)。
	// 输入：数组，数组长度
	// 输出：数组
	void paritySortArray(int* iArray, int iLength);
}