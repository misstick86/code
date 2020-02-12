/*
@File    :   leetcode654.c
@Time    :   2020/02/12 20:05:07
@Author  :   xiaosongsong
@Desc    :   None
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

 

示例 ：

输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    /
     2  0
       \
        1
*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize)
{
    int pos = 0;
    int max = nums[pos];
    struct TreeNode *new;
    if (numsSize <= 0)
    {
        return NULL;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
            pos = i;
        }
    }

    new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new->val = max;
    new->left = constructMaximumBinaryTree(nums, pos);
    new->right = constructMaximumBinaryTree(nums + pos + 1, numsSize - pos - 1);
    return new;
}
int main()
{
    struct TreeNode *p;
    int a[] = {3, 2, 1, 6, 0, 5};
    p = constructMaximumBinaryTree(a, 6);
    printf("av");
    return 0;
}
