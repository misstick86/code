/*
@File    :   leetcode905.c
@Time    :   2020/01/17 18:37:28
@Author  :   xiaosongsong
@Desc    :   None
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 

提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool isEven(int value)
{
    return value % 2 == 0;
}
int *sortArrayByParity(int *A, int ASize, int *returnSize)
{
    int *result;
    result = (int *)malloc(sizeof(int) * ASize);
    int i = 0, j = ASize - 1;
    for (int k = 0; k < ASize; k++)
    {
        if (isEven(A[k]))
        {
            result[i] = A[k];
            i++;
        }
        else
        {
            result[j] = A[k];
            j--;
        }
    }

    for (int i = 0; i < ASize; i++)
    {
        printf("\n%d", result[i]);
    }
    return result;
}

int main()
{
    int *p;
    int nums[] = {3, 1, 2, 4};
    sortArrayByParity(nums, 4, p);
    return 0;
}
