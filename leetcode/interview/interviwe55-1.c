/*
@File    :   interviwe55-1.c
@Time    :   2020/02/17 22:44:10
@Author  :   xiaosongsong
@Desc    :   None
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

 

提示：

节点总数 <= 10000
注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 7)
    {
        return NULL;
    }
    else
    {
        new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i);
        new->right = createTree(nodelist, 2 * i + 1);
        return new;
    }
}
int maxDepth(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        left = maxDepth(root->left) + 1;
        right = maxDepth(root->right) + 1;
        return left > right ? left : right;
    }
}
int main()
{
    struct TreeNode *root;
    int node[] = {0, 3, 9, 20, 0, 0, 15, 7};
    root = createTree(node, 1);
    printf("%d", maxDepth(root));
    return 0;
}
