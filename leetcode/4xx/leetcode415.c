/*
@File    :   leetcode415.c
@Time    :   2020/02/27 09:30:12
@Author  :   xiaosongsong
@Desc    :   None

给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
char *addStrings(char *num1, char *num2)
{
    int flag = 0;
    int add = 0;
    char *result;
    int num1len = strlen(num1);
    int num2len = strlen(num2);
    int max = num1len > num2len ? num1len : num2len;
    int min = num1len < num2len ? num1len : num2len;
    char *p;
    p = (char *)malloc(sizeof(char) * max);
    result = (char *)malloc(sizeof(char) * (max + 1));
    for (int i = max; i > max - min; i--)
    {
        add = num1[--num1len] + num2[--num2len] - 96;
        result[i] = (add + flag) % 10 + 48;
        flag = (add + flag) / 10;
    }
    if (num1len)
    {
        result[num1len] = ((num1[--num1len] + flag - 48) % 10 + 48);
        flag = (num1[--num1len] + flag - 48) / 10;
        if (flag)
        {
        }
        strncpy(result, num1, max - min - 1);
    }
    if (num2len)
    {
        result[num2len] = num2[--num2len] + flag;
        strncpy(result, num2, max - min - 1);
    }
    printf("%s", result);
    return result;
}
int main()
{
    char *a = "978", *b = "89";
    addStrings(a, b);
    return 0;
}
