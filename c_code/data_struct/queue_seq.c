/*
@File    :   queue_seq.c
@Time    :   2020/01/11 10:56:54
@Author  :   xiaosongsong
@Desc    :   队列练习
*/

#include <stdio.h>
#define MaxSize 10

typedef struct Node
{
    int data[MaxSize];
    int head, tail;
} Node;

typedef Node QueueNode;

// 初始化队列
void InitQueue(QueueNode *p)
{
    p->head = 0;
    p->tail = 0;
}

// 入队
void QueuePush(QueueNode *p, int x)
{
    if (p->tail < MaxSize)
    {
        p->data[p->tail] = x;
        p->tail++;
    }
    else
    {
        printf("队满，不能入队！\n");
    }
}

// 出队
void QueuePop(QueueNode *p)
{
    p->head++;
}

// 展示队列
void ShowQueue(QueueNode *p)
{
    int j;
    j = p->head;
    while (j != p->tail)
    {
        /* code */
        printf("%d ", p->data[j]);
        j++;
    }
    printf("\n");
}

#include <stdio.h>

int main()
{
    QueueNode p;
    InitQueue(&p);

    for (int i = 1; i <= 10; i++)
    {
        QueuePush(&p, i);
    }
    ShowQueue(&p);
    QueuePop(&p);
    ShowQueue(&p);
    return 0;
}
