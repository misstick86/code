/*
@File    :   leetcode104.c
@Time    :   2020/01/31 11:05:09
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef int ElemType;
typedef struct TreeNode
{
    ElemType val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createBtTree(ElemType *nodelist, int i)
{
    TreeNode *newnode;
    if (nodelist[i] == 0 || i > 7)
        return NULL;
    else
    {
        newnode = (TreeNode *)malloc(sizeof(TreeNode));
        newnode->val = nodelist[i];
        newnode->left = createBtTree(nodelist, 2 * i);
        newnode->right = createBtTree(nodelist, 2 * i + 1);
        return newnode;
    }
}
int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left_length = maxDepth(root->left);
        int right_length = maxDepth(root->right);
        return (left_length > right_length ? left_length : right_length) + 1;
    }
}
int main()
{
    ElemType node[] = {0, 3, 9, 20, 0, 0, 15, 7};
    TreeNode *mytree = NULL;
    mytree = createBtTree(node, 1);
    int length = maxDepth(mytree);
    printf("%d", length);
    return 0;
}
