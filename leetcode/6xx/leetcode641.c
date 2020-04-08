/*
@File    :   leetcode641.c
@Time    :   2020/04/08 09:40:42
@Author  :   xiaosongsong
@Desc    :   None
设计实现双端队列。
你的实现需要支持以下操作：

MyCircularDeque(k)：构造函数,双端队列的大小为k。
insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
isEmpty()：检查双端队列是否为空。
isFull()：检查双端队列是否满了。
示例：

MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-circular-deque

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct
{
    int val[4];
    int head;
    int tail;
    int k;
} MyCircularDeque;

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque *obj)
{
    return obj->head == obj->tail;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque *obj)
{
    return (obj->tail + 1) % obj->k == obj->head;
}

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque *myCircularDequeCreate(int k)
{
    MyCircularDeque *new;
    new = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    new->head = new->tail = 0;
    new->k = k + 1;
    // new->val = (int *)malloc(sizeof(int) * (k + 1));
    return new;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque *obj, int value)
{
    if (!myCircularDequeIsFull(obj))
    {

        obj->val[obj->tail] = value;
        obj->tail = (obj->tail + 1) % obj->k;

        return true;
    }
    return false;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque *obj, int value)
{
    if (!myCircularDequeIsFull(obj))
    {
        obj->head = (obj->head - 1 + obj->k) % obj->k;
        obj->val[obj->head] = value;
        return true;
    }
    return false;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque *obj)
{
    if (!myCircularDequeIsEmpty(obj))
    {
        obj->tail = (obj->tail - 1 + obj->k) % obj->k;
        return true;
    }
    return false;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque *obj)
{
    if (!myCircularDequeIsEmpty(obj))
    {
        obj->head = (obj->head + 1) % obj->k;
        return true;
    }
    return false;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque *obj)
{
    if (!myCircularDequeIsEmpty(obj))
        return obj->val[(obj->tail - 1 + obj->k) % obj->k];
    return -1;
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque *obj)
{
    if (!myCircularDequeIsEmpty(obj))
        return obj->val[obj->head % obj->k];
    return -1;
}

void myCircularDequeFree(MyCircularDeque *obj)
{
    // free(obj->val);
    // obj->val = NULL;
    free(obj);
    obj = NULL;
}
int main()
{
    MyCircularDeque *queue = myCircularDequeCreate(731);
    printf("%d,", myCircularDequeInsertFront(queue, 344));
    printf("%d,", myCircularDequeGetFront(queue));
    printf("%d,", myCircularDequeGetRear(queue));
    printf("%d,", myCircularDequeGetRear(queue));
    printf("%d,", myCircularDequeInsertFront(queue, 433));
    printf("%d,", myCircularDequeGetRear(queue));
    printf("%d,", myCircularDequeIsEmpty(queue));
    printf("%d,", myCircularDequeIsEmpty(queue));
    printf("%d,", myCircularDequeDeleteFront(queue));
    printf("%d,", myCircularDequeInsertLast(queue, 504));
    printf("%d,", myCircularDequeDeleteFront(queue));
    printf("%d,", myCircularDequeGetFront(queue));
    return 0;
}
