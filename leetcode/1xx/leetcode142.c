/*
@File    :   leetcode142.c
@Time    :   2020/03/09 19:45:45
@Author  :   xiaosongsong
@Desc    :   None
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。


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
    struct ListNode *head, *p, *new;
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
    p->next = head;
    return head;
}
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *first, *last, *p;
    last = head;
    first = head;
    if (head == NULL || head->next == NULL)
        return NULL;
    while (last && first && first->next)
    {
        last = last->next;
        first = first->next->next;
        if (last == first)
        {
            p = head;
            while (p != first)
            {
                first = last->next;
                while (first != last)
                {
                    if (first == p)
                        return first;
                    first = first->next;
                }
                p = p->next;
            }
            if (p == first)
                return first;
        }
    }
    return NULL;
}
int main()
{
    struct ListNode *head;
    int node[] = {1, 2};
    head = createList(node, 2);
    detectCycle(head);
    return 0;
}
