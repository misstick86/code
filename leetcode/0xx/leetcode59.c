/*
@File    :   leetcode59.c
@Time    :   2020/03/06 09:03:27
@Author  :   xiaosongsong
@Desc    :   None
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include <stdio.h>
#include <malloc.h>

int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    int **result;
    result = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(sizeof(int) * n);
    }
    int k = 1, row = 0, line = 0;
    ;
    int m = n * n;
    *returnSize = n;
    while (k <= m)
    {
        result[row][line] = k;
        if (line % n == 2)
            row++;
        else
            line++;
    }
}
int main()
{
    int n = 3;
    int size = 0;
    int *p;
    generateMatrix(n, &size, &p);
    return 0;
}
