/*
@File    :   leetcode378.c
@Time    :   2020/03/30 11:56:36
@Author  :   xiaosongsong
@Desc    :   None

给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

示例:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix
*/

#include <stdio.h>
int kthSmallest(int **matrix, int matrixSize, int *matrixColSize, int k)
{
    int pos = k / matrixSize;
    
}
int main()
{
    int col[] = {3, 3, 3};
    int node[3][3] = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    kthSmallest(node, 3, col, 8);
    return 0;
}
