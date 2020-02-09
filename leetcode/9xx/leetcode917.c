/*
@File    :   leetcode917.c
@Time    :   2020/02/08 21:18:37
@Author  :   xiaosongsong
@Desc    :   None

给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

 

示例 1：

输入："ab-cd"
输出："dc-ba"
示例 2：

输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
 

提示：

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S 中不包含 \ or "

*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

bool isAlpha(char s)
{
    return s >= 65 && s <= 90 || s >= 97 && s <= 122;
}
char *reverseOnlyLetters(char *S)
{
    int length, count;
    char *p;
    length = strlen(S);
    count = length - 1;
    p = (char *)malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++)
    {
        if (isAlpha(S[i]))
        {
            if (isAlpha(S[count]))
            {
                p[i] = S[count];
            }
            else
            {
                i--;
            }

            count--;
        }
        else
        {
            p[i] = S[i];
        }
    }
    // p[length] = '\0';
    for (int i = 0; i < length; i++)
    {
        S[i] = p[i];
    }
    return S;
}

int main()
{
    char *s = "Test1ng-Leet=code-Q!";
    reverseOnlyLetters(s);
    return 0;
}
