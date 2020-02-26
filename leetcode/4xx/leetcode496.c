/*
@File    :   leetcode496.c
@Time    :   2020/01/28 21:40:09
@Author  :   xiaosongsong
@Desc    :   None

给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于num1中的数字2，第二个数组中的下一个较大数字是3。
    对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
注意:

nums1和nums2中所有元素是唯一的。
nums1和nums2 的数组大小都不超过1000。
*/

#include <stdio.h>
#include <malloc.h>
typedef struct Dict
{
    int key;
    int value;
} Dict;
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int *result;
    Dict *nums2dict;
    nums2dict = (Dict *)malloc(sizeof(Dict) * nums2Size);
    result = (int *)malloc(sizeof(int) * nums1Size);
    result = NULL;
    if (nums2Size == 0)
        return NULL;
    for (int i = 0; i < nums2Size; i++)
    {
        for (int j = i + 1; j < nums2Size; j++)
        {
            if (nums2[j] > nums2[i])
            {
                nums2dict[i].key = nums2[i];
                nums2dict[i].value = nums2[j];
                break;
            }
            if (j == nums2Size - 1)
            {
                nums2dict[i].key = nums2[i];
                nums2dict[i].value = -1;
            }
        }
    }
    nums2dict[nums2Size - 1].key = nums2[nums2Size - 1];
    nums2dict[nums2Size - 1].value = -1;
    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2dict[j].key)
            {
                result[i] = nums2dict[j].value;
            }
        }
    }
    *returnSize = nums1Size;
    // for (int i = 0; i < nums1Size; i++)
    // {
    //     printf("%d", result[i]);
    // }
    return result;
}
int main()
{
    int size = 0;
    int nums1[] = {4, 1, 2}, nums2[] = {1, 3, 4, 2};
    nextGreaterElement(nums1, 3, nums2, 4, &size);
    return 0;
}
