/*
@File    :   leetcode215.c
@Time    :   2020/03/24 18:54:51
@Author  :   xiaosongsong
@Desc    :   None

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4


*/

#include <stdio.h>
#include <malloc.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void adjustHeap(int nums[], int n, int k)
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

int getValue(int nums[], int n)
{
    int value = nums[0];
    nums[0] = nums[n];
    adjustHeap(nums, n, 0);
    return value;
}
int findKthLargest(int *nums, int numsSize, int k)
{
    int value;
    // 构建堆
    int pos = numsSize / 2 - 1;
    for (int i = pos; i >= 0; i--)
        adjustHeap(nums, numsSize, i);
    for (int i = 0; i < k; i++)
        value = getValue(nums, numsSize - i - 1);
    return value;
}
int main()
{
    int node[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int count = sizeof(node) / sizeof(int);
    findKthLargest(node, count, 4);
    return 0;
}
