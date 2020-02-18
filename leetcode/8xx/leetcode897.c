/*
@File    :   leetcode897.c
@Time    :   2020/02/18 17:01:18
@Author  :   xiaosongsong
@Desc    :   None
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

struct TreeNode *increasingBST(struct TreeNode *root)
{
    return getBST(root, NULL);
}
int main()
{
    struct TreeNode *root, *p;
    int node[] = {0, 5, 3, 6, 2, 4, 0, 8, 1, 0, 0, 0, 0, 0, 7, 9};
    root = createTree(node, 1);
    p = increasingBST(root);
    return 0;
}
