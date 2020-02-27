/*
@File    :   leetcode98.c
@Time    :   2020/02/27 21:42:30
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

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
struct TreeNode *createTree(int *nodelist, int i)
{
    if (nodelist[i] == 0 || i > 7)
    {
        return NULL;
    }
    else
    {
        struct TreeNode *new;
        new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i);
        new->right = createTree(nodelist, 2 * i + 1);
        return new;
    }
}

void getInOrder(struct TreeNode *root, int *node, int *i)
{
    if (root)
    {
        getInOrder(root->left, node, i);
        node[(*i)++] = root->val;
        getInOrder(root->right, node, i);
    }
}
bool isValidBST(struct TreeNode *root)
{
    int node[1024] = {}, count = 0;
    getInOrder(root, node, &count);
    for (int i = 0; i + 1 < count; i++)
    {
        if (node[i] > node[i + 1])
            return false;
    }
    return true;
}
int main()
{
    int node[] = {0, 10, 5, 15, 0, 0, 6, 20};
    struct TreeNode *root;
    root = createTree(node, 1);
    printf("%d", isValidBST(root));
    return 0;
}
