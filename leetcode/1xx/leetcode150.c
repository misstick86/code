/*
@File    :   leetcode150.c
@Time    :   2020/02/12 17:29:15
@Author  :   xiaosongsong
@Desc    :   None

根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct NodeStack
{
    char val;
    struct NodeStack *next;
} NodeStack;

NodeStack *InitStack(NodeStack *p)
{
    p = NULL;
    return p;
}
bool Empty(NodeStack *p)
{
    return p == NULL;
}
NodeStack *Push(NodeStack *st, char x)
{
    NodeStack *new;
    new = (NodeStack *)malloc(sizeof(NodeStack));
    new->val = x;
    new->next = NULL;
    if (Empty(st))
    {
        return new;
    }
    else
    {
        new->next = st;
        st = new;
        return st;
    }
}

NodeStack *PopValue(NodeStack *p, char **x)
{
    NodeStack *temp;
    temp = p;
    *x = p->val;
    p = p->next;
    free(temp);
    return p;
}
int getValue(int x1, int x2, char flag)
{
    switch (flag)
    {
    case '+':
        return x1 + x2;
    case '-':
        return x1 - x2;
    case '*':
        return x1 * x2;
    case '/':
        return x1 / x2;
        ;
    default:
        break;
    }
}
int evalRPN(char *tokens, int tokensSize)
{
    int x1_, x2_;
    char *x1, *x2;
    int result;
    NodeStack *st;
    st = InitStack(st);
    for (int i = 0; i < tokensSize; i++)
    {
        while (tokens[i] != '+' && tokens[i] != '-' && tokens[i] != '*' && tokens[i] != '/')
        {
            st = Push(st, tokens[i++]);
        }
        st = PopValue(st, &*x1);
        st = PopValue(st, &*x2);
        x1_ = atoi(x1);
        x2_ = atoi(x2);
        result = getValue(x1, x2, tokens[i]);
        st = Push(st, result + '0');
    }
    return result;
}
int main()
{
    char a[] = {'1', '6', '9', '3', '+', '1', '*', '/', '*', '7', '+', '5', '+'};
    printf("%d", evalRPN(a, 5));
    return 0;
}
