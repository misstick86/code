/*
@File    :   leetcode167.c
@Time    :   2020/03/21 08:37:49
@Author  :   xiaosongsong
@Desc    :   None

给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/

#include <stdio.h>
#include <malloc.h>
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int *result;
    int index1 = 0, index2 = 0;
    for (index1 = 0; index1 < numbersSize; index1++)
    {
        for (index2 = index1 + 1; index2 < numbersSize; index2++)
        {
            if (numbers[index1] + numbers[index2] == target)
            {
                result = (int *)malloc(sizeof(int) * 2);
                result[0] = index1 + 1;
                result[1] = index2 + 1;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    result = NULL;
    return result;
}
int main()
{
    int size = 0;
    int number[] = {2, 7, 11, 15};
    twoSum(number, 4, 23, &size);
    return 0;
}
