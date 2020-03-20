/*
@File    :   leetcode66.c
@Time    :   2020/03/20 08:16:50
@Author  :   xiaosongsong
@Desc    :   None
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

*/

#include <stdio.h>
#include <malloc.h>
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int mod = 1;
    int *result;
    *returnSize = digitsSize;
    result = (int *)malloc(sizeof(int) * (digitsSize + 1));
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        result[i + 1] = (digits[i] + mod) % 10;
        mod = (digits[i] + mod) / 10;
    }
    if (mod)
    {
        result[0] = mod;
        *returnSize = digitsSize + 1;
    }
    else
        result++;
    return result;
}
int main()
{
    int size = 0;
    int a[] = {1, 9, 9};
    plusOne(a, 3, &size);
    return 0;
}
