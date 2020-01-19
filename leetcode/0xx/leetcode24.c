/*
@File    :   leetcode24.c
@Time    :   2020/01/18 17:34:17
@Author  :   xiaosongsong
@Desc    :   None
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
        int initdata[3] = {2, 3, 4};
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

struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode *p, *newHead;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        p = head->next->next;
        newHead = head->next;
        newHead->next = head;
        head->next = swapPairs(p);
        return newHead;
    }
}
int main()
{
    ListNode *head, *result;
    head = create();
    result = swapPairs(head);
    return 0;
}
