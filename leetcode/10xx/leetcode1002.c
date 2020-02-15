/*
@File    :   leetcode1002.c
@Time    :   2020/02/10 10:58:11
@Author  :   xiaosongsong
@Desc    :   None

给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

以 10^9 + 7 为模，返回这些数字之和。

 

示例：
           1
         /   \
        0     1
       / \   / \
      0   1 0   1

输入：[1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

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
void leafNode(struct TreeNode *root, int n, int *sum)
{
    if (root != NULL && root->left == NULL && root->right == NULL)
    {
        (*sum) += n * 2 + root->val;
    }
    else
    {
        if (root->left)
            leafNode(root->left, (n * 2 + root->val), sum);
        if (root->right)
            leafNode(root->right, (n * 2 + root->val), sum);
    }
}

int sumRootToLeaf(struct TreeNode *root)
{
    int sum = 0;
    leafNode(root, 0, &sum);
    printf("%d", sum);
    return sum;
}
int main()
{
    struct TreeNode *root;
    int a[] = {0, 1, 0, 1, 0, 1, 0, 1};
    root = createTree(a, 1);
    sumRootToLeaf(root);
    return 0;
}
