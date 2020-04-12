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

void QueueNodePush(QueueNode *p, int x)
{
    if ((p->tail + 1) % MaxSize != p->head)
    {
        p->data[p->tail] = x;
        p->tail = (p->tail + 1) % MaxSize;
    }
    else
    {
        printf("队满\n");
    }
}

void QueueNodePop(QueueNode *p)
{
    // 判断空队
    if (p->head == p->tail)
        return;
    p->head = (p->head + 1) % MaxSize;
}

void ShowQueueNode(QueueNode *p)
{
    printf("head is : %d\n", p->head);
    while (p->head != p->tail)
    {
        printf("%d,", p->data[p->head]);
        p->head = (p->head + 1) % MaxSize;
    }
}

int main()
{
    QueueNode p;
    InitQueueNode(&p);
    // printf("%d,%d", p.head, p.tail);
    for (int i = 1; i < 10; i++)
        QueueNodePush(&p, i);
    // ShowQueueNode(&p);
    // 出队
    QueueNodePop(&p);
    QueueNodePop(&p);
    QueueNodePop(&p);
    QueueNodePush(&p, 20);
    QueueNodePush(&p, 21);
    ShowQueueNode(&p);
    ShowQueueNode(&p);
    return 0;
}
