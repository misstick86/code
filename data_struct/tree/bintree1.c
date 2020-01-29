/*
@File    :   bintree.c
@Time    :   2020/01/29 09:40:36
@Author  :   xiaosongsong
@Desc    :   None
二叉树创建
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct BintreeNode
{
    char val;
    struct BintreeNode *lchild;
    struct BintreeNode *rchild;
} BintreeNode;

typedef struct Bintree
{
    BintreeNode *root;
    char refvalue;
} Bintree;

// 初始化树
void InitBinTree(Bintree *bt, char ref)
{
    bt->root = NULL;
    bt->refvalue = ref;
}

// 创建二叉树

void CreateBinTree(Bintree *bt, BintreeNode **t)
{
    char item;
    scanf("%c", &item);
    if (item == bt->refvalue)
    {
        (*t) = NULL;
    }
    else
    {
        (*t) = (BintreeNode *)malloc(sizeof(BintreeNode));
        assert((*t) != NULL);
        (*t)->val = item;
        CreateBinTree(bt, &((*t)->lchild));
        CreateBinTree(bt, &((*t)->rchild));
    }
}
void CreateBinTreeApi(Bintree *bt)
{
    CreateBinTree(bt, &(bt->root));
}

// 二叉树前中后序遍历

// 先序
void PreOrderTree(BintreeNode *t)
{
    if (t != NULL)
    {
        printf("%c", t->val);
        PreOrderTree(t->lchild);
        PreOrderTree(t->rchild);
    }
}

//中序
void InOrderTree(BintreeNode *t)
{
    if (t != NULL)
    {
        InOrderTree(t->lchild);
        printf("%c", t->val);
        InOrderTree(t->rchild);
    }
}

// 后序

void PostOrderTree(BintreeNode *t)
{
    if (t != NULL)
    {
        PostOrderTree(t->lchild);
        PostOrderTree(t->rchild);
        printf("%c", t->val);
    }
}

// 销毁二叉树

// 清空二叉树

// 判断二叉树是否为空

int main()
{
    Bintree mytree;
    InitBinTree(&mytree, '#');
    CreateBinTreeApi(&mytree);
    printf("preorder: ");
    PreOrderTree(mytree.root);
    printf("\n");
    printf("inorder: ");
    InOrderTree(mytree.root);
    printf("\n");
    printf("PostOrder: ");
    PostOrderTree(mytree.root);
    printf("\n");
    return 0;
}
