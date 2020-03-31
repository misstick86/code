/*
@File    :   leetcode240.c
@Time    :   2020/03/31 12:11:09
@Author  :   xiaosongsong
@Desc    :   None


编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix-ii


*/

#include <stdio.h>
#include <stdbool.h>
bool halfSearch(int *nums, int left, int right, int target)
{
    int pos = (left + right) / 2;
    if (left <= right)
    {
        if (nums[pos] == target)
            return true;
        if (nums[pos] > target)
            return halfSearch(nums, left, pos - 1, target);
        return halfSearch(nums, pos + 1, right, target);
    }
    return false;
}
int SearchRow(int **node, int first, int last, int target)
{
    int matrix[1][5] = {{1, 4, 7, 11, 15}};
    int pos = (first + last) / 2;
    if (matrix[pos][0] <= target && matrix[pos + 1][0] > target)
        return pos;
    if (matrix[pos][0] < target)
        return SearchRow(matrix, pos + 1, last, target);
    return SearchRow(matrix, first, pos - 1, target);
}
bool searchMatrix(int **node, int matrixRowSize, int matrixColSize, int target)
{

    int matrix[1][5] = {{1, 4, 7, 11, 15}};
    bool flag = false;
    if (matrixColSize == 0 || matrixRowSize == 0)
        return false;
    if (target < matrix[0][0] || target > matrix[matrixRowSize - 1][matrixColSize - 1])
        return false;
    int pos = SearchRow(matrix, 0, matrixRowSize - 1, target);
    while (pos >= 0)
    {
        flag = halfSearch(matrix[pos], 0, matrixColSize, target);
        if (flag)
            return flag;
        pos--;
    }
    return false;
}
int main()
{
    int node[5][5] = {{1, 4, 7, 11, 15},
                      {2, 5, 8, 12, 19},
                      {3, 6, 9, 16, 22},
                      {10, 13, 14, 17, 24},
                      {18, 21, 23, 26, 30}};
    searchMatrix(node, 1, 5, 5);
    return 0;
}
