/*
@File    :   leetcode81.c
@Time    :   2020/03/30 09:29:37
@Author  :   xiaosongsong
@Desc    :   None

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
*/

#include <stdio.h>
#include <stdbool.h>

bool halfSearch(int *nums, int first, int last, int target)
{
    int pos = (first + last) / 2;
    if (nums[pos] == target)
        return true;
    if (last < first)
        return false;
    return halfSearch(nums, first, pos - 1, target) || halfSearch(nums, pos + 1, last, target);
}

bool search(int *nums, int numsSize, int target)
{
    if (numsSize == 0)
        return false;
    return halfSearch(nums, 0, numsSize - 1, target);
}
int main()
{
    int node[] = {2, 5, 6, 0, 0, 1, 2};
    search(node, 7, 0);
    return 0;
}
