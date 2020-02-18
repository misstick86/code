/*
@File    :   leetcode669.c
@Time    :   2020/02/18 12:02:43
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

示例 1:

输入:
    1
   / \
  0   2

  L = 1
  R = 2

输出:
    1
      \
       2
示例 2:

输入:
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

输出:
      3
     /
   2
  /
 1

*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void insertNode(struct TreeNode **t, int x)
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
        insertNode(&(*t)->left, x);
    }
    else if ((*t)->val < x)
    {
        insertNode(&(*t)->right, x);
    }
}
struct TreeNode *trimBST(struct TreeNode *root, int L, int R)
{
    if (root != NULL)
    {
        if (root->val < L)
        {
            root = root->right;
            root = trimBST(root, L, R);
        }
        else if (root->val > R)
        {
            root = root->left;
            root = trimBST(root, L, R);
        }
        else
        {
            if (root->left && root->left->val < L)
                root->left = root->left->right;
            if (root->right && root->right->val > R)
                root->right = root->right->left;
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
        }

        return root;
    }
}
int main()
{
    struct TreeNode *root = NULL;
    struct TreeNode *p;
    int node[] = {3, 2, 4, 1};
    for (int i = 0; i < 4; i++)
        insertNode(&root, node[i]);
    p = trimBST(root, 1, 1);
    return 0;
}
