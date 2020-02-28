/*
@File    :   leetcode230.c
@Time    :   2020/02/28 10:40:07
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct TreeStack
{
    struct TreeNode *val;
    struct TreeStack *next;
    int count;
} TreeStack;

TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 8)
    {
        return NULL;
    }
    else
    {
        new = (TreeNode *)malloc(sizeof(TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i);
        new->right = createTree(nodelist, 2 * i + 1);
        return new;
    }
}

TreeStack *initStack(TreeStack *p)
{
    p = NULL;
    return p;
}
bool Empty(TreeStack *p)
{
    return p == NULL;
}

TreeStack *Push(TreeStack *st, struct TreeNode *val)
{
    TreeStack *new;
    new = (TreeStack *)malloc(sizeof(TreeStack));
    new->val = val;
    new->count++;
    if (st == NULL)
    {
        new->next = NULL;
        return new;
    }
    else
    {

        new->next = st;
        st = new;
        return st;
    }
}
TreeStack *Pop(TreeStack *st)
{
    TreeStack *p;
    p = st;
    st = st->next;
    free(p);
    p = NULL;
    return st;
}

void getTopValue(TreeStack *st, struct TreeNode **val)
{
    *val = st->val;
}

int kthSmallest(struct TreeNode *root, int k)
{
    int i = 0;
    TreeStack *st;
    struct TreeNode *p;
    if (root == NULL)
    {
        return 0;
    }
    st = initStack(st);
    st = Push(st, root);
    while (!Empty(st))
    {
        while (root && root->left)
        {
            st = Push(st, root->left);
            root = root->left;
        }
        getTopValue(st, &p);
        st = Pop(st);
        i++;
        if (i == k)
            return p->val;
        if (p->right)
        {
            st = Push(st, p->right);
            root = p->right;
        }
    }
}
int main()
{
    TreeNode *root;
    int node[] = {0, 5, 3, 6, 2, 4, 0, 0, 1};
    root = createTree(node, 1);
    printf("%d", kthSmallest(root, 6));
    return 0;
}
