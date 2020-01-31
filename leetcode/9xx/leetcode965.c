/*
@File    :   leetcode965.c
@Time    :   2020/01/30 20:12:44
@Author  :   xiaosongsong
@Desc    :   None

如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。

示例 1：

输入：[1,1,1,1,1,null,1]
输出：true
示例 2：



输入：[2,2,2,5,2]
输出：false

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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
bool isUnivalTree(struct TreeNode *root)
{
}
int main()
{
    ElemType node[] = {0, 1, 1, 1, 1, 1, 0, 1};
    TreeNode *mytree = NULL;
    mytree = createBtTree(node, 1);
    return 0;
}
