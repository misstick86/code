/*
@File    :   leetcode108.c
@Time    :   2020/02/14 20:57:44
@Author  :   xiaosongsong
@Desc    :   None

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

*/

#include <stdio.h>
#include <malloc.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    struct TreeNode *new;
    int n = numsSize / 2;
    if (numsSize == 0)
    {
        return NULL;
    }
    else
    {
        new = (struct TreeNode *)malloc(sizeof(struct TreeNode ));
        new->val = nums[n];
        new->left = sortedArrayToBST(nums, n);
        new->right = sortedArrayToBST(nums + n + 1, numsSize - n - 1);
        return new;
    }
}
int main()
{
    struct TreeNode *p;
    int a[] = {-10, -8, -3, 0, 5, 9, 10, 11};
    p = sortedArrayToBST(a, 8);
    return 0;
}
