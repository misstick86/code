/*
@File    :   leetcode94.c
@Time    :   2020/01/30 10:48:27
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/

#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    if (root != NULL)
    {
        inorderTraversal(root->left, returnSize);
        printf("%d", root->val);
        *returnSize = root->val;
        inorderTraversal(root->right, returnSize);
    }
    return returnSize;
}
int main()
{

    return 0;
}
