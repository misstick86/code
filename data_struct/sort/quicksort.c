/*
@File    :   quicksort.c
@Time    :   2020/03/05 17:14:04
@Author  :   xiaosongsong
@Desc    :   None
快速排查

*/

#include <stdio.h>

int quickSort(int *node, int left, int right)
{
    int temp = node[left];
    while (left < right)
    {
        while (left < right && node[right] > temp)
            right--;
        node[left] = node[right];
        while (left < right && node[left] < temp)
            left++;
        node[right] = node[left];
    }
    node[right] = temp;
    return right;
}
int main()
{
    int node[] = {70, 81, 59, 8, 2, 21, 92, 34, 13, 76};
    int count = sizeof(node) / sizeof(int);
    int left = 0, right = count - 1;
    int pos;
    if (left < right)
    {
        pos = quickSort(node, left, right);
        quickSort(node, left, pos - 1);
        quickSort(node, pos + 1, right);
    }
    return 0;
}
