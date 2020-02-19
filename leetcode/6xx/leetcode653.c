/*
@File    :   leetcode653.c
@Time    :   2020/02/18 21:18:21
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:

输入:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

输出: True
 

案例 2:

输入:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

输出: False

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void insterNode(struct TreeNode **t, int x)
{
    if ((*t) == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else if ((*t)->val > x)
    {
        insterNode(&(*t)->left, x);
    }
    else if ((*t)->val < x)
    {
        insterNode(&(*t)->right, x);
    }
}

bool searchValue(struct TreeNode *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val > x)
    {
        return searchValue(root->left, x);
    }
    else if (root->val < x)
    {
        return searchValue(root->right, x);
    }
    else
    {
        return true;
    }
}

bool findTarget(struct TreeNode *root, int k)
{
    bool flag = false;
    if (root != NULL)
    {
        int search = k - root->val;
        if (!flag)
            flag = flag || findTarget(root->left, k);
        if (!flag)
            flag = flag || findTarget(root->right, k);
    }
    return flag;
}
int main()
{
    struct TreeNode *root = NULL;
    int a[] = {5, 3, 6, 2, 4, 7};
    for (int i = 0; i < 6; i++)
        insterNode(&root, a[i]);
    printf("%d", findTarget(root, 10));
    return 0;
}
