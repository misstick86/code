/*
@File    :   leetcode844.c
@Time    :   2020/02/24 20:01:33
@Author  :   xiaosongsong
@Desc    :   None

给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

 

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
示例 3：

输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。
示例 4：

输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。
 

提示：

1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct StackNode
{
    char val;
    struct StackNode *next;
} StackNode;

bool Empty(StackNode *p)
{
    return p == NULL;
}

StackNode *InitStack(StackNode *p)
{
    p = NULL;
    return p;
}

StackNode *Push(StackNode *p, char x)
{
    StackNode *new;
    new = (StackNode *)malloc(sizeof(StackNode));
    new->val = x;
    if (p == NULL)
    {
        new->next = NULL;
        return new;
    }
    else
    {
        new->next = p;
        p = new;
        return p;
    }
}

StackNode *Pop(StackNode *p)
{
    if (!Empty(p))
    {
        StackNode *q;
        q = p;
        p = p->next;
        free(q);
        q = NULL;
    }
    return p;
}

void getTopValue(StackNode *p, char *x)
{
    if (!Empty(p))
        *x = p->val;
}
bool backspaceCompare(char *S, char *T)
{
    char s, t;
    StackNode *st_s, *st_t;
    st_s = InitStack(st_s);
    st_t = InitStack(st_t);
    while (*S != '\0')
    {
        if (*S != '#')
            st_s = Push(st_s, *S);
        else
            st_s = Pop(st_s);
        S++;
    }
    while (*T != '\0')
    {
        if (*T != '#')
            st_t = Push(st_t, *T);
        else
            st_t = Pop(st_t);
        T++;
    }
    while (st_t != NULL && st_s != NULL)
    {
        getTopValue(st_s, &s);
        getTopValue(st_t, &t);
        if (s != t)
            return false;
        st_s = Pop(st_s);
        st_t = Pop(st_t);
    }
    return st_s == st_t;
}
int main()
{
    char *S = "a##c";
    char *T = "#a#c";
    printf("%d", backspaceCompare(S, T));
    return 0;
}
