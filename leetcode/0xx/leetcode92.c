/*
@File    :   leetcode92.c
@Time    :   2020/02/07 11:53:23
@Author  :   xiaosongsong
@Desc    :   None

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/

#include <stdio.h>
#include <malloc.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;

} ListNode;

struct ListNode *createList()
{
    ListNode *new, *p, *head;

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 1;
    head = (ListNode *)malloc(sizeof(ListNode));
    head->val = a[0];
    p = head;
    while (i < 10)
    {

        new = (ListNode *)malloc(sizeof(ListNode));
        new->val = a[i];
        p->next = new;
        p = new;
        i++;
    }
    return head;
}

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
    struct ListNode *p, *pre = NULL;
    struct ListNode *prenode, *temp;
    prenode = NULL;
    int i = 1;
    p = head;
    while (m < n)
    {

        if (i == m)
        {
            // 进行链表反转
            while (m <= n)
            {
                temp = p->next;
                p->next = prenode;
                prenode = p;
                p = temp;
                m++;
            }
            break;
        }
        pre = p;
        i++;
        p = p->next;
    }
    if (m > n)
    {
        if (pre == NULL)
        {
            pre = prenode;
            head = pre;
        }
        else
        {
            pre->next = prenode;
        }

        while (pre != NULL)
        {
            if (pre->next == NULL)
            {
                pre->next = p;
                break;
            }
            pre = pre->next;
        }
    }

    return head;
}
int main()
{
    ListNode *head;
    head = createList();
    reverseBetween(head, 1, 2);
    printf("av");
    return 0;
}
