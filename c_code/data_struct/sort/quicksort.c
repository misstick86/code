/*
@File    :   quicksort.c
@Time    :   2022/08/04 17:14:04
@Author  :   xiaosongsong
@Desc    :   快速排序

*/

#include <stdio.h>

int Pos(int *node, int left, int right)
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

void quickSort(int *node, int left, int right)
{
    int pos;
    if (left < right) {
        pos = Pos(node, left, right);
        quickSort(node, left, pos-1);
        quickSort(node, pos+1, right);
    }

}


int main()
{

    // 28 18 59 21 53 5 34 13 22 8 2 11
    int node[] = {70, 81, 59, 21, 92, 34, 13, 76, 8, 2, 11, 22, 77, 53, 18, 28};
    int count = sizeof(node) / sizeof(int);
    int left = 0, right = count - 1;
    quickSort(node, left, right);
    for(int i=0; i<count; i++){
        printf("%d ", node[i]);
    }
    return 0;
}
