/*
@File    :   leetcode530.c
@Time    :   2020/02/18 11:26:06
@Author  :   xiaosongsong
@Desc    :   None
给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。

示例 :

输入:

   1
    \
     3
    /
   2

输出:
1

解释:
最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
注意: 树中至少有2个节点。


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
void insertNode(struct TreeNode **t, int x)
{
    if ((*t) == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else if ((*t)->val > x)
    {
        insertNode(&(*t)->left, x);
    }
    else if ((*t)->val < x)
    {
        insertNode(&(*t)->right, x);
    }
}

void getNodeValue(struct TreeNode *root, int *min)
{
    int temp = 0;
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            temp = abs(root->val - root->left->val);
            (*min) = (*min) < temp ? (*min) : temp;
            getNodeValue(root->left, min);
        }
        if (root->right != NULL)
        {
            temp = abs(root->val - root->right->val);
            (*min) = (*min) < temp ? (*min) : temp;
            getNodeValue(root->right, min);
        }
    }
}

int getMinimumDifference(struct TreeNode *root)
{
    int min = 100000;
    getNodeValue(root, &min);
    return min;
}
int main()
{
    struct TreeNode *root = NULL;
    int a[] = {1, 3, 2};
    for (int i = 0; i < 3; i++)
    {
        insertNode(&root, a[i]);
    }
    printf("%d", getMinimumDifference(root));

    return 0;
}
