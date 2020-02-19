/*
@File    :   leetcode671.c
@Time    :   2020/02/19 09:42:54
@Author  :   xiaosongsong
@Desc    :   None
给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 

给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

示例 1:

输入:
    2
   / \
  2   5
     / \
    5   7

输出: 5
说明: 最小的值是 2 ，第二小的值是 5 。
示例 2:

输入:
    2
   / \
  2   2

输出: -1
说明: 最小的值是 2, 但是不存在第二小的值。


*/

#include <stdio.h>
#include <stdbool.h>
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
    if (nodelist[i] == 0 || i > 7)
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
int findSecondMinimumValue(struct TreeNode *root)
{
    int min = -1;
    int leftmin = -1, rightmin = -1;
    if (root->left)
    {
        leftmin = root->left->val;
    }
    if (root->right)
    {
        rightmin = root->right->val;
    }
    min = leftmin <= rightmin ? leftmin : rightmin;
    if (min == root->val)
    {
        leftmin = findSecondMinimumValue(root->left);
        rightmin = findSecondMinimumValue(root->right);
    }
    else
    {
        return min;
    }
}
int main()
{
    TreeNode *root;
    int node[] = {0, 2, 2, 5, 0, 0, 5, 7};
    root = createTree(node, 1);
    findSecondMinimumValue(root);
    return 0;
}
