/*
@File    :   selectsort.c
@Time    :   2020/03/06 10:57:27
@Author  :   xiaosongsong
@Desc    :   None
选择排序, 在n序列中，
第一次： 以0位置为首，并在其之后的元素中选择最小元素放在0位置。
第一次选择后首节点的元素必然是最小元素。
以此内推。
*/

#include <stdio.h>

int main()
{
    int node[] = {70, 81, 59, 8, 2, 21, 92, 34, 13, 76};
    int count = sizeof(node) / sizeof(int);
    int min, k;
    for (int i = 0; i < count - 1; i++)
    {
        min = node[i + 1];
        for (int j = i + 1; j < count - 1; j++)
        {
            if (node[j] < min)
            {
                k = j;
                min = node[j];
            }
        }
        if (min == node[i + 1])
        {
            node[i + 1] = node[i];
            node[i] = min;
        }
        else
        {
            node[k] = node[i];
            node[i] = min;
        }
    }
    return 0;
}
