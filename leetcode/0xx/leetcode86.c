/*
@File    :   leetcode86.c
@Time    :   2020/01/20 08:37:37
@Author  :   xiaosongsong
@Desc    :   None

给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

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
        int initdata[5] = {4, 3, 2, 5, 2};
        for (int i = 0; i < 5; i++)
        {
            New = (ListNode *)malloc(sizeof(struct ListNode));
            New->val = initdata[i];
            Pointer->next = New;
            Pointer = New;
        }
    }
    return Head;
}
struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *p, *q, *morelist, *lesslist;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    q = (struct ListNode *)malloc(sizeof(struct ListNode));
    morelist = p;
    lesslist = q;
    while (head)
    {
        if (head->val >= x)
        {
            p->next = head;
            p = p->next;
        }

        else
        {
            q->next = head;
            q = q->next;
        }
        head = head->next;
    }
    p->next = NULL;
    q->next = morelist->next;
    // printf("p is :%d\n", p->val);
    // first->next = q;

    // while (lesslist)
    // {
    //     printf("%d", lesslist->val);
    //     lesslist = lesslist->next;
    // }

    return lesslist->next;
}
int main()
{
    ListNode *head;
    head = create();
    partition(head, 3);
    return 0;
}
