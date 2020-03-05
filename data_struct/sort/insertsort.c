/*
@File    :   insertsort.c
@Time    :   2020/03/04 21:10:46
@Author  :   xiaosongsong
@Desc    :   None

直接插入排序
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int temp, j;
    int node[] = {9, 10, 38, 25, 13, 2};
    int n = sizeof(node) / sizeof(int);
    for (int i = 1; i < n; i++)
    {
        temp = node[i]; //辅助空间
        if (temp < node[i - 1])
        {
            // 从后向前挪动位置
            for (j = i - 1; node[j] > temp; j--)
            {
                node[j + 1] = node[j];
            }
            node[j + 1] = temp;
        }
    }
    return 0;
}
