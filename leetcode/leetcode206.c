/*
@File    :   leetcode206.c
@Time    :   2020/01/14 09:01:01
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
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *pre, *p, *temp;
    pre = NULL;
    if (head == NULL)
    {
        return head;
    }
    p = head;
    // 注 p永远不能等于p->next,因为，p->发生了改变， temp为p->next. 而temp->next就存储了整个链表的结构
    while (p)
    {
        temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
    }

    while (pre != NULL)
    {
        /* code */
        printf("%d", pre->val);
        pre = pre->next;
    }
    head = pre;
    // return pre;
}

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
int main()
{
    ListNode *head;
    head = create();
    reverseList(head);
    return 0;
}
