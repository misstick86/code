/*
@File    :   leetcode1019.c
@Time    :   2020/04/02 11:08:27
@Author  :   xiaosongsong
@Desc    :   None

给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。

每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。

返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。

注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。

 

示例 1：

输入：[2,1,5]
输出：[5,5,0]
示例 2：

输入：[2,7,4,3,5]
输出：[7,0,5,5,0]
示例 3：

输入：[1,7,5,1,9,2,5,1]
输出：[7,9,9,9,0,5,0,0]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-node-in-linked-list

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListStack
{
    struct ListNode *p;
    int count;
    struct ListStack *next;
} ListStack;

bool Empty(ListStack *st)
{
    return st == NULL;
}
ListStack *initStack()
{
    ListStack *p = (ListStack *)malloc(sizeof(ListStack));
    p = NULL;
    return p;
}
ListStack *Push(ListStack *st, struct ListNode *p, int val)
{
    ListStack *new;
    new = (ListStack *)malloc(sizeof(ListStack));
    new->p = p;
    new->count = val;
    new->next = NULL;
    if (st == NULL)
        return new;
    new->next = st;
    return new;
}
ListStack *Pop(ListStack *st)
{
    ListStack *p;
    if (!Empty(st))
    {
        p = st;
        st = st->next;
        free(p);
        p = NULL;
        return st;
    }
    return NULL;
}

struct ListNode *createList(int *nodelist, int count)
{
    struct ListNode *new, *pointer, *head;
    new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = nodelist[0];
    new->next = NULL;
    head = new;
    pointer = new;
    for (int i = 1; i < count; i++)
    {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = nodelist[i];
        new->next = NULL;
        pointer->next = new;
        pointer = new;
    }
    return head;
}
int *nextLargerNodes(struct ListNode *head, int *returnSize)
{
    int i = 0;
    int *result;
    result = (int *)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    if (head == NULL)
        return NULL;
    struct ListNod *p;
    ListStack *st = initStack();
    st = Push(st, head, i++);
    head = head->next;
    while (head)
    {
        while (!Empty(st) && st->p->val < head->val)
        {
            result[st->count] = head->val;
            st = Pop(st);
        }
        st = Push(st, head, i++);
        head = head->next;
    }
    while (!Empty(st))
    {
        result[st->count] = 0;
        st = Pop(st);
    }
    *returnSize = i;
    return result;
}
int main()
{
    int size = 0;
    struct ListNode *head;
    int nodelist[] = {1, 7, 5, 1, 9, 2, 5, 1};
    head = createList(nodelist, sizeof(nodelist) / sizeof(int));
    nextLargerNodes(head, &size);
    return 0;
}
