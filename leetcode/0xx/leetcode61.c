/*
@File    :   leetcode61.c
@Time    :   2020/03/09 09:02:54
@Author  :   xiaosongsong
@Desc    :   None
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL


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
    head = new;
    p = new;
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
struct ListNode *rotateRight(struct ListNode *head, int k)
{
    int n = 0, count;
    struct ListNode *p = head;
    if (head == NULL || k == 0)
        return head;
    while (p->next)
    {
        n++;
        p = p->next;
    }
    p->next = head;
    k = (k % (n + 1));
    count = n + 1 - k;

    while (count--)
    {
        p = head;
        head = head->next;
    }
    p->next = NULL;
    return head;
}
int main()
{
    struct ListNode *head, *p;
    int node[] = {1, 2, 3, 4, 5};
    head = createList(node, 5);
    p = rotateRight(head, 1);
    return 0;
}
