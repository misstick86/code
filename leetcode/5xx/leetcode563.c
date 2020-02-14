/*
@File    :   leetcode563.c
@Time    :   2020/02/14 13:52:54
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树，计算整个树的坡度。

一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

整个树的坡度就是其所有节点的坡度之和。

示例:

输入:
         1
       /   \
      2     3
输出: 1
解释:
结点的坡度 2 : 0
结点的坡度 3 : 0
结点的坡度 1 : |2-3| = 1
树的坡度 : 0 + 0 + 1 = 1
注意:

任何子树的结点的和不会超过32位整数的范围。
坡度的值不会超过32位整数的范围。

*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 6)
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

// 获取当前节点的左或者右所有之和

int getSumValue(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->val + getSumValue(root->left) + getSumValue(root->right);
    }
}

int findTilt(struct TreeNode *root)
{
    int sum = 0;
    if (root)
    {
        sum += abs(getSumValue(root->left) - getSumValue(root->right));
        sum += findTilt(root->left);
        sum += findTilt(root->right);
        return sum;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int p;
    struct TreeNode *root;
    int node[] = {0, 1, 2, 3, 4, 6, 5};

    root = createTree(node, 1);
    // printf("%d", getSumValue(root));
    p = findTilt(root);
    printf("%d", p);
    return 0;
}
