/*
@File    :   leetcode100.c
@Time    :   2020/02/10 09:57:29
@Author  :   xiaosongsong
@Desc    :   None

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 4)
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

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    bool flag;
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p != NULL && q == NULL || p == NULL && q != NULL)
    {
        return false;
    }
    flag = p->val == q->val ? true : false;
    flag = flag && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
    return flag;
}
int main()
{
    int a[] = {0, 1, 2, 3};
    int b[] = {0, 1, 2, 3};
    TreeNode *p1, *p2;
    p1 = createTree(a, 1);
    p2 = createTree(b, 1);
    isSameTree(p1, p2);
    return 0;
}
