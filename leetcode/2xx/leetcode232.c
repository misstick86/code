/*
@File    :   leetcode232.c
@Time    :   2020/01/28 21:10:24
@Author  :   xiaosongsong
@Desc    :   None
使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
示例:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
说明:

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int head;
    int tail;
} MyQueue;

/** Initialize your data structure here. */

MyQueue *myQueueCreate()
{
    MyQueue *p;
    p = (MyQueue *)malloc(sizeof(MyQueue));
    p->head = 0;
    p->tail = 0;
    return p;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x)
{
    if (obj->tail < MaxSize)
    {
        obj->data[obj->tail] = x;
        obj->tail++;
    }
    else
    {
        printf("栈满！");
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj)
{
    int x;
    if (obj->head != obj->tail)
    {
        x = obj->data[obj->head];
        obj->head++;
    }
    return x;
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj)
{
    return obj->data[obj->head];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *obj)
{
    return obj->head == obj->tail;
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
    obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
int main()
{
    MyQueue *obj = myQueueCreate();
    return 0;
}
