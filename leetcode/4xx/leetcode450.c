/*
@File    :   leetcode450.c
@Time    :   2020/02/29 10:27:18
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7

*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void insertTree(struct TreeNode **t, int x)
{
    if ((*t) == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else
    {
        if ((*t)->val > x)
            insertTree(&(*t)->left, x);
        else
            insertTree(&(*t)->right, x);
    }
}

struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    struct TreeNode *p, *parent = NULL, *q, *k;
    p = root;
    while (p && p->val != key)
    {
        parent = p;
        if (p->val > key)
            p = p->left;
        else
            p = p->right;
    }
    if (p == NULL)
        return root;
    if (p->left && p->right)
    {
        k = p;
        parent = p;
        p = p->right;
        while (p->left)
        {
            parent = p;
            p = p->left;
        }
        k->val = p->val;
    }

    if (p->left)
        q = p->left;
    else
        q = p->right;

    if (parent)
    {
        if (parent->left == p)
            parent->left = q;
        else
            parent->right = q;
    }
    else
    {
        parent = q;
        root = parent;
    }

    free(p);
    p = NULL;
    return root;
}

int main()
{
    struct TreeNode *root = NULL;
    int node[] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        insertTree(&root, node[i]);
    }
    deleteNode(root, 4);
    return 0;
}
