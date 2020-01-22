/*
@File    :   leetcode445.c
@Time    :   2020/01/20 20:55:15
@Author  :   xiaosongsong
@Desc    :   None

给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。

 

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶:

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例:

输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 8 -> 0 -> 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *create()
{
    ListNode *Head, *Pointer, *New;
    Head = (ListNode *)malloc(sizeof(struct ListNode));
    if (Head == NULL)
    {
        printf("内存分配失败");
    }
    else
    {
        int data = 7;
        Head->val = data;
        Head->next = NULL;
        Pointer = Head;
        int initdata[3] = {2, 4, 3};
        for (int i = 0; i < 3; i++)
        {
            New = (ListNode *)malloc(sizeof(struct ListNode));
            New->val = initdata[i];
            Pointer->next = New;
            Pointer = New;
        }
    }
    return Head;
}

struct ListNode *NewList(struct ListNode *p, int x)
{
    // printf("x is %d", x);
    struct ListNode *New;
    New = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (p == NULL)
    {
        New->val = x;
    }
    else
    {
        New->val = x;
        p->next = New;
        p = New;
    }

    return p;
}

ListNode *create2()
{
    ListNode *Head, *Pointer, *New;
    Head = (ListNode *)malloc(sizeof(struct ListNode));
    if (Head == NULL)
    {
        printf("内存分配失败");
    }
    else
    {
        int data = 5;
        Head->val = data;
        Head->next = NULL;
        Pointer = Head;
        int initdata[2] = {6, 4};
        for (int i = 0; i < 2; i++)
        {
            New = (ListNode *)malloc(sizeof(struct ListNode));
            New->val = initdata[i];
            Pointer->next = New;
            Pointer = New;
        }
    }
    return Head;
}

struct ListNode *InitStack(struct ListNode *p)
{
    p = NULL;
    return p;
}

struct ListNode *PushStack(struct ListNode *p, int x)
{
    struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
    t->val = x;
    if (p == NULL)
    {
        p = t;
        p->next = NULL;
    }
    else
    {
        t->next = p;
        p = t;
    }
    return p;
}
bool isEmptyStack(struct ListNode *s)
{
    return s == NULL;
}

struct ListNode *PopStack(struct ListNode *p, int *x)
{
    struct ListNode *t;

    if (isEmptyStack(p))
    {
        // return NULL;
        *x = 0;
        return NULL;
    }
    else
    {
        *x = p->val;
        t = p;
        p = p->next;
        free(t);
    }
    return p;
}

void Show(ListNode *p)
{
    while (p != NULL)
    {
        printf("%d,", p->val);
        p = p->next;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    // 初始化入栈
    int x1, x2, i = 0;
    struct ListNode *l1Stack, *l2Stack, *rStack;
    l1Stack = InitStack(l1Stack);
    l2Stack = InitStack(l2Stack);
    rStack = InitStack(rStack);
    while (l1)
    {
        l1Stack = PushStack(l1Stack, l1->val);
        l1 = l1->next;
    }
    while (l2)
    {
        l2Stack = PushStack(l2Stack, l2->val);
        l2 = l2->next;
    }
    while (!isEmptyStack(l1Stack) || !isEmptyStack(l2Stack))
    {
        l1Stack = PopStack(l1Stack, &x1);
        l2Stack = PopStack(l2Stack, &x2);
        rStack = PushStack(rStack, (x1 + x2 + i) % 10);
        // printf("i is: %d\n", (x1 + x2 + i) % 10);
        i = (x1 + x2 + i) / 10;
        // printf("x1 is :%d,", x1);
        // printf("x2 is :%d,", x2);
        // printf("i is: %d\n", i);
    }
    if (i)
    {
        rStack = PushStack(rStack, i);
    }
}

int main()
{
    ListNode *head1, *head2;
    head1 = create();
    head2 = create2();
    addTwoNumbers(head1, head2);
    return 0;
}
