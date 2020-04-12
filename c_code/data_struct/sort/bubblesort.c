/*
@File    :   bubblesort.c
@Time    :   2020/03/05 14:20:44
@Author  :   xiaosongsong
@Desc    :   None
冒泡排查
*/

#include <stdio.h>

int main()
{
    int node[] = {70, 81, 59, 21, 92, 34, 13, 76, 8, 2, 11, 22, 77, 53, 18, 28};
    int count = sizeof(node) / sizeof(int);
    int temp;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (node[j] > node[j + 1])
            {
                temp = node[j + 1];
                node[j + 1] = node[j];
                node[j] = temp;
            }
        }
    }
    printf("av");
    return 0;
}
