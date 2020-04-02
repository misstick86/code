/*
@File    :   leetcode561.c
@Time    :   2020/04/02 09:01:42
@Author  :   xiaosongsong
@Desc    :   None

给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

示例 1:

输入: [1,4,3,2]

输出: 4
解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
提示:

n 是正整数,范围在 [1, 10000].
数组中的元素范围在 [-10000, 10000].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-partition-i

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
        if (j + 1 < n && nums[j] > nums[j + 1])
            j++;
        if (nums[k] < nums[j])
            break;
        Swap(&nums[k], &nums[j]);
        k = j;
        j = 2 * j + 1;
    }
}
int getMinValue(int *nums, int n)
{
    int min = nums[0];
    nums[0] = nums[n];
    adjustHeap(nums, n, 0);
    return min;
}
int arrayPairSum(int *nums, int numsSize)
{
    int value = 0;
    int pos = numsSize / 2 - 1;
    // 构建最小堆
    for (int i = pos; i >= 0; i--)
        adjustHeap(nums, numsSize, i);
    for (int i = 0; i < numsSize; i++)
    {
        if (i % 2 == 0)
            value += getMinValue(nums, numsSize - i - 1);
        else
            getMinValue(nums, numsSize - i - 1);
    }
    return value;
}
int main()
{
    int node[] = {1, 4, 3, 2, 8, 5, 10, 34, 22, 15};
    arrayPairSum(node, 10);
    return 0;
}
