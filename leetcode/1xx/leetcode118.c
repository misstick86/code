/*
@File    :   leetcode118.c
@Time    :   2020/03/20 10:28:24
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#include <malloc.h>
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
    int **result;
    *returnSize = numRows;
    result = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++)
    {
        result[i] = (int *)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        if (i == 0)
            result[i][0] = 1;

        else if (i == 1)
            result[i][0] = 1, result[i][1] = 1;

        else
        {
            result[i][0] = 1;
            result[i][(*returnColumnSizes)[i] - 1] = 1;
            for (int j = 1; j < (*returnColumnSizes)[i] - 1; j++)
            {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
    }
    return result;
}
int main()
{
    int *p = NULL, size = 0;
    generate(5, &size, &p);
    return 0;
}
