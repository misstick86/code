/*
@File    :   leetcode701.c
@Time    :   2020/02/16 14:09:57
@Author  :   xiaosongsong
@Desc    :   None

给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

例如, 

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \
    1   3
         \
          4
*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void InsertBST(struct TreeNode **t, int x)
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
        InsertBST(&(*t)->left, x);
    }
    else
    {
        InsertBST(&(*t)->right, x);
    }
}
struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    InsertBST(&root, val);
    return root;
}
int main()
{
    struct TreeNode *root = NULL;
    int a[] = {4, 2, 7, 1, 3};
    for (int i = 0; i < 5; i++)
        InsertBST(&root, a[i]);
    insertIntoBST(root, 5);
    return 0;
}
