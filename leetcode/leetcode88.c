/*
@File    :   leetcode88.c
@Time    :   2020/01/07 20:36:20
@Author  :   xiaosongsong
@Desc    :   None
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
