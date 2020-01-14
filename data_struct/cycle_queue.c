/*
@File    :   cycle_queue.c
@Time    :   2020/01/11 21:27:33
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#define MaxSize 10
typedef struct Node
{
    int data[MaxSize];
    int head;
    int tail;
} QueueNode;

void InitQueueNode(QueueNode *p)
{
    p->head = 0;
    p->tail = 0;
}

void QueueNodePush(QueueNode *p)
{
}
void QueueNodePop(QueueNode *p)
{
}

int main()
{

    return 0;
}
