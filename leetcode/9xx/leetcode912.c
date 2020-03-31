/*
@File    :   leetcode912.c
@Time    :   2020/03/31 11:13:54
@Author  :   xiaosongsong
@Desc    :   None
给定一个整数数组 nums，将该数组升序排列。

 

示例 1：

输入：[5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array


采用快速排序方法

*/

#include <stdio.h>

int Partion(int *nums, int left, int right)
{
    int temp = nums[left];
    while (left < right)
    {
        while (left < right && nums[right] >= temp)
            right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= temp)
            left++;
        nums[right] = nums[left];
    }
    nums[left] = temp;
    return left;
}

void quickSort(int *nums, int left, int right)
{
    if (left < right)
    {
        int pos = Partion(nums, left, right);
        quickSort(nums, left, pos - 1);
        quickSort(nums, pos + 1, right);
    }
}
int *sortArray(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    quickSort(nums, 0, numsSize - 1);
    return nums;
}
int main()
{
    int size = 0;
    int node[] = {5, 1, 1, 2, 0, 0};
    sortArray(node, 6, &size);
    return 0;
}
