/*
@File    :   leetcode110.c
@Time    :   2020/02/17 09:16:16
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
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
    if (nodelist[i] == 0 || i > 7)
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

int getNodeDepth(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        left = getNodeDepth(root->left) + 1;
        right = getNodeDepth(root->right) + 1;
        return left > right ? left : right;
    }
}
bool isBalanced(struct TreeNode *root)
{
    bool flag = true;
    if (root == NULL)
    {
        return true;
    }
    else
    {
        flag = abs(getNodeDepth(root->left) - getNodeDepth(root->right)) <= 1;
        flag = flag && isBalanced(root->left) && isBalanced(root->right);
    }

    return flag;
}
int main()
{
    struct TreeNode *root;
    int a[] = {0, 3, 9, 20, 0, 0, 15, 7};
    root = createTree(a, 1);

    printf("%d", isBalanced(root));
    return 0;
}
