/*
@File    :   leetcode783.c
@Time    :   2020/02/20 18:49:31
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉搜索树的根结点 root, 返回树中任意两节点的差的最小值。

示例：

输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树结点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \
    1   3

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
注意：

二叉树的大小范围在 2 到 100。
二叉树总是有效的，每个节点的值都是整数，且不重复。

*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void InsertBST(struct TreeNode **t, int x)
{
    if ((*t) == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else if ((*t)->val > x)
    {
        InsertBST(&(*t)->left, x);
    }
    else
    {
        InsertBST(&(*t)->right, x);
    }
}

void Inorder(struct TreeNode *root, int *p, int *i)
{
    if (root)
    {
        Inorder(root->left, p, i);
        p[*i] = root->val;
        (*i) += 1;
        Inorder(root->right, p, i);
    }
}
int minDiffInBST(struct TreeNode *root)
{
    int count = 0, temp;
    int node[100] = {};
    Inorder(root, node, &count);
    int min = abs(node[0] - node[1]);
    for (int i = 1; i + 1 < count; i++)
    {
        temp = abs(node[i] - node[i + 1]);
        min = min < temp ? min : temp;
    }
    return min;
}
int main()
{
    struct TreeNode *root = NULL;
    int node[] = {4, 2, 6, 1, 3};
    for (int i = 0; i < 5; i++)
        InsertBST(&root, node[i]);
    printf("%d", minDiffInBST(root));
    return 0;
}
