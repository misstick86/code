/*
@File    :   leetcode350.c
@Time    :   2020/03/05 17:13:28
@Author  :   xiaosongsong
@Desc    :   None
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii

双指针
*/

#include <stdio.h>
#include <malloc.h>
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int min = nums1Size > nums2Size ? nums1Size : nums2Size;
    int *result;
    result = (int *)malloc(sizeof(int) * min);
    while ()
    {
        /* code */
    }
    
}
int main()
{
    int size = 0;
    int node1[] = {4, 9, 5};
    int node2[] = {9, 4, 9, 8, 4};
    intersect(node1, 3, node2, 5, &size);
    return 0;
}
