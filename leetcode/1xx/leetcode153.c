/*
@File    :   leetcode153.c
@Time    :   2020/03/29 19:20:08
@Author  :   xiaosongsong
@Desc    :   None
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0


*/

#include <stdio.h>
int halfSearch(int *nums, int first, int last, int size)
{
    int pos = (first + last) / 2;
    if (first <= last)
    {
        if (pos > 0 && nums[pos - 1] > nums[pos] && nums[pos] < nums[pos + 1])
            return pos;
        int p = halfSearch(nums, first, pos - 1, size);
        if (p != -1)
            return p;
        return halfSearch(nums, pos + 1, last, size);
    }
    return -1;
}
int findMin(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    if (nums[numsSize - 1] < nums[numsSize - 2])
        return nums[numsSize - 1];
    if (nums[0] < nums[numsSize - 1])
        return nums[0];
    int q = halfSearch(nums, 0, numsSize - 1, numsSize);
    return nums[q];
}
int main()
{
    int node[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d", findMin(node, 7));
    return 0;
}
