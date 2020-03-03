/*
@File    :   leetcode109.c
@Time    :   2020/03/01 18:03:36
@Author  :   xiaosongsong
@Desc    :   None
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5


*/

#include <stdio.h>
#include <malloc.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
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
struct TreeNode *sortedListToBST(struct ListNode *head)
{
    struct TreeNode *new;
    struct ListNode *first, *last, *pre;
    first = head->next->next;
    last = head->next;

    while (first)
    {
        first = first->next->next;
        pre = last;
        last = last->next;
    }
    first = last->next;
    new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new->val = last->val;
    pre->next = NULL;
    new->left = sortedListToBST(head);
    new->right = sortedListToBST(first);
    return new;
}
int main()
{
    struct ListNode *head;
    int node[] = {-10, -3, 0, 5, 9};
    head = createList(node, 5);
    sortedListToBST(head);
    return 0;
}
