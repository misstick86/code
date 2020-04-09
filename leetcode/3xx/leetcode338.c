/*
@File    :   leetcode338.c
@Time    :   2020/04/08 21:13:38
@Author  :   xiaosongsong
@Desc    :   None

给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-bits

*/

#include <stdio.h>
#include <malloc.h>
int *countBits(int num, int *returnSize)
{
    int result[9] = {};
    *returnSize = num + 1;
    // result = (int *)malloc(sizeof(int) * (num + 1));
    result[0] = 0;
    for (int i = 1; i <= num; i++)
    {
        if (i % 2 == 0)
            result[i] = result[i - 1];
        else
        {
            result[i] = result[i] + 1;
        }
    }
}
int main()
{
    int size = 0;
    countBits(8, &size);
    return 0;
}
