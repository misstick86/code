/*
@File    :   leetcode543.c
@Time    :   2020/02/21 10:52:21
@Author  :   xiaosongsong
@Desc    :   None

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \
      4   5
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

*/

#include <stdio.h>
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
    if (nodelist[i] == 0 || i > 5)
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
        return left > right ? left : right;
    }
}
void getNodeMax(struct TreeNode *root, int *max)
{
    int left = 0, rigth = 0;
    if (root)
    {
        if (root->left)
            left = getMaxDepth(root->left);
        if (root->right)
            rigth = getMaxDepth(root->right);
        *max = *max > rigth + left ? *max : rigth + left;
        getNodeMax(root->left, max);
        getNodeMax(root->right, max);
    }
}

int diameterOfBinaryTree(struct TreeNode *root)
{
    int max = 0;
    if (root == NULL)
        return 0;
    getNodeMax(root, &max);
    return max;
}

int main()
{
    TreeNode *root;
    int a[] = {0, 1, 2, 3, 4, 5};
    root = createTree(a, 1);
    printf("%d", diameterOfBinaryTree(root));
    return 0;
}
