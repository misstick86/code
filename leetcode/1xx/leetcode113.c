/*
@File    :   leetcode113.c
@Time    :   2020/02/28 10:59:04
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

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

typedef struct TreeStack
{
    struct TreeNode *val;
    struct TreeStack *next;
    int count;
} TreeStack;
TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 15)
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
TreeStack *initStack(TreeStack *p)
{
    p = NULL;
    return p;
}
bool Empty(TreeStack *p)
{
    return p == NULL;
}

TreeStack *Push(TreeStack *st, struct TreeNode *val)
{
    TreeStack *new;
    new = (TreeStack *)malloc(sizeof(TreeStack));
    new->val = val;
    if (st == NULL)
    {
        new->count = val->val;
        new->next = NULL;
        return new;
    }
    else
    {
        new->count = st->count + val->val;
        new->next = st;
        st = new;
        return st;
    }
}
TreeStack *Pop(TreeStack *st)
{
    TreeStack *p;
    p = st;
    st = st->next;
    free(p);
    p = NULL;
    return st;
}

void getTopValue(TreeStack *st, struct TreeNode **val)
{
    *val = st->val;
}
int **pathSum(struct TreeNode *root, int sum, int *returnSize, int **returnColumnSizes)
{
    int **result;
    int temp[1024] = {};
    TreeStack *st;
    struct TreeNode *p;
    st = initStack(st);
    st = Push(st, root);
    temp[0] = root->val;
    *returnSize = 0;
    result = (int **)malloc(sizeof(int *) * 1024);
    int i = 1;
    while (!Empty(st))
    {
        while (root && root->left)
        {

            st = Push(st, root->left);
            root = root->left;
            temp[i++] = root->val;
        }
        getTopValue(st, &p);
        st = Pop(st);
        i--;
        if (p->left == NULL && p->right == NULL && st->count + p->val == sum)
        {
            result[(*returnSize)++] = (int *)malloc(sizeof(int) * st->count);
            for (int j = 0; j < i; j++)
            {
                result[(*returnSize) - 1][j] = temp[i];
            }
        }

        if (p->right)
        {
            st = Push(st, p->right);
            st->count += p->val;
            root = p->right;
            temp[i++] = root->val;
        }
    }
}
int main()
{
    int size = 0, *p;
    struct TreeNode *root;
    int node[] = {0, 5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 0, 0, 5, 1};
    root = createTree(node, 1);
    pathSum(root, 22, &size, &p);
    return 0;
}
