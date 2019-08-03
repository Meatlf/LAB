#pragma once

namespace SERACH {


// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组{3，4，5，1，2}为{1，2，3，4，5}的一个旋转，该数组的最小值为1。
// 解法：二分查找法来寻找最小的元素
// 输入：int iArray[], int length
// 输出：int iMinValue
	bool rotate_array(int iArray[], int length, int* value);

}