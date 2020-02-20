/*
@File    :   leetcode897.c
@Time    :   2020/02/18 17:01:18
@Author  :   xiaosongsong
@Desc    :   None
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

typedef struct TreeStack
{
    struct TreeNode *val;
    struct TreeStack *next;
} TreeStack;

struct TreeNode *createTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 15)
    {
        return NULL;
    }
    else
    {
        new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i);
        new->right = createTree(nodelist, 2 * i + 1);
        return new;
    }
}

// 初始化栈

TreeStack *initStack(TreeStack *st)
{
    st = NULL;
    return st;
}

// 判断栈空

bool Empty(TreeStack *st)
{
    return st == NULL;
}
// 入栈
TreeStack *Push(TreeStack *st, struct TreeNode *x)
{
    TreeStack *new;
    new = (TreeStack *)malloc(sizeof(TreeStack));
    new->val = x;
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

//出栈
TreeStack *Pop(TreeStack *st)
{
    TreeStack *p;
    p = st;
    st = st->next;
    free(p);
    p = NULL;
    return st;
}

// 获取栈顶元素

void getTopValue(TreeStack *st, struct TreeNode **x)
{
    if (st != NULL)
    {
        *x = st->val;
    }
    else
    {
        *x = NULL;
    }
}

void InsertTree(struct TreeNode **t, int x)
{
    if (*t == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else
    {
        InsertTree(&(*t)->right, x);
    }
}
struct TreeNode *increasingBST(struct TreeNode *root)
{
    struct TreeNode *newroot = NULL;
    TreeStack *st;
    st = initStack(st);
    struct TreeNode *p;
    if (root == NULL)
        return newroot;
    st = Push(st, root);
    while (!Empty(st))
    {
        while (root && root->left)
        {
            st = Push(st, root->left);
            root = root->left;
        }
        getTopValue(st, &p);
        st = Pop(st);
        InsertTree(&newroot, p->val);
        // printf("%d", p->val);
        if (p->right)
        {
            root = p->right;
            if (root)
                st = Push(st, root);
        }
    }
    return newroot;
}
int main()
{
    struct TreeNode *root, *p;
    int node[] = {0, 5, 3, 6, 2, 4, 0, 8, 1, 0, 0, 0, 0, 0, 7, 9};
    root = createTree(node, 1);
    p = increasingBST(root);
    return 0;
}
