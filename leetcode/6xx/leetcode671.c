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
    if (nodelist[i] == 0 || i > 21)
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

void findMin(struct TreeNode *root, int x, int *min)
{

    if (root)
    {
        findMin(root->left, x, min);
        findMin(root->right, x, min);
        if (root->val > x && root->val < *min)
            *min = root->val;
    }
}
void getNodeMax(struct TreeNode *root, int *max)
{
    if (root)
    {
        getNodeMax(root->left, max);
        getNodeMax(root->right, max);
        if (*max < root->val)
            *max = root->val;
    }
}
int findSecondMinimumValue(struct TreeNode *root)
{
    int min = root->val;
    getNodeMax(root, &min);
    if (min == root->val)
        return -1;
    findMin(root->left, root->val, &min);
    findMin(root->right, root->val, &min);
    return min;
}
int main()
{
    TreeNode *root;
    int node[] = {0, 1, 1, 3, 1, 1, 3, 4, 3, 1, 1, 1, 3, 8, 4, 8, 3, 3, 2, 6, 4, 1};
    // int node[] = {0, 2, 2, 2};
    root = createTree(node, 1);
    printf("%d", findSecondMinimumValue(root));
    return 0;
}
