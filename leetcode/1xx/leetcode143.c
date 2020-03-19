/*
@File    :   leetcode143.c
@Time    :   2020/01/22 19:03:36
@Author  :   xiaosongsong
@Desc    :   None

给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

*/

#include <stdio.h>
#include <stdlib.h>
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
        int data = 1;
        Head->val = data;
        Head->next = NULL;
        Pointer = Head;
        int initdata[6] = {2, 3, 4, 5, 6, 7};
        for (int i = 0; i < 6; i++)
        {
            New = (ListNode *)malloc(sizeof(struct ListNode));
            New->val = initdata[i];
            Pointer->next = New;
            Pointer = New;
        }
    }
    return Head;
}

void reorderList(struct ListNode *head)
{
    // 1. 获取链表的中间节点
    struct ListNode *first, *last, *p;
    p = head;
    last = p;
    first = p;
    while (first && first->next)
    {
        first = first->next->next;
        last = last->next;
    }
    p = head;

    // 2.反转last链表

    struct ListNode *newhead, *temp, *pre = NULL;

    while (last)
    {
        temp = last;
        last = last->next;
        temp->next = pre;
        pre = temp;
    }

    // 3.链接前后链表
    newhead = p;
    int i = 0;
    while (p && pre && p != pre)
    {
        temp = p->next;
        newhead->next = p;
        newhead->next->next = pre;
        newhead = newhead->next;
        pre = pre->next;
        p = temp;
        if (i++)
        {
            newhead = newhead->next;
        }
    }
}
int main()
{
    struct ListNode *head;
    head = create();
    reorderList(head);
    return 0;
}
