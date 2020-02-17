/*
@File    :   leetcode111.c
@Time    :   2020/02/17 10:56:45
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.


*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 7)
    {
        return NULL;
    }
    else
    {
        new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i);
        new->right = createTree(nodelist, 2 * i + 1);
        return new;
    }
}

void getMinNode(struct TreeNode *root, int depth, int *min)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            (*min) = (*min) < depth + 1 ? *min : depth + 1;
        }
        getMinNode(root->left, depth + 1, min);
        getMinNode(root->right, depth + 1, min);
    }
}
int minDepth(struct TreeNode *root)
{
    int min = 1000;
    if (root == NULL)
        return 0;
    getMinNode(root, 0, &min);
    printf("%d", min);
    return min;
}
int main()
{
    struct TreeNode *root;
    int node[] = {0, 3, 9, 20, 0, 0, 15, 7};
    root = createTree(node, 1);
    minDepth(root);
    return 0;
}
