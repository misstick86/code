/*
@File    :   leetcode160.c
@Time    :   2020/03/07 17:38:15
@Author  :   xiaosongsong
@Desc    :   None

编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。

 

示例 1：



输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。



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
    struct ListNode *new, *pointer, *p;
    new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = node[0];
    new->next = NULL;
    p = new;
    pointer = new;
    for (int i = 1; i < n; i++)
    {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = node[i];
        new->next = NULL;
        pointer->next = new;
        pointer = new;
    }
    return p;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *p1, *p2;
    p2 = headB;
    while (headA)
    {
        while (headB)
        {
            if (headB == headA)
                return headB;
            headB = headB->next;
        }
        headB = p2;
        headA = headA->next;
    }
    return NULL;
}
int main()
{
    int i = 2;
    struct ListNode *head1, *head2, *p1, *p2;
    int list1[] = {0, 9, 1, 2, 4};
    int list2[] = {3, 2, 4};
    head1 = createList(list1, 5);
    head2 = createList(list2, 3);
    p1 = head1;
    while (i--)
    {
        p1 = p1->next;
    }
    p1->next = head2->next;
    getIntersectionNode(head1, head2);
    return 0;
}
