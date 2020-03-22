/*
@File    :   leetcode977.c
@Time    :   2020/03/22 19:39:15
@Author  :   xiaosongsong
@Desc    :   None
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
示例 2：

输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

*/

#include <stdio.h>
#include <malloc.h>

int *sortedSquares(int *A, int ASize, int *returnSize)
{
    int *result, j = 0;
    result = (int *)malloc(sizeof(int) * ASize);
    *returnSize = ASize;
    for (int i = 0; i < ASize; i++)
    {
        int t = A[i] * A[i];
        j = i;
        while (j && result[j - 1] > t)
            result[j--] = result[j - 1];
        result[j] = t;
    }
    for (int i = 0; i < ASize; i++)
    {
        printf("%d,", result[i]);
    }
    return result;
}
int main()
{
    int size = 0;
    int a[] = {-4, -1, 0, 3, 10};
    sortedSquares(a, 5, &size);
    return 0;
}
