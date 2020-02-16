/*
@File    :   leetcode1302.c
@Time    :   2020/02/16 12:27:05
@Author  :   xiaosongsong
@Desc    :   None
给你一棵二叉树，请你返回层数最深的叶子节点的和。

 

示例：
                1
            2       3
        4       5       6
    7                       8

输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15
 
提示：

树中节点数目在 1 到 10^4 之间。
每个节点的值在 1 到 100 之间。
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
    if (nodelist[i] == 0 || i > 15)
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

int getMaxDepth(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        left = getMaxDepth(root->left) + 1;
        right = getMaxDepth(root->right) + 1;
    }
    return left > right ? left : right;
}

void getSumLeafNode(struct TreeNode *root, int i, int depth, int *sum)
{
    if (root != NULL)
    {
        if (i == depth && root->left == NULL && root->right == NULL)
        {
            *sum += root->val;
        }
        else
        {
            getSumLeafNode(root->left, i + 1, depth, sum);
            getSumLeafNode(root->right, i + 1, depth, sum);
        }
    }
}

int deepestLeavesSum(struct TreeNode *root)
{
    int sum = 0;
    int maxDepth = getMaxDepth(root);
    getSumLeafNode(root, 1, maxDepth, &sum);
    printf("%d", sum);
    return sum;
}
int main()
{
    struct TreeNode *p;
    int node[] = {0, 1, 2, 3, 4, 5, 0, 6, 7, 0, 0, 0, 0, 0, 0, 8};
    p = createTree(node, 1);
    deepestLeavesSum(p);
    return 0;
}
