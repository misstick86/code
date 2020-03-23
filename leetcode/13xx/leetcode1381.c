/*
@File    :   leetcode1381.c
@Time    :   2020/03/23 08:23:32
@Author  :   xiaosongsong
@Desc    :   None
请你设计一个支持下述操作的栈。

实现自定义栈类 CustomStack ：

CustomStack(int maxSize)：用 maxSize 初始化对象，maxSize 是栈中最多能容纳的元素数量，栈在增长到 maxSize 之后则不支持 push 操作。
void push(int x)：如果栈还未增长到 maxSize ，就将 x 添加到栈顶。
int pop()：返回栈顶的值，或栈为空时返回 -1 。
void inc(int k, int val)：栈底的 k 个元素的值都增加 val 。如果栈中元素总数小于 k ，则栈中的所有元素都增加 val 。
 

示例：

输入：
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
输出：
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
解释：
CustomStack customStack = new CustomStack(3); // 栈是空的 []
customStack.push(1);                          // 栈变为 [1]
customStack.push(2);                          // 栈变为 [1, 2]
customStack.pop();                            // 返回 2 --> 返回栈顶值 2，栈变为 [1]
customStack.push(2);                          // 栈变为 [1, 2]
customStack.push(3);                          // 栈变为 [1, 2, 3]
customStack.push(4);                          // 栈仍然是 [1, 2, 3]，不能添加其他元素使栈大小变为 4
customStack.increment(5, 100);                // 栈变为 [101, 102, 103]
customStack.increment(2, 100);                // 栈变为 [201, 202, 103]
customStack.pop();                            // 返回 103 --> 返回栈顶值 103，栈变为 [201, 202]
customStack.pop();                            // 返回 202 --> 返回栈顶值 202，栈变为 [201]
customStack.pop();                            // 返回 201 --> 返回栈顶值 201，栈变为 []
customStack.pop();                            // 返回 -1 --> 栈为空，返回 -1


*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct
{
    int *val;
    int top;
    int maxSize;
} CustomStack;

bool Full(CustomStack *st)
{
    return st->top == st->maxSize;
}

bool Empty(CustomStack *st)
{
    return st->top == 0;
}

CustomStack *customStackCreate(int maxSize)
{
    CustomStack *st;
    st = (CustomStack *)malloc(sizeof(CustomStack));
    st->val = (int *)malloc(sizeof(int) * maxSize);
    st->maxSize = maxSize;
    st->top = 0;
    return st;
}

void customStackPush(CustomStack *obj, int x)
{
    if (!Full(obj))
        obj->val[obj->top++] = x;
}

int customStackPop(CustomStack *obj)
{
    if (!Empty(obj))
        return obj->val[--obj->top];
    return -1;
}

void customStackIncrement(CustomStack *obj, int k, int val)
{
    if (obj->top < k)
    {
        for (int i = 0; i < obj->top; i++)
        {
            obj->val[i] += val;
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            obj->val[i] += val;
        }
    }
}

void customStackFree(CustomStack *obj)
{
    free(obj->val);
    obj->val = NULL;
    free(obj);
    obj = NULL;
}
int main()
{
    CustomStack *st;
    st = customStackCreate(3);
    customStackPush(st, 1);
    customStackPush(st, 2);
    printf("%d,", customStackPop(st));
    customStackPush(st, 2);
    customStackPush(st, 3);
    customStackPush(st, 4);
    customStackIncrement(st, 5, 100);
    customStackIncrement(st, 2, 100);
    printf("%d,", customStackPop(st));
    printf("%d,", customStackPop(st));
    printf("%d,", customStackPop(st));
    printf("%d,", customStackPop(st));
    // customStackPush(st, 2);
    return 0;
}
