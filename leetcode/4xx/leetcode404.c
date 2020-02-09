/*
@File    :   leetcode404.c
@Time    :   2020/02/09 21:20:15
@Author  :   xiaosongsong
@Desc    :   None
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24


*/

#include <stdio.h>
#include <malloc.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 16)
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

int sumOfLeftLeaves(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
    {
        left = root->left->val;
    }
    left += sumOfLeftLeaves(root->left);
    right += sumOfLeftLeaves(root->right);
    return left + right;
}

int main()
{
    int p;
    TreeNode *root;
    int a[] = {0, 3, 9, 20, 0, 0, 15, 7, 0, 0, 0, 0, 0, 18, 2, 6};
    root = createTree(a, 1);
    p = sumOfLeftLeaves(root);
    printf("%d", p);
    return 0;
}
