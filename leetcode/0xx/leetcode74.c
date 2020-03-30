/*
@File    :   leetcode74.c
@Time    :   2020/03/30 10:35:18
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#include <stdbool.h>
bool halfSearch(int *nums, int first, int last, int target)
{
    int pos = (first + last) / 2;
    if (last < first)
        return false;
    if (nums[pos] == target)
        return true;
    if (nums[pos] > target)
        return halfSearch(nums, first, pos - 1, target);
    return halfSearch(nums, pos + 1, last, target);
}
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int i;
    if (matrixSize == 0 || matrixColSize[0] == 0)
        return false;
    if (matrix[0][0] > target)
        return false;
    if (matrix[matrixSize - 1][matrixColSize[0] - 1] < target)
        return false;
    for (i = 0; i < matrixSize - 1; i++)
    {
        if (matrix[i][0] == target)
            return true;
        if (matrix[i][0] < target && matrix[i + 1][0] > target)
            break;
    }
    return halfSearch(matrix[i], 0, matrixColSize[0] - 1, target);
}
int main()
{
    int size[] = {4, 4, 4, 4};
    int node[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    searchMatrix(node, 3, size, 80);
    return 0;
}
