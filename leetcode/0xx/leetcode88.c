/*
@File    :   leetcode88.c
@Time    :   2020/01/07 20:36:20
@Author  :   xiaosongsong
@Desc    :   None

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <stdlib.h>
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{

    int flag = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n >= 0)
    {

        if (nums1[m] > nums2[n])
        {

            nums1[flag] = nums1[m];
            m--;
        }
        else
        {

            nums1[flag] = nums2[n];
            n--;
        }
        flag--;
    }
    while (n >= 0)
    {
        nums1[flag--] = nums2[n--];
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int i;
    int nums1[] = {0};
    int nums2[] = {1};
    merge(nums1, 0, 0, nums2, 0, 1);
    for (i = 0; i < 1; i++)
    {
        printf("%d\n", nums1[i]);
    }
    return 0;
}
