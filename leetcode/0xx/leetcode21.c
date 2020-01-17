/*
@File    :   leetcode21.c
@Time    :   2020/01/6 20:36:56
@Author  :   xiaosongsong
@Desc    :

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *result, *new;
    result = (struct ListNode *)malloc(sizeof(struct ListNode));
    new = result;
    if (l1 == NULL && l2 == NULL)
        return NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    while (l1 != NULL && l2 != NULL)
    {
        /* code */
        if (l1->val < l2->val)
        {

            result->next = l1;
            l1 = l1->next;
        }
        else
        {
            result->next = l2;
            l2 = l2->next;
        }

        result = result->next;
    }
    // 当两个不相等，或两个长度相等但是最后一个元素相同
    result->next = l1 ? l1 : l2;
    new = new->next;
    return new;
}

int main(int argc, char const *argv[])
{
    /* code */
    struct ListNode *p1, *p2, *p3;
    struct ListNode *v1, *v2, *v3;
    struct ListNode *l3;
    p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    v1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    v2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    v3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p1->val = 1;
    p2->val = 2;
    p3->val = 4;
    v1->val = 1;
    v2->val = 3;
    v3->val = 4;
    p1->next = p2;
    p2->next = p3;

    v1->next = v2;
    v2->next = v3;

    mergeTwoLists(p1, v1);
    return 0;
}
