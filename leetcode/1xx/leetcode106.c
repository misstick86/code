/*
@File    :   leetcode106.c
@Time    :   2020/02/11 09:21:08
@Author  :   xiaosongsong
@Desc    :   None

根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
    struct TreeNode *new;
    if (inorderSize == 0 || postorderSize == 0)
    {
        return NULL;
    }
    else
    {
        int k = 0;
        while (postorder[postorderSize - 1] != inorder[k])
        {
            k++;
        }

        new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new->val = inorder[k];
        new->right = buildTree(inorder + k + 1, inorderSize - k - 1, postorder + k, postorderSize - k - 1);
        new->left = buildTree(inorder, k, postorder, k);
        return new;
    }
}
int main()
{
    struct TreeNode *p;
    int a[] = {9, 3, 15, 20, 7};
    int b[] = {9, 15, 7, 20, 3};
    p = buildTree(a, 5, b, 5);
    printf("av");
    return 0;
}
