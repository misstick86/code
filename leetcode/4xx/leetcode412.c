/*
@File    :   leetcode412.c
@Time    :   2020/03/21 20:15:08
@Author  :   xiaosongsong
@Desc    :   None
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]


*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int getNumberCount(int n)
{
    int count = 0;
    while (n)
    {
        n = n / 10;
        count++;
    }
    return count;
}
char **fizzBuzz(int n, int *returnSize)
{
    char **result;
    int count = 0;
    *returnSize = n;
    char *s1 = "Fizz", *s2 = "Buzz", *s3 = "FizzBuzz";
    result = (char **)malloc(sizeof(char *) * n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            result[i - 1] = (char *)malloc(sizeof(char) * (strlen(s3) + 1));
            strcpy(result[i - 1], s3);
            continue;
        }
        if (i % 3 == 0)
        {
            result[i - 1] = (char *)malloc(sizeof(char) * (strlen(s1) + 1));
            strcpy(result[i - 1], s1);
            continue;
        }
        if (i % 5 == 0)
        {
            result[i - 1] = (char *)malloc(sizeof(char) * (strlen(s2) + 1));
            strcpy(result[i - 1], s2);
            continue;
        }
        count = getNumberCount(i);
        result[i - 1] = (char *)malloc(sizeof(char) * (count + 1));
        sprintf(result[i - 1], "%d", i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", result[i]);
    }
}
int main()
{
    int size = 0;
    fizzBuzz(15, &size);
    return 0;
}
