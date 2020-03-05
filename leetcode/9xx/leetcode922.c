/*
@File    :   leetcode922.c
@Time    :   2020/03/05 19:10:42
@Author  :   xiaosongsong
@Desc    :   None

给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。



示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
*/

#include <stdio.h>
#include <malloc.h>
int *sortArrayByParityII(int *A, int ASize, int *returnSize)
{
    int *result;
    result = (int *)malloc(sizeof(int) * ASize);
    int k = 0, j = 1;
    *returnSize = ASize;
    for (int i = 0; i < ASize; i++)
    {
        if (A[i] % 2 == 0)
        {
            result[k] = A[i];
            k += 2;
        }
        else
        {
            result[j] = A[i];
            j += 2;
        }
    }
    return result;
}
int main()
{
    int size;
    int a[] = {4, 2, 5, 7};
    sortArrayByParityII(a, 4, &size);
    return 0;
}
