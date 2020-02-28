/*
@File    :   leetcode513.c
@Time    :   2020/02/28 20:17:10
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1
 

示例 2:

输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7

*/

#include <stdio.h>
#include <malloc.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 27)
    {
        return NULL;
    }
    else
    {
        new = (TreeNode *)malloc(sizeof(TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i);
        new->right = createTree(nodelist, 2 * i + 1);
        return new;
    }
}
int getMaxDepth(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root)
    {
        left = getMaxDepth(root->left) + 1;
        right = getMaxDepth(root->right) + 1;
        return left > right ? left : right;
    }
}

int findBottomLeftValue(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }
    else
    {
        left = getMaxDepth(root->left);
        right = getMaxDepth(root->right);
        if (left >= right)
            return findBottomLeftValue(root->left);
        else
            return findBottomLeftValue(root->right);
    }
}
int main()
{
    TreeNode *root;
    int node[] = {0, 3, 0, 30, 0, 0, 10, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45};
    // printf("%d,", sizeof(node) / sizeof(int));
    root = createTree(node, 1);
    printf("%d", findBottomLeftValue(root));
    return 0;
}
