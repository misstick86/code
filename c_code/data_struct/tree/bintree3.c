/*
@File    :   bintree3.c
@Time    :   2020/01/29 17:57:35
@Author  :   xiaosongsong
@Desc    :   None
数据结构书中示例
*/

#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;
typedef struct TreeNode
{
    ElemType val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createBtTree(ElemType *nodelist, int i)
{
    TreeNode *newnode;
    if (nodelist[i] == 0 || i > 7)
        return NULL;
    else
    {
        newnode = (TreeNode *)malloc(sizeof(TreeNode));
        newnode->val = nodelist[i];
        newnode->left = createBtTree(nodelist, 2 * i);
        newnode->right = createBtTree(nodelist, 2 * i + 1);
        return newnode;
    }
}

void PreOrder(TreeNode *bt)
{
    if (bt != NULL)
    {
        printf("%d", bt->val);
        PreOrder(bt->left);
        PreOrder(bt->right);
    }
}

void InOrder(TreeNode *bt)
{
    if (bt != NULL)
    {

        InOrder(bt->left);
        printf("%d", bt->val);
        InOrder(bt->right);
    }
}

void PostOrder(TreeNode *bt)
{
    if (bt != NULL)
    {
        PostOrder(bt->left);
        PostOrder(bt->right);
        printf("%d", bt->val);
    }
}

int main()
{
    ElemType node[] = {0, 1, 3, 5, 0, 8, 6, 2};
    TreeNode *mytree = NULL;
    mytree = createBtTree(node, 1);
    printf("\nPreOrder: ");
    PreOrder(mytree);
    printf("\nInOrder: ");
    InOrder(mytree);
    printf("\nPostOrder: ");
    PostOrder(mytree);
    return 0;
}
