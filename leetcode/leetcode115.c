/*
@File    :   leetcode115.c
@Time    :   2020/01/08 20:35:15
@Author  :   xiaosongsong
@Desc    :

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/

#include <stdio.h>
#include <stdlib.h>

#define StackMaxSize 1024

typedef struct MinStack
{
    int data[StackMaxSize];
    int top;

} MinStack;

/** initialize your data structure here. */

MinStack *minStackCreate()
{
    MinStack *ss;
    ss = (MinStack *)malloc(sizeof(MinStack));
    ss->top = 0;
    return ss;
}

void minStackPush(MinStack *obj, int x)
{
    if (obj->top < StackMaxSize)
    {
        obj->data[obj->top] = x;
        obj->top++;
    }
}

void minStackPop(MinStack *obj)
{

    obj->top = obj->top - 1;
}

int minStackTop(MinStack *obj)
{
    return obj->data[obj->top - 1];
}

int minStackGetMin(MinStack *obj)
{
    int minValue, tempTop;

    minValue = obj->data[obj->top - 1];
    tempTop = obj->top;
    while (obj->top != 0)
    {
        /* code */
        obj->top--;
        if (obj->data[obj->top] < minValue)
        {
            minValue = obj->data[obj->top];
        }
    }
    obj->top = tempTop;
    return minValue;
}

void minStackFree(MinStack *obj)
{
    free(obj);
}

int main(int argc, char const *argv[])
{
    /* code */
    MinStack *obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    printf("current: %d", obj->top);
    printf("top is:%d\n", minStackTop(obj));
    printf("min is:%d\n", minStackGetMin(obj));
    minStackPop(obj);
    printf("current: %d", obj->top);
    printf("top is:%d\n", minStackTop(obj));
    printf("min is:%d\n", minStackGetMin(obj));
    return 0;
}
