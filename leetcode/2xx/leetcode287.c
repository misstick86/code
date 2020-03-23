/*
@File    :   leetcode287.c
@Time    :   2020/03/22 20:46:55
@Author  :   xiaosongsong
@Desc    :   None
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2
示例 2:

输入: [3,1,3,4,2]
输出: 3

*/

#include <stdio.h>
int findDuplicate(int *nums, int numsSize)
{
    int first, last;
    for (last = 0; last < numsSize; last++)
    {
        first = last + 1;
        while (nums[last] != nums[first] && first < numsSize)
            first++;
        if (nums[last] == nums[first])
            return nums[last];
    }
}
int main()
{
    int n[] = {1, 3, 4, 2, 2};
    findDuplicate(n, 5);
    return 0;
}
