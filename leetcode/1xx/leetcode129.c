/*
@File    :   leetcode129.c
@Time    :   2020/02/16 10:34:21
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.


*/

#include <stdio.h>
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
    if (nodelist[i] == 10 || i > 5)
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
void leafNode(struct TreeNode *root, int n, int *sum)
{
    if (root != NULL && root->left == NULL && root->right == NULL)
    {
        (*sum) += n * 10 + root->val;
    }
    else
    {
        if (root->left)
            leafNode(root->left, (n * 10 + root->val), sum);
        if (root->right)
            leafNode(root->right, (n * 10 + root->val), sum);
    }
}
int sumNumbers(struct TreeNode *root)
{
    int sum = 0;
    if (root == NULL)
    {
        return 0;
    }
    leafNode(root, 0, &sum);
    return sum;
}
int main()
{
    struct TreeNode *root;
    int a[] = {0, 4, 9, 0, 5, 1};
    root = CreateTree(a, 1);
    sumNumbers(root);
    return 0;
}
