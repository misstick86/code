/*
@File    :   leetcode112.c
@Time    :   2020/02/15 10:24:07
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *CreateTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 15)
    {
        return NULL;
    }
    else
    {
        new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new->val = nodelist[i];
        new->left = CreateTree(nodelist, 2 * i);
        new->right = CreateTree(nodelist, 2 * i + 1);
        return new;
    }
}
bool hasPathSum(struct TreeNode *root, int sum)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == sum && root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else
    {
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
}
int main()
{
    struct TreeNode *root;
    int a[] = {0, 5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 0, 0, 0, 1};
    root = CreateTree(a, 1);
    printf("%d", hasPathSum(root, 22));
    return 0;
}
