/*
@File    :   leetcode1351.c
@Time    :   2020/03/30 20:00:05
@Author  :   xiaosongsong
@Desc    :   None
给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 

请你统计并返回 grid 中 负数 的数目。

 

示例 1：

输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
输出：8
解释：矩阵中共有 8 个负数。
示例 2：

输入：grid = [[3,2],[1,0]]
输出：0
示例 3：

输入：grid = [[1,-1],[-1,-1]]
输出：3
示例 4：

输入：grid = [[-1]]
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix

*/

#include <stdio.h>
int halfSearch(int *nums, int first, int last)
{
    int pos = (first + last) / 2;
    if (pos > 0 && nums[pos - 1] >= 0 && nums[pos] < 0)
        return pos;
    if (nums[pos] >= 0)
        return halfSearch(nums, pos + 1, last);
    else
        return halfSearch(nums, first, pos - 1);
}
int countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int i, count = 0;
    if (gridSize == 0 || gridColSize[0] == 0)
        return count;
    int n = gridColSize[0];
    int node[4][5] = {{3, -1, -3, -3, -3}, {2, -2, -3, -3, -3}, {1, -2, -3, -3, -3}, {0, -3, -3, -3, -3}};
    for (i = 0; i < gridSize; i++)
    {
        if (node[i][0] < 0)
            break;
        if (node[i][n - 1] >= 0)
            continue;
        count += (n - halfSearch(node[i], 0, n - 1));
    }
    count += (gridSize - i) * n;
    return count;
}
int main()
{
    int size[] = {5, 5, 5, 5, 5};
    int node[4][4] = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    countNegatives(node, 4, size);
    return 0;
}
