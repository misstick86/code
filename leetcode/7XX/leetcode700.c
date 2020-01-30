/*
@File    :   leetcode700.c
@Time    :   2020/01/30 11:19:54
@Author  :   xiaosongsong
@Desc    :   None

给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

例如，

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2
你应该返回如下子树:

      2
     / \
    1   3
在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。
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
BintreeNode *searchBST(BintreeNode *root, char val)
{

    // printf("root is: %c\n", root->val);
    if (root == NULL)
        return NULL;
    if (root->val == val)
    {
        return root;
    }
    BintreeNode *p = searchBST(root->lchild, val);
    if (p != NULL)
    {
        return p;
    }
    return searchBST(root->rchild, val);
}
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
int main()
{
    Bintree mytree;
    InitBinTree(&mytree, '#');
    CreateBinTreeApi(&mytree);

    printf("preorder: ");
    PreOrderTree(mytree.root);
    printf("\n");
    BintreeNode *p = searchBST(mytree.root, '2');
    printf("%c", p->val);
    return 0;
}
