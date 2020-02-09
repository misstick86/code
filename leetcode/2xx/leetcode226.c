/*
@File    :   leetcode226.c
@Time    :   2020/02/09 18:31:36
@Author  :   xiaosongsong
@Desc    :   None


翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

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
    if (nodelist[i] == 0 || i > 8)
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
struct TreeNode *invertTree(struct TreeNode *root)
{
    struct TreeNode *temp;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
}
int main()
{
    TreeNode *root;
    int node[] = {0, 1, 2, 3, 4, 5, 6, 7};
    root = createTree(node, 1);
    invertTree(root);
    printf("av");
    return 0;
}
