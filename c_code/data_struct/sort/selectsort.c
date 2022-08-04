/*
@File    :   selectsort.c
@Time    :   2020/03/06 10:57:27
@Author  :   xiaosongsong
@Desc    :   None
选择排序, 在n序列中，
第一次： 以0位置为首，并在其之后的元素中选择最小元素放在0位置。
第一次选择后首节点的元素必然是最小元素。
以此内推。

问题：
对于N个记录的数据，每一趟的记录都会有N-i次的比较，可以作为改进点。
*/

#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int getPos(int *node, int k, int count){
    int pos = k;
    int min = node[k];
    for (int i = k + 1; i < count; i++)
        if (node[i] < min)
        {
            min = node[i];
            pos = i;
        }
    return pos;
}
void selectSort(int *node, int count)
{
    for (int i = 0; i < count; i++)
    {
        int j = getPos(node, i, count);
        if (j != i)
            Swap(&node[i], &node[j]);
    }

}
int main(int argc, char const *argv[])
{
    int node[] = {70, 81, 59, 8, 2, 21, 92, 34, 13, 76};
    int count = sizeof(node) / sizeof(int);
    selectSort(node, count);
    for (int i = 0; i < count; i++)
    {
        printf("%d,", node[i]);
    }

}

/*
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

*/