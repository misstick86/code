/*
@File    :   leetcode147.c
@Time    :   2020/03/08 20:46:50
@Author  :   xiaosongsong
@Desc    :   None
对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5

*/

#include <stdio.h>
#include <malloc.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *createList(int *node, int n)
{
    struct ListNode *head, *new, *p;
    new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = node[0];
    new->next = NULL;
    p = new;
    head = new;

    for (int i = 1; i < n; i++)
    {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = node[i];
        new->next = NULL;
        p->next = new;
        p = new;
    }
    return head;
}
struct ListNode *insertionSortList(struct ListNode *head)
{
    struct ListNode *newhead = head, *p, *q;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    head = head->next;
    newhead->next = NULL;
    while (head)
    {
        p = newhead;
        if (p->val >= head->val)
        {
            newhead = head;
            head = head->next;
            newhead->next = p;
        }
        if (p && head && p->val < head->val)
        {
            while (p && p->val < head->val)
            {
                q = p;
                p = p->next;
            }
            if (p == NULL)
            {
                p = head;
                head = head->next;
                p->next = NULL;
                q->next = p;
            }
            else
            {
                q->next = head;
                q = q->next;
                head = head->next;
                q->next = p;
            }
        }
    }
    return newhead;
}
int main()
{
    struct ListNode *head, *new;
    int node[] = {4, 1, 2, 3, -1, 2, 2, 2, -1, -2, 0};
    head = createList(node, 11);
    new = insertionSortList(head);
    return 0;
}
