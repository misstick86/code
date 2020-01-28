/*
@File    :   leetcode225.c
@Time    :   2020/01/28 10:28:54
@Author  :   xiaosongsong
@Desc    :   None
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 1024
typedef struct
{
    int data[MaxSize];
    int head;
    int tail;

} MyStack;

/** Initialize your data structure here. */

MyStack *myStackCreate()
{
    MyStack *p;
    p = (MyStack *)malloc(sizeof(MyStack));
    p->head = 0;
    p->tail = 0;
    return p;
}

/** Push element x onto stack. */
void myStackPush(MyStack *obj, int x)
{
    if (obj->tail < MaxSize)
    {
        obj->data[obj->tail] = x;
        obj->tail++;
    }
    else
    {
        printf("满！");
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack *obj)
{
    int x;
    if (obj->head != obj->tail)
    {
        x = obj->data[obj->tail - 1];
        obj->tail--;
    }
    return x;
}

/** Get the top element. */
int myStackTop(MyStack *obj)
{
    return obj->data[obj->tail - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack *obj)
{
    return obj->head == obj->tail;
}

void myStackFree(MyStack *obj)
{
    free(obj);
    obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
int main()
{
    MyStack *obj = myStackCreate();
    return 0;
}
