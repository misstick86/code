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
void getLeftRightMinValue(struct TreeNode *root, int *min)
{
    struct TreeNode *leftnode, *rightnode;
    if (root != NULL)
    {
        if (root->left)
        {
            leftnode = root->left;
            while (leftnode->right)
            {
                leftnode = leftnode->right;
            }
            *min = *min < abs(root->val - leftnode->val) ? *min : abs(root->val - leftnode->val);
        }
        if (root->right)
        {
            rightnode = root->right;
            while (rightnode->left)
            {
                rightnode = rightnode->left;
            }
            *min = *min < abs(root->val - rightnode->val) ? *min : abs(root->val - rightnode->val);
        }
        getLeftRightMinValue(root->left, min);
        getLeftRightMinValue(root->right, min);
    }
}
int getMinimumDifference(struct TreeNode *root)
{
    int min = 100000;
    // 节点中任意两个相邻节点的最小值
    getNodeValue(root, &min);
    // 根节点左右节点的最大值
    getLeftRightMinValue(root, &min);
    return min;
}
int main()
{
    struct TreeNode *root = NULL;
    int a[] = {2, 4443, 1329, 2917, 4406};
    for (int i = 0; i < 5; i++)
    {
        insertNode(&root, a[i]);
    }
    printf("%d", getMinimumDifference(root));
    return 0;
}
