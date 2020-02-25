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

void getNodeMin(struct TreeNode *root, int *second, int k)
{
    if (root)
    {
        if (root->val >= *second)
        {
            *second = root->val;
        }
        if (root->val > k && root->val > *second)
        {
            *second = root->val;
        }
        getNodeMin(root->left, second, k);
        getNodeMin(root->right, second, k);
    }
}

void getMin(struct TreeNode *root, int *min)
{
    int minValue = 0, maxValue = 0;
    int left = root->left->val, right = root->right->val;
    if (left == root->val)
        getNodeMin(root->left, &left, root->val);
    if (right == root->val)
        getNodeMin(root->right, &right, root->val);
    minValue = left < right ? left : right;
    maxValue = left > right ? left : right;
    if (*min < minValue)
    {
        *min = minValue;
    }
    else if (*min == minValue)
    {
        if (*min == maxValue)
        {
            *min = -1;
        }
        else
        {
            *min = maxValue;
        }
    }
}

int findSecondMinimumValue(struct TreeNode *root)
{
    int min = root->val;
    getMin(root, &min);
    printf("%d", min);
    return min;
}
int main()
{
    TreeNode *root;
    int node[] = {0, 1, 1, 3, 1, 1, 3, 4, 3, 1, 1, 1, 3, 8, 4, 8, 3, 3, 1, 6, 2, 1};
    root = createTree(node, 1);
    findSecondMinimumValue(root);
    return 0;
}
