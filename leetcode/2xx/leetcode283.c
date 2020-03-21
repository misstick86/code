/*
@File    :   leetcode283.c
@Time    :   2020/03/21 16:11:52
@Author  :   xiaosongsong
@Desc    :   None
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

*/

#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void moveZeroes(int *nums1, int numsSize)
{
    int temp, j, i = 0;
    int nums[] = {0, 1, 0, 0, 3, 5, 2, 11, 16, 0, 0, 0, 14, 0};
    while (i < numsSize)
    {
        if (nums[i] == 0)
        {
            int j = i + 1;
            while (nums[j] == 0 && j < numsSize)
                j = j + 1;
            if (j < numsSize)
                Swap(&nums[i], &nums[j]);
            if (j == numsSize || j + 1 == numsSize)
                break;
        }
        i++;
    }
}
int main()
{
    int node[] = {0, 1, 0, 0, 0, 0, 3, 5};
    moveZeroes(node, 14);
    return 0;
}
