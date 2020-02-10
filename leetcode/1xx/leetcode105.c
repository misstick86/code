/*
@File    :   leetcode105.c
@Time    :   2020/02/10 19:39:06
@Author  :   xiaosongsong
@Desc    :   None

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    if (preorderSize == 0 || inorderSize == 0)
    {
        return NULL;
    }
    else
    {
        struct TreeNode *new;
        int k = 0;
        while (preorder[0] != inorder[k])
        {
            k++;
        }
        new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new->val = inorder[k];
        new->left = buildTree(preorder + 1, preorderSize - 1, inorder, k);
        new->right = buildTree(preorder + k + 1, preorderSize - k - 1, inorder + k + 1, inorderSize - k - 1);
        return new;
    }
}
int main()
{
    struct TreeNode *p;
    int a[] = {1, 2, 3};
    int b[] = {3, 2, 1};
    p = buildTree(a, 3, b, 3);
    printf("av");
    return 0;
}
