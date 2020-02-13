/*
@File    :   leetcode101.c
@Time    :   2020/02/11 10:25:05
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *CreateTree(int *nodelist, int i)
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
        new->left = CreateTree(nodelist, 2 * i);
        new->right = CreateTree(nodelist, 2 * i + 1);
        return new;
    }
}
bool isSymmetric(struct TreeNode *root)
{
}
int main()
{
    struct TreeNode *root;
    int a[] = {0, 1, 2, 2, 3, 4, 4, 3};
    root = CreateTree(a, 1);
    isSymmetric(root);
    return 0;
}
