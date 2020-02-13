/*
@File    :   leetcode680.c
@Time    :   2020/02/13 09:53:45
@Author  :   xiaosongsong
@Desc    :   None
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool Judge_char(char *str, int len)
{
    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool validPalindrome(char *s)
{
    int i = 0;
    char *p;
    int len = strlen(s);
    bool flag = Judge_char(s, len);
    len--;
    if (!flag)
    {
        while (s[i] == s[len])
        {
            i++;
            len--;
        }
        if (s[i + 1] == s[len])
        {
            i++;
            p = s + i;
            flag = Judge_char(p, len - i + 1);
            i--;
        }
        if (s[i] == s[len - 1])
        {
            len--;
            return flag || Judge_char((s + i), len - i + 1);
        }
    }
    return flag;
}
int main()
{
    char *p = "lcupuupucul";
    printf("%d", validPalindrome(p));
    return 0;
}
