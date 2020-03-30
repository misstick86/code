/*
@File    :   leetcode162.c
@Time    :   2020/03/30 09:42:29
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
int halfSearch(int *nums, int first, int last, int numsSize)
{
    int pos = (first + last) / 2;
    if (pos == 0 && nums[pos] > nums[pos + 1])
        return pos;
    if (pos == numsSize && nums[pos - 1] < nums[pos])
        return pos;
    if (pos > 0 && nums[pos - 1] < nums[pos] && nums[pos + 1] < nums[pos])
        return pos;
    if (last < first)
        return -1;
    int q = halfSearch(nums, first, pos - 1, numsSize);
    if (q != -1)
        return q;
    return halfSearch(nums, pos + 1, last, numsSize);
}
int findPeakElement(int *nums, int numsSize)
{
    if (numsSize == 1)
        return 0;
    return halfSearch(nums, 0, numsSize - 1, numsSize - 1);
}
int main()
{
    int node[] = {1, 2, 1, 3, 5, 6, 4};
    findPeakElement(node, 7);
    return 0;
}
