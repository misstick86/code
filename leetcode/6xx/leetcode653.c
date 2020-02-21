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

void Inorder(struct TreeNode *root, int *p, int *i)
{

    if (root)
    {
        Inorder(root->left, p, i);
        p[(*i)++] = root->val;
        Inorder(root->right, p, i);
    }
}

bool findTarget(struct TreeNode *root, int k)
{
    int node[102400] = {};
    int count = 0;
    Inorder(root, node, &count);
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
        {
            if (node[i] + node[j] == k)
                return true;
        }
    return false;
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
