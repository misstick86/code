/*
@File    :   leetcode1313.c
@Time    :   2020/01/22 21:21:59
@Author  :   xiaosongsong
@Desc    :   None
给你一个以行程长度编码压缩的整数列表 nums 。

考虑每相邻两个元素 [a, b] = [nums[2*i], nums[2*i+1]] （其中 i >= 0 ），每一对都表示解压后有 a 个值为 b 的元素。

请你返回解压后的列表。


示例：

输入：nums = [1,2,3,4]
输出：[2,4,4,4]
 

提示：

2 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100

*/

#include <stdio.h>
#include <stdlib.h>
int *decompressRLElist(int *nums, int numsSize, int *returnSize)
{
    int *result;
    result = (int *)malloc(sizeof(int) * 10240);
    int j, k = 0;
    for (int i = 0; i < numsSize; i += 2)
    {
        j = nums[i];
        // printf("%d", j);
        while (j)
        {
            result[k] = nums[i + 1];
            j--;
            k++;
        }

        // printf("%d", nums[i]);
    }
    *returnSize = k;
    return result;
}
int main()
{
    int nums[] = {1, 2, 3, 4};
    int result[] = {};
    decompressRLElist(nums, 4, result);
    return 0;
}
