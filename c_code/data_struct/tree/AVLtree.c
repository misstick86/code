/*
@File    :   AVLtree.c
@Time    :   2020/02/23 17:26:27
@Author  :   xiaosongsong
@Desc    :   None


AVL 树代码实现

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct AVLNode
{
    int val;
    struct AVLNode *leftchirld;
    struct AVLNode *rightchirld;
    int bf;
} AVLNode;

// 定义栈

typedef struct AVLStack
{
    AVLNode *val;
    struct AVLStack *next;
} AVLStack;

// 初始化栈
void InitStack(AVLStack **st)
{
    *st = NULL;
}

// 判断栈是否为空

bool Empty(AVLStack **st)
{
    return *st == NULL;
}

// 入栈

void Push(AVLStack **st, AVLNode *p)
{
    AVLStack *new;
    new = (AVLStack *)malloc(sizeof(AVLStack));
    new->val = p;
    if (*st == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = (*st);
    }

    *st = new;
}

//出栈

void Pop(AVLStack **st)
{
    AVLStack *p;

    if (!Empty(&*st))
    {
        p = *st;
        (*st) = (*st)->next;
        free(p);
        p = NULL;
    }
}

void GetTopValue(AVLStack **st, AVLNode **p)
{
    if (!Empty(&*st))
    {
        (*p) = (*st)->val;
    }
}

// 调整平衡因子函数

void RotateL(AVLNode **ptr)
{
    AVLNode *subL = (*ptr);
    (*ptr) = subL->rightchirld;
    subL->rightchirld = (*ptr)->leftchirld;
    (*ptr)->leftchirld = subL;
    (*ptr)->bf = subL->bf = 0;
}
void RotateR(AVLNode **ptr)
{
    AVLNode *subR = (*ptr);
    *ptr = subR->leftchirld;
    subR->leftchirld = (*ptr)->rightchirld;
    (*ptr)->rightchirld = subR;
    (*ptr)->bf = subR->bf = 0;
}
void RotateRL(AVLNode **ptr)
{
    AVLNode *subL, *subR;
    subL = (*ptr);
    subR = subL->rightchirld;
    (*ptr) = subR->leftchirld;
    // 调整右树和平衡因子

    subR->leftchirld = (*ptr)->rightchirld;
    (*ptr)->rightchirld = subR;
    if ((*ptr)->bf >= 0)
        subR->bf = 0;
    else
        subR->bf = 1;

    // 调整左树和平衡因子

    subL->rightchirld = (*ptr)->leftchirld;
    (*ptr)->leftchirld = subL;
    if ((*ptr)->bf == 1)
        subL->bf = -1;
    else
        subL->bf = 0;
    (*ptr)->bf = 0;
}
void RotateLR(AVLNode **ptr)
{
    AVLNode *subR, *subL;
    subR = (*ptr);
    subL = subR->leftchirld;
    (*ptr) = subL->rightchirld;
    // 调整左树
    subL->rightchirld = (*ptr)->leftchirld;
    (*ptr)->leftchirld = subL;
    if ((*ptr)->bf <= 0)
        subL->bf = 0;
    else
        subL->bf = -1;

    // 调整右树
    subR->leftchirld = (*ptr)->rightchirld;
    (*ptr)->rightchirld = subR;
    if ((*ptr)->bf == -1)
        subR->bf = 1;
    else
        subR->bf = 0;
    (*ptr)->bf = 0;
}

AVLNode *CreateNode(int x)
{
    AVLNode *new;
    new = (AVLNode *)malloc(sizeof(AVLNode));
    new->val = x;
    new->leftchirld = new->rightchirld = NULL;
    new->bf = 0;
}

void InsertAVLNode(AVLNode **t, int x)
{

    AVLStack *st;
    InitStack(&st);
    AVLNode *p, *parent = NULL;
    p = *t;
    while (p != NULL)
    {
        parent = p;
        Push(&st, parent);
        if (p->val > x)
            p = p->leftchirld;
        else
        {
            p = p->rightchirld;
        }
    }
    p = CreateNode(x);
    if (parent == NULL)
    {
        *t = p;
        return;
    }
    else
    {
        if (parent->val > x)
            parent->leftchirld = p;
        else
            parent->rightchirld = p;
    }

    // 调整平衡因子
    while (!Empty(&st))
    {
        GetTopValue(&st, &parent);
        Pop(&st);
        if (parent->leftchirld == p)
            parent->bf--;
        else
            parent->bf++;

        if (parent->bf == 0)
            break;
        else if (parent->bf == 1 || parent->bf == -1)
            p = parent;
        else
        {
            // 实际调整平衡因子方法
            int flag = parent->bf < 0 ? -1 : 1;
            if (flag == p->bf) //说明是单旋转
            {
                if (flag == 1)
                    RotateL(&parent);
                else
                    RotateR(&parent);
            }
            else //说明是双旋转
            {
                if (flag == 1)
                    RotateRL(&parent);
                else
                    RotateLR(&parent);
            }
            break;
        }
    }
    if (Empty(&st))
    {
        *t = parent;
    }
    else
    {
        AVLNode *q;
        GetTopValue(&st, &q);
        if (q->val > parent->val)
            q->leftchirld = parent;
        else
            q->rightchirld = parent;
    }
}
int main()
{
    AVLNode *root = NULL;
    // int node[] = {13, 24, 20, 37, 90, 53};
    // int node[] = {10, 5, 8, 10, 25, 5};
    int node[] = {30, 20, 50, 10, 40, 70, 60, 80, 65};
    int count = sizeof(node) / sizeof(int);
    for (int i = 0; i < count; i++)
        InsertAVLNode(&root, node[i]);
    return 0;
}
