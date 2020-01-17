/*
@File    :   leetcode19.c
@Time    :   2020/01/14 20:52:31
@Author  :   xiaosongsong
@Desc    :   None

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

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
        int initdata[4] = {2, 3, 4, 5};
        for (int i = 0; i < 4; i++)
        {
            New = (ListNode *)malloc(sizeof(struct ListNode));
            New->val = initdata[i];
            Pointer->next = New;
            Pointer = New;
        }
    }
    return Head;
}

// 快慢指针
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *first, *last;
    struct ListNode *temp;
    first = last = head;
    // 只有单个节点
    if (head->next == NULL)
    {
        return NULL;
    }
    while (n > 0)
    {
        last = last->next;
        printf("%d", n);
        n--;
    }
    // last 和first 已将链表分割为两层
    //  判断是否删除第一个
    if (last == NULL)
    {
        head = head->next;
        return head;
    }
    printf("first is %d, last is %d\n", first->val, last->val);
    while (last->next != NULL)
    {
        last = last->next;
        first = first->next;
    }
    first->next = first->next->next;
    while (head != NULL)
    {
        printf("head is %d,", head->val);
        head = head->next;
    }
    return head;
}
int main()
{
    ListNode *head;
    head = create();
    removeNthFromEnd(head, 2);
    return 0;
}
