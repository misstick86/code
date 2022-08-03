/*
@File    :   shellsort.c
@Time    :   2020/03/05 11:30:51
@Author  :   xiaosongsong
@Desc    :   None

希尔排序
*/

#include <stdio.h>

void shellsort(int *node, int count, int k)
{
    int temp, j; //临时存储
    for (int i = k; i < count; i = i + k)
    {
        temp = node[i];
        // 每个相隔k距离的位置做一下调换，看成一次插入排序
        for (j = i - k; j >= 0 && temp < node[j]; j = j - k)
        {
            node[j + k] = node[j];
        }
        node[j + k] = temp;
    }
}
int main()
{
    int node[] = {70, 81, 59, 21, 92, 34, 13, 76, 8, 2, 11, 22, 77, 53, 18, 28};
    int count = sizeof(node) / sizeof(int);
    int d[] = {5, 3, 2, 1};
    for (int i = 0; i < 4; i++)
    {
        shellsort(node, count, d[i]);
    }
    for (int i=0; i< count; i++){
        printf("%d ", node[i]);
    }
    return 0;
}
