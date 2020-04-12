/*
@File    :   leetcode1252.c
@Time    :   2020/04/09 10:54:39
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#include <malloc.h>
int oddCells(int n, int m, int **indices1, int indicesSize, int *indicesColSize)
{
    int indices[2][2] = {{0, 1}, {1, 1}};
    int result[2][3] = {};
    for (int i = 0; i < indicesSize; i++)
    {
        for (int j = 0; j < (*indicesColSize); j++)
        {
            printf("%d,", indices[i][j]);
        }
    }
}
int main()
{
    int size = 2;
    int n = 2, m = 3;
    int node[2][2] = {{0, 1}, {1, 1}};
    oddCells(n, m, node, 2, &size);
    return 0;
}
