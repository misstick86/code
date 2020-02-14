/*
@File    :   bstree.c
@Time    :   2020/02/14 21:42:11
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void insertBSTree(struct TreeNode **t, int x)
{
    if (*t == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else if (x < (*t)->val)
    {
        insertBSTree(&(*t)->left, x);
    }
    else if (x > (*t)->val)
    {
        insertBSTree(&(*t)->right, x);
    }
}
int main()
{

    return 0;
}
