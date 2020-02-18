/*
@File    :   leetcode538.c
@Time    :   2020/02/18 19:10:54
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：

输入: 二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13

*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void insertBST(struct TreeNode **t, int x)
{
    if ((*t) == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else if ((*t)->val < x)
    {
        insertBST(&(*t)->right, x);
    }
    else if ((*t)->val > x)
    {
        insertBST(&(*t)->left, x);
    }
}

int getRootSum(struct TreeNode *root)
{
    int sum = 0;
    if (root != NULL)
    {
        sum += root->val;
        sum += getRootSum(root->right);
        sum += getRootSum(root->left);
    }
    return sum;
}
void sumNode(struct TreeNode **t, int pre, int rightsum)
{
    int n;
    if ((*t) != NULL)
    {
        if ((*t)->right)
        {
            n = getRootSum((*t)->right->right);
            sumNode(&(*t)->right, pre, n);
        }
        (*t)->val = (*t)->val + pre + rightsum;
        if ((*t)->left)
        {
            n = getRootSum((*t)->right->right);
            sumNode(&(*t)->left, (*t)->val, n);
        }
    }
}
struct TreeNode *convertBST(struct TreeNode *root)
{
    // 对于每个节点来说，最后的结果由：当前节点+当前节点右树和+父节点之和
    int sum = 0;
    if (root != NULL)
    {
        sum = getRootSum(root->right);
        sumNode(&root, 0, sum);
    }
    return root;
}
int main()
{
    struct TreeNode *root = NULL;
    int a[] = {2, 0, 4, -4, 1, 3, 5};
    for (int i = 0; i < 7; i++)
    {
        insertBST(&root, a[i]);
    }
    convertBST(root);
    return 0;
}
