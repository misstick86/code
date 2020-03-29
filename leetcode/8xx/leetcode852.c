/*
@File    :   leetcode852.c
@Time    :   2020/03/29 12:22:36
@Author  :   xiaosongsong
@Desc    :   None

我们把符合下列属性的数组 A 称作山脉：

A.length >= 3
存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1] 的 i 的值。

 

示例 1：

输入：[0,1,0]
输出：1
示例 2：

输入：[0,2,1,0]
输出：1
 

提示：

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A 是如上定义的山脉


*/

#include <stdio.h>
int halfSearch(int *A, int first, int last)
{
    int pos = (first + last) / 2;
    if (A[pos - 1] < A[pos] && A[pos] > A[pos + 1])
        return pos;
    if (A[pos] < A[pos + 1])
        return halfSearch(A, pos + 1, last);
    else
        return halfSearch(A, first, pos - 1);
}
int peakIndexInMountainArray(int *A, int ASize)
{
    return halfSearch(A, 0, ASize - 1);
}
int main()
{
    int node[] = {1, 2, 3, 4, 5, 6, 7, 4, 2, 1};
    printf("%d", peakIndexInMountainArray(node, 10));
    return 0;
}
