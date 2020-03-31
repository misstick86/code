/*
@File    :   leetcode1304.c
@Time    :   2020/03/31 18:46:44
@Author  :   xiaosongsong
@Desc    :   None

给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。

 

示例 1：

输入：n = 5
输出：[-7,-1,1,3,4]
解释：这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
示例 2：

输入：n = 3
输出：[-1,0,1]
示例 3：

输入：n = 1
输出：[0]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-n-unique-integers-sum-up-to-zero

*/

#include <stdio.h>
#include <malloc.h>
int *sumZero(int n, int *returnSize)
{
    int *result;
    int j = 0;
    *returnSize = n;
    result = (int *)malloc(sizeof(int) * n);
    if (n == 1)
    {
        result[0] = 0;
        return result;
    }

    if (n % 2 == 0)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            result[j++] = i;
            result[j++] = i * (-1);
        }
    }
    else
    {
        result[j++] = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            result[j++] = i;
            result[j++] = i * (-1);
        }
    }
    return result;
}
int main()
{
    int size = 0;
    sumZero(5, &size);
    return 0;
}
