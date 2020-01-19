/*
@File    :   leetcode203.c
@Time    :   2020/01/13 20:59:17
@Author  :   xiaosongsong
@Desc    :   None

删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
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
        int initdata[3] = {2, 2, 1};
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
struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *p;
    p = head;
    //  删除前几个节点中相等的
    while (head == p && p != NULL)
    {
        if (p->val != val)
        {
            break;
        }
        p = p->next;
        head = p;
    }
    // printf("current is:%d", head->val);
    while (p != NULL)
    {

        if (p->next && p->next->val == val)
        {
            p->next = p->next->next;
        }
        else
        {
            p = p->next;
        }
    }

    // 输出
    while (head != NULL)
    {
        printf("current is:%d", head->val);
        head = head->next;
    }

    return head;
}
int main()
{
    ListNode *head;
    head = create();
    removeElements(head, 2);
    return 0;
}
