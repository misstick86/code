/*
@File    :   leetcode257.c
@Time    :   2020/02/21 18:11:14
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
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
    if (nodelist[i] == 0 || i > 8)
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
    new->count++;
    if (st == NULL)
    {
        new->next = NULL;
        return new;
    }
    else
    {

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

char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{
    char **result;
    int i = 0;
    char re[1024] = {};
    (result) = (char **)malloc(sizeof(char) * 1024);
    struct TreeNode *p;
    TreeStack *st;
    st = initStack(st);
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    st = Push(st, root);
    re[i++] = root->val + '0';
    while (!Empty(st))
    {
        while (root && root->left)
        {
            st = Push(st, root->left);
            root = root->left;
            re[i++] = root->val + '0';
        }

        getTopValue(st, &p);
        st = Pop(st);
        if (p->left == NULL && p->right == NULL)
        {
            result[*returnSize] = (char *)malloc(sizeof(char) * (i + 1));
            strncpy(result[(*returnSize)++], re, i);
            printf("%s,", *result);
            result++;
        }
        // printf("%d,", p->val);
        if (p->right)
        {
            st = Push(st, p->right);
            re[i++] = p->right->val + '0';
            root = p->right;
        }
        else
        {
            i--;
        }
    }
    return result;
}
int main()
{
    int size = 0;
    TreeNode *root;
    int node[] = {0, 1, 2, 3, 4, 5, 0, 0, 7};
    root = createTree(node, 1);
    binaryTreePaths(root, &size);
    return 0;
}
