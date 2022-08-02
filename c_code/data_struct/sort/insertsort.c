/*
@File    :   insertsort.c
@Time    :   2020/03/04 21:10:46
@Author  :   xiaosongsong
@Desc    :   None

直接插入排序
*/

#include <stdio.h>


void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// 该函数是从要插入的地方不断的和前面的数据对比, 然后交换.  
// 可以优化的点是使用一个临时辅助空间保存要插入的数据, 然后和之前排序好的数据对比, 不段的将数据向后移动, 然后将这个数据插入到对应的位置.
// 对应于下面的insertSort2函数.
void insertSort(int *node, int n) {
    for(int i=1; i<n;i++){
        if (node[i]< node[i-1]){
            swap(&node[i],&node[i-1]);
        }
        for(int j=i-1; j>0 && node[j]<node[j-1]; j--) {
               swap(&node[j], &node[j-1]);
        }
    }
}

void insertSort2(int *node, int n) {
    int temp, j;
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
}


int main(int argc, char const *argv[])
{
    int node[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(node) / sizeof(int);
    // insertSort(node,n);
    insertSort2(node,n);
    for (int i=0; i<n; i++){
        printf("%d ", node[i]);
    }

    return 0;
}
