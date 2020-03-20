/*
@File    :   leetcode989.c
@Time    :   2020/03/20 08:35:13
@Author  :   xiaosongsong
@Desc    :   None
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。



示例 1：

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
示例 2：

输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455
示例 3：

输入：A = [2,1,5], K = 806
输出：[1,0,2,1]
解释：215 + 806 = 1021
示例 4：

输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
输出：[1,0,0,0,0,0,0,0,0,0,0]
解释：9999999999 + 1 = 10000000000

*/

#include <stdio.h>
#include <malloc.h>
int getKcount(int k)
{
    int i = 0;
    while (k)
    {
        k = k / 10;
        i++;
    }
    return i;
}
int *addToArrayForm(int *A, int ASize, int K, int *returnSize)
{
    int mod = 0, i, count;
    int *result;
    *returnSize = ASize;
    count = getKcount(K);
    if (count > ASize)
    {
        *returnSize = count;
        result = (int *)malloc(sizeof(int) * (count + 1));
        for (i = ASize - 1; i >= 0; i--)
        {
            result[count--] = (A[i] + K % 10 + mod) % 10;
            mod = (A[i] + K % 10 + mod) / 10;
            K = K / 10;
        }
        while (K)
        {
            result[count--] = (K % 10 + mod) % 10;
            mod = (K % 10 + mod) / 10;
            K = K / 10;
        }
    }
    else
    {
        *returnSize = ASize;
        result = (int *)malloc(sizeof(int) * (ASize + 1));
        for (i = ASize - 1; i >= 0; i--)
        {
            result[i + 1] = (A[i] + K % 10 + mod) % 10;
            mod = (A[i] + K % 10 + mod) / 10;
            K = K / 10;
        }
    }

    if (mod)
    {
        (*returnSize)++;
        result[0] = mod;
    }
    else
        result++;

    return result;
    for (int i = 0; i < *returnSize; i++)
    {
        printf("%d,", result[i]);
    }
}
int main()
{
    int size = 0;
    int a[] = {6};
    addToArrayForm(a, 1, 805, &size);
    return 0;
}
