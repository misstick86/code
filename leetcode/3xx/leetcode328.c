/*
@File    :   leetcode328.c
@Time    :   2020/01/19 21:48:01
@Author  :   xiaosongsong
@Desc    :   None

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
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

struct ListNode *oddEvenList(struct ListNode *head)
{
    int i = 1;
    struct ListNode *p, *q, *first, *last;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    first = p = head;
    last = q = head->next;
    head = head->next->next;
    while (head)
    {
        if (i % 2 == 0)
        {
            q->next = head;
            q = q->next;
        }
        else
        {
            p->next = head;
            p = p->next;
        }
        head = head->next;
        i++;
    }
    q->next = NULL;
    p->next = last;
    // while (first)
    // {
    //     printf("%d", first->val);
    //     first = first->next;
    // }

    return first;
}
int main()
{
    ListNode *head;
    head = create();
    oddEvenList(head);
    return 0;
}
