/*
@File    :   leetcode199.c
@Time    :   2020/02/28 20:51:31
@Author  :   xiaosongsong
@Desc    :   None

给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

*/

#include <stdio.h>
#include <malloc.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode *createBtTree(int *nodelist, int i)
{
    TreeNode *newnode;
    if (nodelist[i] == 0 || i > 10)
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
int getMaxDepth(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root)
    {
        left = getMaxDepth(root->left) + 1;
        right = getMaxDepth(root->right) + 1;
    }
    return left > right ? left : right;
}
int *rightSideView(struct TreeNode *root, int *returnSize)
{
    int *result;
    int left = 0, right = 0;
    left = getMaxDepth(root->left);
    right = getMaxDepth(root->right);
}
int main()
{
    int size = 0;
    TreeNode *root;
    int a[] = {0, 1, 2, 3, 0, 5, 0, 4, 0, 0, 7};
    root = createBtTree(a, 1);
    rightSideView(root, &size);
    return 0;
}
