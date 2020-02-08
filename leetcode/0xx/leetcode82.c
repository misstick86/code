/*
@File    :   leetcode82.c
@Time    :   2020/02/07 23:33:46
@Author  :   xiaosongsong
@Desc    :   None
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3


*/

#include <stdio.h>
#include <malloc.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;
ListNode *createList(int *val, int count)
{
    int i = 0;
    ListNode *new, *head, *p;
    p = NULL;
    head = p;
    while (i < count)
    {
        new = (ListNode *)malloc(sizeof(ListNode));
        new->val = val[i];
        if (p == NULL)
        {
            p = new;
            head = p;
        }
        else
        {
            p->next = new;
            p = new;
        }
        i++;
    }
    return head;
}

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *p, *pre;
    int flag = 0;
    pre = head;
    p = pre;
    if (head == NULL || head->next == NULL)
        return head;
    while (head)
    {
        while (head->next && head->val == head->next->val)
        {
            head->next = head->next->next;
            flag = 1;
        }
        if (flag)
        {
            flag = 0;
            if (pre->val == head->val)
            {
                pre = head->next;
                p = pre;
            }
            else
            {
                pre->next = head->next;
            }
        }
        else
        {
            pre = head;
        }

        head = head->next;
    }
    return p;
}
int main()
{
    int a[] = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    ListNode *head = createList(a, 9);
    deleteDuplicates(head);
    return 0;
}
