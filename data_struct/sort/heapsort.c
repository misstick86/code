/*
@File    :   heapsort.c
@Time    :   2020/03/24 17:15:22
@Author  :   xiaosongsong
@Desc    :   None

堆排序，
堆排序是为了解决树型选择排序使用过多的存储空间问题
*/

#include <stdio.h>
#include <malloc.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void adjustHeap(int node[], int n, int pos)
{
    int i = pos;
    int j = 2 * pos + 1;
    while (j < n)
    {
        if (j + 1 < n && node[j + 1] < node[j])
            j++;
        if (node[i] < node[j])
            break;
        if (node[i] > node[j])
        {
            Swap(&node[i], &node[j]);
            i = j;
            j = 2 * i + 1;
        }
    }
}
int getValue(int node[], int n)
{
    int value = node[0];
    node[0] = node[n];
    adjustHeap(node, n, 0);
    return value;
}
int main()
{
    int node[] = {70, 81, 59, 8, 2, 21, 34, 13};
    int *e;
    int count = sizeof(node) / sizeof(int);
    e = (int *)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++)
        e[i] = node[i];
    int pos = count / 2 - 1;
    // 构建最小堆
    for (int i = pos; i >= 0; i--)
        adjustHeap(e, count, i);
    for (int i = 0; i < count; i++)
        node[i] = getValue(e, count - i - 1);
    free(e);
    e = NULL;
    return 0;
}
