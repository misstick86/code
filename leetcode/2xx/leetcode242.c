/*
@File    :   leetcode242.c
@Time    :   2020/03/05 21:57:49
@Author  :   xiaosongsong
@Desc    :   None
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

通过次数78,620提交次数133,946

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool Equle(char *p, char *q)
{
    if (p[0] == q[0] && p[1] == q[1])
        return true;
    if (p[0] == q[1] && p[1] == q[0])
        return true;
    return false;
}
bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    while (*s != '\0' && *(s + 1) != '\0')
    {
        if (!Equle(s, t))
            return false;
        s += 2;
        t += 2;
    }
    if (*s != '\0')
    {
        return *s == *t;
    }
    return true;
}
int main()
{
    char *s = "rat";
    char *t = "car";
    printf("%d", isAnagram(s, t));
    return 0;
}
