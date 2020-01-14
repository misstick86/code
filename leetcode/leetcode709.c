/*
@File    :   leetcode709.c
@Time    :   2020/01/09 21:58:20
@Author  :   xiaosongsong
@Desc    :
实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

示例 1：

输入: "Hello"
输出: "hello"
示例 2：

输入: "here"
输出: "here"
示例 3：

输入: "LOVELY"
输出: "lovely"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *toLowerCase(char *str)
{
    char *p;
    p = str;
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = *str + 32;
        }
        str++;
    }
    return p;
}
int main()
{
    char s[] = "Hello";
    toLowerCase(s);
    // printf("%p", s);
    return 0;
}
