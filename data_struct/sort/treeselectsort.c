/*
@File    :   treeselectsort.c
@Time    :   2020/03/24 10:10:53
@Author  :   xiaosongsong
@Desc    :   None
树型选择排序

解决选择排序的问题：

解决选择排序比较次数较多的问题。

带来问题：
所需的辅助空间较多，堆排序解决了这个问题。
*/

#include <stdio.h>
#include <malloc.h>
#define MaxValue 0x7FFFFFFF
int getEValue(int e[], int n, int pos)
{
    int value;
    if (pos > n / 2 - 1)
    {
        value = e[pos];
    }
    else
    {
        value = e[e[pos]];
    }
    return value;
}
void treeSelect(int e[], int n, int p)
{
    int left, right;
    int leftValue, rightValue;
    while (p >= 0)
    {
        left = 2 * p + 1;
        right = 2 * p + 2;
        leftValue = getEValue(e, n, left);
        rightValue = getEValue(e, n, right);
        if (leftValue <= rightValue)
        {
            if (left >= n / 2)
                e[p] = left;
            else
                e[p] = e[left];
        }
        else
        {
            if (right >= n / 2)
                e[p] = right;
            else
                e[p] = e[right];
        }
        p--;
    }
}

void treeAdjust(int e[], int n, int p)
{
    int i = (p - 1) / 2;
    int left, right;
    int leftValue, rightValue;
    int flag = 2;
    while (flag && i >= 0)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        leftValue = getEValue(e, n, left);
        rightValue = getEValue(e, n, right);
        if (leftValue <= rightValue)
        {
            if (left >= n / 2)
                e[i] = left;
            else
                e[i] = e[left];
        }
        else
        {
            if (right >= n / 2)
                e[i] = right;
            else
                e[i] = e[right];
        }
        i = (i - 1) / 2;
        if (i == 0)
            flag--;
    }
}

int main()
{
    int *e;
    int node[] = {70, 81, 59, 8, 2, 21, 34, 13};
    int count = sizeof(node) / sizeof(int);
    int size = 2 * count - 1;
    e = (int *)malloc(sizeof(int) * size);
    int p = size / 2;
    for (int i = 0; i < count; i++)
        e[p++] = node[i];

    // 对e进行树型调整
    treeSelect(e, size, size / 2 - 1);
    node[0] = e[e[0]];
    e[e[0]] = MaxValue;
    // printf("%d", e[e[0]]);
    for (int i = 1; i < count; i++)
    {
        treeAdjust(e, size, e[0]);
        node[i] = e[e[0]];
        e[e[0]] = MaxValue;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d,", node[i]);
    }

    return 0;
}
