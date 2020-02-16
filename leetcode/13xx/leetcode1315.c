/*
@File    :   leetcode1315.c
@Time    :   2020/02/16 14:57:08
@Author  :   xiaosongsong
@Desc    :   None

给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：

该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
如果不存在祖父节点值为偶数的节点，那么返回 0 。

 

示例：



输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
输出：18
解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点

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

void SumNode(struct TreeNode *root, int *sum)
{
    if (root)
    {
        if (root->val % 2 == 0)
        {
            if (root->left)
            {
                if (root->left->left)
                {
                    (*sum) += root->left->left->val;
                }
                if (root->left->right)
                {
                    (*sum) += root->left->right->val;
                }
            }
            if (root->right)
            {
                if (root->right->left)
                {
                    (*sum) += root->right->left->val;
                }
                if (root->right->right)
                {
                    (*sum) += root->right->right->val;
                }
            }
        }
        SumNode(root->left, sum);
        SumNode(root->right, sum);
    }
}
int sumEvenGrandparent(struct TreeNode *root)
{
    int sum = 0;
    SumNode(root, &sum);
    return sum;
}
int main()
{
    struct TreeNode *root;
    int node[] = {0, 6, 7, 8, 2, 7, 1, 3, 9, 0, 1, 4, 0, 0, 0, 5};
    root = createTree(node, 1);
    printf("%d", sumEvenGrandparent(root));
    return 0;
}
