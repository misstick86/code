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
    if (!Empty(st))
    {
        st->val[--st->top] = NULL;
    }
}

// 获取栈顶元素
void getTopValue(BSTIterator *st, struct TreeNode **p)
{
    *p = st->val[st->top - 1];
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{

    BSTIterator *st;
    st = (BSTIterator *)malloc(sizeof(BSTIterator));
    initStack(st);
    while (root)
    {
        Push(st, root);
        root = root->left;
    }
    return st;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator *obj)
{
    struct TreeNode *p;
    getTopValue(obj, &p);
    struct TreeNode *q;
    q = p->right;
    Pop(obj);
    if (p->right)
        Push(obj, p->right);
    q = p->right;
    while (q && q->left)
    {
        Push(obj, q->left);
        q = q->left;
    }
    return p->val;
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
    free(obj->val);
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
    BSTIterator *p;
    int node[] = {7, 3, 15, 9, 20};
    int len = (sizeof(node) / sizeof(int));
    for (int i = 0; i < len; i++)
        insertTree(&root, node[i]);
    p = bSTIteratorCreate(root);
    printf("%d,", bSTIteratorNext(p));
    printf("%d,", bSTIteratorNext(p));
    printf("%d,", bSTIteratorHasNext(p));
    printf("%d,", bSTIteratorNext(p));
    printf("%d,", bSTIteratorHasNext(p));
    printf("%d,", bSTIteratorNext(p));
    printf("%d,", bSTIteratorHasNext(p));
    printf("%d,", bSTIteratorNext(p));
    printf("%d,", bSTIteratorHasNext(p));
    return 0;
}
