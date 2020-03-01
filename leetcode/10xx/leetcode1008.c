/*
@File    :   leetcode1008.c
@Time    :   2020/03/01 09:42:37
@Author  :   xiaosongsong
@Desc    :   None

返回与给定先序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。

(回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，先序遍历首先显示节点的值，然后遍历 node.left，接着遍历 node.right。）

 

示例：

输入：[8,5,1,7,10,12]
输出：[8,5,10,1,7,null,12]

*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void insertTree(struct TreeNode **t, int x)
{
    if ((*t) == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else
    {
        if ((*t)->val > x)
            return insertTree(&(*t)->left, x);
        else
            return insertTree(&(*t)->right, x);
    }
}
struct TreeNode *bstFromPreorder(int *preorder, int preorderSize)
{
    struct TreeNode *root = NULL;
    for (int i = 0; i < preorderSize; i++)
    {
        insertTree(&root, preorder[i]);
    }
    return root;
}
int main()
{
    int node[] = {8, 5, 1, 7, 10, 12};
    bstFromPreorder(node, 6);
    return 0;
}
