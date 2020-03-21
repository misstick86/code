/*
@File    :   leetcode119.c
@Time    :   2020/03/21 08:26:02
@Author  :   xiaosongsong
@Desc    :   None
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
*/

#include <stdio.h>
#include <malloc.h>

int *getRow(int rowIndex, int *returnSize)
{
    int pos;
    int *result;
    *returnSize = rowIndex;
    result = (int *)malloc(sizeof(int) * rowIndex);
    for (int i = 0; i < rowIndex; i++)
    {
        if (i == 0)
            result[i] = 1;
        if (i == 1)
            result[0] = 1, result[i] = 1;
        pos = i / 2;
        while (pos--)
        {
            result[pos] = 
        }
    }
}
int main()
{

    return 0;
}
