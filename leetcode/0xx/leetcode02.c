/*
@File    :   leetcode02.c
@Time    :   2020/02/07 19:31:15
@Author  :   xiaosongsong
@Desc    :   None
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode *InitLink(int *l, int n)
{
    int i = 0;
    struct ListNode *p, *new, *head;
    p = NULL;
    head = p;
    while (i < n)
    {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = l[i];
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

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *result, *p, *new;
    int i = 0;
    result = p;
    p = NULL;
    while (l1 != NULL || l2 != NULL)
    {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (l1 == NULL)
        {
            new->val = (l2->val + i) % 10;
            i = (l2->val + i) / 10;
            l2 = l2->next;
        }
        else if (l2 == NULL)
        {
            new->val = (l1->val + i) % 10;
            i = (l1->val + i) / 10;
            l1 = l1->next;
        }
        else
        {
            new->val = (l1->val + l2->val + i) % 10;
            i = (l1->val + l2->val + i) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        new->next = NULL;
        if (p == NULL)
        {
            p = new;
            result = p;
        }
        else
        {
            p->next = new;
            p = new;
        }
    }
    if (i)
    {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = i;
        new->next = NULL;
        p->next = new;
    }
    return result;
}
int main()
{
    struct ListNode *l1, *l2;
    int a[] = {2, 4, 3};
    int b[] = {8, 6, 7};
    l1 = InitLink(a, 3);
    l2 = InitLink(b, 3);
    addTwoNumbers(l1, l2);
    return 0;
}
