/*
@File    :   leetcode141.c
@Time    :   2020/02/12 11:40:22
@Author  :   xiaosongsong
@Desc    :   

给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。


*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

// 构造环形链表
ListNode *createList(int *p, int n, int pos)
{
    int i = 0;
    ListNode *new, *temp, *pointer, *root;
    temp = NULL;
    new = (ListNode *)malloc(sizeof(ListNode));
    new->val = p[i++];
    new->next = NULL;
    root = new;
    pointer = new;
    if (pos == 0)
    {
        temp = new;
    }
    while (i < n)
    {
        new = (ListNode *)malloc(sizeof(ListNode));
        new->val = p[i];
        new->next = NULL;
        pointer->next = new;
        pointer = new;
        if (i == pos)
        {
            temp = pointer;
        }
        i++;
    }
    pointer->next = temp;
    return root;
}

bool hasCycle(struct ListNode *head)
{
    struct ListNode *first, *last;
    first = head;
    last = head;
    // 双指针法
    if (head == NULL || head->next == NULL)
        return false;
    while (last && first->next && first->next->next)
    {
        last = last->next;
        first = first->next->next;
        if (last == first)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    bool flag;
    ListNode *root;
    int a[] = {3, 2, 0, -4, 5};
    root = createList(a, 5, -1);
    flag = hasCycle(root);
    return 0;
}
