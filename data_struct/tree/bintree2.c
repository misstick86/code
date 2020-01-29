/*
@File    :   bintree2.c
@Time    :   2020/01/29 17:04:00
@Author  :   xiaosongsong
@Desc    :   None
二叉树的创建， 返回树节点的方式
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

BintreeNode *CreateBinTree(Bintree *bt, char *str, int i)
{
    printf("%d", i);
    if (str[i] == bt->refvalue)
    {
        return NULL;
    }
    else
    {
        BintreeNode *t = (BintreeNode *)malloc(sizeof(BintreeNode));
        assert(t != NULL);
        t->val = str[i];
        t->lchild = CreateBinTree(bt, str, ++i);
        t->rchild = CreateBinTree(bt, str, ++i);
        return t;
    }
}

void CreateBinTreeApi(Bintree *bt, char *str)
{
    int i = 0;
    bt->root = CreateBinTree(bt, str, i);
}

int main()
{
    Bintree tree;
    char str[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#', '#', 'F', '#', '#', 'G', '#', 'H', '#', '#'};
    InitBinTree(&tree, '#');
    CreateBinTreeApi(&tree, str);
    printf("avc");
    return 0;
}
