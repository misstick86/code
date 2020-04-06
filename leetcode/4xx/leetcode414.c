/*
@File    :   leetcode414.c
@Time    :   2020/04/05 19:15:16
@Author  :   xiaosongsong
@Desc    :   None

给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

示例 1:

输入: [3, 2, 1]

输出: 1

解释: 第三大的数是 1.
示例 2:

输入: [1, 2]

输出: 2

解释: 第三大的数不存在, 所以返回最大的数 2 .
示例 3:

输入: [2, 2, 3, 1]

输出: 1

解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/third-maximum-number
*/

#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void adjustHeap(int *nums, int n, int k)
{
    int j = 2 * k + 1;
    while (j < n)
    {
        if (j + 1 < n && nums[j] < nums[j + 1])
            j++;
        if (nums[k] > nums[j])
            break;
        else
        {
            Swap(&nums[k], &nums[j]);
            k = j;
            j = 2 * k + 1;
        }
    }
}

int getValue(int *nums, int n)
{

    int value = nums[0];
    nums[0] = nums[n];
    adjustHeap(nums, n, 0);
    return value;
}
int thirdMax(int *nums, int numsSize)
{
    int value, i = 0;
    int maxvalue[3] = {};
    int k = 0;
    int pos = numsSize / 2 - 1;
    for (int i = pos; i >= 0; i--)
        adjustHeap(nums, numsSize, i);
    maxvalue[i++] = nums[0];
    while (k < numsSize)
    {
        value = getValue(nums, numsSize - k - 1);
        if (value != maxvalue[i - 1])
        {
            maxvalue[i++] = value;
        }
        if (i == 3)
            break;
        k++;
    }
    if (i == 3)
        return maxvalue[i - 1];
    return maxvalue[0];
}
int main(int argc, char const *argv[])
{
    int node[] = {2, 2, 3, 1};
    thirdMax(node, 4);
    return 0;
}
