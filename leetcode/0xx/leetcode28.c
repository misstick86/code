/*
@File    :   leetcode28.c
@Time    :   2020/04/08 18:59:14
@Author  :   xiaosongsong
@Desc    :   None

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int strStr(char *haystack, char *needle)
{
    bool flag = false;
    char *temp;
    temp = needle;
    int count = 0;
    if (strlen(needle) > strlen(haystack))
        return -1;
    if (strlen(needle) == 0)
        return count;
    while (*haystack != '\0')
    {
        while (*needle != '\0' && *needle == *haystack)
        {
            flag = true;
            count++;
            haystack++;
            needle++;
        }
        if (*needle == '\0')
            return count - strlen(temp);
        if (flag)
        {
            int a = strlen(needle) - strlen(temp) + 1;
            haystack = haystack + a;
            count += a;
            needle = temp;
            flag = false;
            continue;
        }
        haystack++;
        count++;
    }
    return -1;
}
int main()
{
    char *node = "babba";
    char *node2 = "bbb";
    printf("%d", strStr(node, node2));
    return 0;
}
