/*
@File    :   leetcode173.c
@Time    :   2020/03/02 10:27:01
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MaxSize 1024
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct BSTIterator
{
    struct TreeNode *val[MaxSize];
    int top;
} BSTIterator;

// 初始化栈
void initStack(BSTIterator *st)
{
    st->top = 0;
    // st->top = 0;
}
//  判断栈空
bool Empty(BSTIterator *st)
{
    return st->top == 0;
}

// 判断栈满
bool Full(BSTIterator *st)
{
    return st->top == MaxSize;
}

void Push(BSTIterator *st, struct TreeNode *x)
{
    if (!Full(st))
        st->val[st->top++] = x;
}

// 出栈
void Pop(BSTIterator *st)
{
    st->val[--st->top] = NULL;
}

// 获取栈顶元素
struct TreeNode *getTopValue(BSTIterator *st)
{
    return st->val[st->top - 1];
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{

    BSTIterator st, *p;
    p = &st;
    initStack(&st);
    while (root)
    {
        Push(&st, root);
        root = root->left;
    }
    return p;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator *obj)
{
    struct TreeNode *p1, *q = NULL;
    p1 = getTopValue(obj);
    q = p1->right;
    Pop(obj);
    if (p1->right)
        Push(obj, p1->right);
    q = p1->right;
    while (q && q->left)
    {
        Push(obj, q->left);
        q = q->left;
    }
    return p1->val;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator *obj)
{
    if (!Empty(obj))
        return true;
    return false;
}

void bSTIteratorFree(BSTIterator *obj)
{
    free(obj);
    obj = NULL;
}

// 创建二插搜索树
void insertTree(struct TreeNode **t, int x)
{
    if (*t == NULL)
    {
        *t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else
    {
        if ((*t)->val > x)
            insertTree(&(*t)->left, x);
        else
            insertTree(&(*t)->right, x);
    }
}

int main()
{
    struct TreeNode *root = NULL;
    BSTIterator *st;
    int node[] = {7, 3, 15, 9, 20};
    int len = (sizeof(node) / sizeof(int));
    for (int i = 0; i < len; i++)
        insertTree(&root, node[i]);
    st = bSTIteratorCreate(root);
    printf("%d,", bSTIteratorNext(st));
    printf("%d,", bSTIteratorNext(st));
    // printf("%d,", bSTIteratorHasNext(&st));
    // printf("%d,", bSTIteratorNext(&st));
    // printf("%d,", bSTIteratorHasNext(&st));
    // printf("%d,", bSTIteratorNext(&st));
    // printf("%d,", bSTIteratorHasNext(&st));
    // printf("%d,", bSTIteratorNext(&st));
    // printf("%d,", bSTIteratorHasNext(&st));
    return 0;
}
