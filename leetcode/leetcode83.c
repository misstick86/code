/*
@File    :   leetcode83.c
@Time    :   2020/01/12 21:27:06
@Author  :   xiaosongsong
@Desc    :   None

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
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
        int initdata[2] = {1, 1};
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

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *p, *temp;
    p = head;
    if (p == NULL)
    {
        return NULL;
    }
    while (p->next != NULL)
    {
        if (p->val == p->next->val)
        {
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else
        {
            p = p->next;
        }
    }
    while (head != NULL)
    {
        printf("%d\n", head->val);
        head = head->next;
    }

    return head;
}
int main()
{
    ListNode *head;
    head = create();
    deleteDuplicates(head);
    return 0;
}
