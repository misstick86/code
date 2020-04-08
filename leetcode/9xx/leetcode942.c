/*
@File    :   leetcode942.c
@Time    :   2020/04/08 14:22:14
@Author  :   xiaosongsong
@Desc    :   None

给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。

返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：

如果 S[i] == "I"，那么 A[i] < A[i+1]
如果 S[i] == "D"，那么 A[i] > A[i+1]
 

示例 1：

输出："IDID"
输出：[0,4,1,3,2]
示例 2：

输出："III"
输出：[0,1,2,3]
示例 3：

输出："DDI"
输出：[3,2,0,1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/di-string-match
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
int *diStringMatch(char *S, int *returnSize)
{
    int i = 0, j = 0;
    int *result;
    int count = strlen(S);
    *returnSize = count + 1;
    result = (int *)malloc(sizeof(int) * (count + 1));
    while (*S != '\0')
    {
        if (*S == 'I')
            result[i++] = j++;
        if (*S == 'D')
            result[i++] = count--;
        S++;
    }
    result[i] = j;
    return result;
}
int main()
{
    int size = 0;
    char *node = "IDID";
    diStringMatch(node, &size);
    return 0;
}
