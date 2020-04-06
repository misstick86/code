/*
@File    :   leetcode622.c
@Time    :   2020/04/06 20:42:30
@Author  :   xiaosongsong
@Desc    :   None
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
 

示例：

MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为 3

circularQueue.enQueue(1);  // 返回 true

circularQueue.enQueue(2);  // 返回 true

circularQueue.enQueue(3);  // 返回 true

circularQueue.enQueue(4);  // 返回 false，队列已满

circularQueue.Rear();  // 返回 3

circularQueue.isFull();  // 返回 true

circularQueue.deQueue();  // 返回 true

circularQueue.enQueue(4);  // 返回 true

circularQueue.Rear();  // 返回 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-circular-queue

*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
typedef struct
{
    int *nums;
    int k;
    int head;
    int tail;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *queue;
    queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    queue->k = k + 1;
    queue->head = queue->tail = 0;
    queue->nums = (int *)malloc(sizeof(int) * (k + 1));
    return queue;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    return obj->head == obj->tail;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    return (obj->head + 1) % obj->k == obj->tail;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if (!myCircularQueueIsFull(obj))
    {
        obj->nums[obj->head] = value;
        obj->head = (obj->head + 1) % obj->k;
        return true;
    }
    return false;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (!myCircularQueueIsEmpty(obj))
    {
        obj->tail = (obj->tail + 1) % obj->k;
        return true;
    }
    return false;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue *obj)
{
    if (!myCircularQueueIsEmpty(obj))
        return obj->nums[obj->tail];
    return -1;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue *obj)
{
    if (!myCircularQueueIsEmpty(obj))
        return obj->nums[(obj->head + obj->k - 1) % obj->k];
    return -1;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->nums);
    obj->nums = NULL;
    free(obj);
    obj = NULL;
}
int main()
{
    MyCircularQueue *queue;
    queue = myCircularQueueCreate(3);
    printf("%d,", myCircularQueueEnQueue(queue, 1));
    printf("%d,", myCircularQueueEnQueue(queue, 2));
    printf("%d,", myCircularQueueEnQueue(queue, 3));
    printf("%d,", myCircularQueueEnQueue(queue, 4));
    // printf("%d,", myCircularQueueRear(queue));
    // printf("%d,", myCircularQueueIsFull(queue));
    // printf("%d,", myCircularQueueDeQueue(queue));
    // printf("%d,", myCircularQueueEnQueue(queue, 4));
    // printf("%d,", myCircularQueueRear(queue));
    printf("%d,", myCircularQueueFront(queue));
    return 0;
}
