/*
@File    :   leetcode171.c
@Time    :   2020/02/13 18:20:17
@Author  :   xiaosongsong
@Desc    :   None
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
示例 1:

输入: "A"
输出: 1
示例 2:

输入: "AB"
输出: 28
示例 3:

输入: "ZY"
输出: 701
致谢：
特别感谢 @ts 添加此问题并创建所有测试用例。
*/

#include <stdio.h>

int titleToNumber(char *s)
{
    unsigned int sum = 0;
    while (*s != '\0')
    {
        sum = sum * 26 + *s - 'A' + 1;
        s++;
    }
    printf("%d", sum);
    return sum;
}
int main()
{
    char *p = "AB";
    titleToNumber(p);
    return 0;
}
