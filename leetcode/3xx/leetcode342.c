/*
@File    :   leetcode342.c
@Time    :   2020/01/29 22:31:39
@Author  :   xiaosongsong
@Desc    :   None

给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

示例 1:

输入: 16
输出: true
示例 2:

输入: 5
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

*/

#include <stdio.h>
#include <stdbool.h>
bool isPowerOfFour(int num)
{
    if (num == 1)
    {
        return true;
    }
    while (num % 4)
    {
        num = num / 4;
    }
    return num == 0;
}
int main()
{
    isPowerOfFour(5);
    return 0;
}
