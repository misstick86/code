/*
@File    :   leetcode946.c
@Time    :   2020/02/11 11:05:31
@Author  :   xiaosongsong
@Desc    :   None

给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

 

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
 

提示：

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed 是 popped 的排列。

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct NodeStack
{
    int val;
    struct NodeStack *next;
} NodeStack;

NodeStack *Initstack()
{
    NodeStack *new;
    new = NULL;
    return new;
}
bool Empty(NodeStack *p)
{
    return p == NULL;
}

NodeStack *Push(NodeStack *p, int x)
{
    NodeStack *new;
    new = (NodeStack *)malloc(sizeof(NodeStack));
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
NodeStack *Pop(NodeStack *p)
{
    NodeStack *temp;
    temp = p;
    p = p->next;
    free(temp);
    temp = NULL;
    return p;
}

int getTopValue(NodeStack *p)
{
    int x;
    x = p->val;

    return x;
}

bool validateStackSequences(int *pushed, int pushedSize, int *popped, int poppedSize)
{
    NodeStack *st;
    st = Initstack();
    int i = 0, value;
    if (pushedSize == 0 && poppedSize == 0)
    {
        return true;
    }
    if (pushedSize > 0)
    {
        st = Push(st, pushed[i++]);
        value = getTopValue(st);
        if (i == pushedSize)
            return *pushed == *popped;
        while (i < pushedSize)
        {
            while (value != *popped)
            {
                if (i == pushedSize)
                {
                    break;
                }
                st = Push(st, pushed[i++]);
                value = getTopValue(st);
            }
            while (value == *popped)
            {
                st = Pop(st);
                popped++;
                if (Empty(st))
                {
                    break;
                }

                value = getTopValue(st);
            }
        }

        return Empty(st);
    }
    else
    {
        return false;
    }
}

int main()
{
    bool flag;
    int pushed[] = {1};
    int popped[] = {1};
    flag = validateStackSequences(pushed, 1, popped, 1);
    printf("%d", flag);
    return 0;
}
