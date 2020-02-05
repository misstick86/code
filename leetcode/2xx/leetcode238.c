/*
@File    :   leetcode238.c
@Time    :   2020/02/05 11:13:42
@Author  :   xiaosongsong
@Desc    :   None

给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *result;
    result = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        result[i] = 1;
    }
    int first = 1, last = 1;
    for (int i = 0; i < numsSize; i++)
    {
        result[i] *= first;
        first *= nums[i];

        result[numsSize - i - 1] *= last;
        last *= nums[numsSize - i - 1];
        // last *= nums[numsSize - i - 1];
    }
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        // result[i] = nums[i];
        printf("%d,", result[i]);
    }
    // // printf("%d", first);
    return result;
}
int main()
{
    int b;
    int a[] = {1, 2, 3, 4};
    productExceptSelf(a, 4, &b);
    return 0;
}
