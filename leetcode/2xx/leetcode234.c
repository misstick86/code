/*
@File    :   leetcode234.c
@Time    :   2020/02/25 17:23:11
@Author  :   xiaosongsong
@Desc    :   None

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *createList(int *node, int n)
{
    struct ListNode *head, *new, *pointer;
    new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = node[0];
    new->next = NULL;
    head = new;
    pointer = new;
    for (int i = 1; i < n; i++)
    {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = node[i];
        new->next = NULL;
        pointer->next = new;
        pointer = new;
    }
    return head;
}

bool isPalindrome(struct ListNode *head)
{
    int flag = 0;
    struct ListNode *first, *last, *p, *pre = NULL;
    first = head;
    last = head;
    if (head == NULL || head->next == NULL)
        return true;
    // 找到中间节点
    while (first && first->next)
    {
        first = first->next->next;
        last = last->next;
    }
    if (first)
        flag = 1;
    first = last;
    // 反转链接
    last = head;
    while (last != first)
    {
        p = last;
        last = p->next;
        p->next = pre;
        pre = p;
    }
    if (flag)
        first = first->next;
    while (pre && first)
    {
        if (pre->val != first->val)
            return false;
        pre = pre->next;
        first = first->next;
    }
    if (pre != NULL || first != NULL)
        return false;

    return true;
}
int main()
{
    struct ListNode *head;
    int node[] = {1, 2, 3, 3, 3, 2, 1};
    head = createList(node, 7);
    printf("%d", isPalindrome(head));
    return 0;
}
