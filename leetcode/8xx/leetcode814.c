/*
@File    :   leetcode814.c
@Time    :   2020/03/01 11:30:38
@Author  :   xiaosongsong
@Desc    :   None

给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。

返回移除了所有不包含 1 的子树的原二叉树。

( 节点 X 的子树为 X 本身，以及所有 X 的后代。)

示例1:
输入: [1,null,0,0,1]
输出: [1,null,0,null,1]

解释:
只有红色节点满足条件“所有不包含 1 的子树”。
右图为返回的答案。


示例2:
输入: [1,0,1,0,0,0,1]
输出: [1,null,1,null,1]



示例3:
输入: [1,1,0,1,1,0,1,0]
输出: [1,1,0,1,1,null,1]



说明:

给定的二叉树最多有 100 个节点。
每个节点的值只会为 0 或 1 。

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
    if (nodelist[i] == 2 || i > 7)
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
void pruneNode(struct TreeNode **root)
{
    if ((*root) && (*root)->left)
        pruneNode(&(*root)->left);
    if ((*root) && (*root)->right)
        pruneNode(&(*root)->right);
    if ((*root)->val == 0 && (*root)->left == NULL && (*root)->right == NULL)
        (*root) = NULL;
}
struct TreeNode *pruneTree(struct TreeNode *root)
{
    pruneNode(&root);
    return root;
}
int main()
{
    TreeNode *root;
    int node[] = {2, 1, 2, 0, 2, 2, 0, 1};
    root = createTree(node, 1);
    pruneTree(root);
    return 0;
}
