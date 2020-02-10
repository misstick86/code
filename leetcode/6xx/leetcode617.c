/*
@File    :   leetcode617.c
@Time    :   2020/02/10 15:50:57
@Author  :   xiaosongsong
@Desc    :   None

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
输出:
合并后的树:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7
注意: 合并必须从两个树的根节点开始。

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
    if (nodelist[i] == 0 || i > 5)
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

TreeNode *createTree2(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 8)
    {
        return NULL;
    }
    else
    {
        new = (TreeNode *)malloc(sizeof(TreeNode));
        new->val = nodelist[i];
        new->left = createTree2(nodelist, 2 * i);
        new->right = createTree2(nodelist, 2 * i + 1);
        return new;
    }
}

struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2)
{
    struct TreeNode *new;
    if (t1 == NULL && t2 == NULL)
    {
        return NULL;
    }
    if (t1 == NULL)
    {
        return t2;
    }
    if (t2 == NULL)
    {
        return t1;
    }
    new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new->val = t1->val + t2->val;
    new->left = mergeTrees(t1->left, t2->left);
    new->right = mergeTrees(t1->right, t2->right);
    return new;
}

int main()
{
    TreeNode *p1, *p2, *result;
    int a[] = {0, 1, 3, 2, 5};
    int b[] = {0, 2, 1, 3, 0, 4, 0, 7};
    p1 = createTree(a, 1);
    p2 = createTree2(b, 1);
    result = mergeTrees(p1, p2);
    printf("av");
    return 0;
}
