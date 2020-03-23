/*
@File    :   leetcode387.c
@Time    :   2020/03/22 20:10:49
@Author  :   xiaosongsong
@Desc    :   None
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.

*/

#include <stdio.h>
#include <string.h>
int firstUniqChar(char *s)
{
    char *p, *q;
    char x;
    int i = 0;
    while (*s != '\0')
    {
        if (!strchr(++s, x))
            return i;
        i++;
    }
    return -1;
}
int main()
{
    char *s = "looveleetcde";
    firstUniqChar(s);
    return 0;
}
