/*
@File    :   pretree.c
@Time    :   2020/02/10 17:22:27
@Author  :   xiaosongsong
@Desc    :   None
根据前中序创建二叉树
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct TreeNode
{
    char val;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

void createTree(TreeNode **t, char *VLR, char *LVR, int n)
{
    if (n == 0)
    {
        t = NULL;
    }
    else
    {
        int k = 0;
        while (VLR[0] != LVR[k])
        {
            k++;
        }
        *t = (TreeNode *)malloc(sizeof(TreeNode));
        (*t)->val = LVR[k];
        createTree(&(*t)->lchild, VLR + 1, LVR, k);
        createTree(&(*t)->rchild, VLR + k + 1, LVR + k + 1, n - k - 1);
    }
}

int main()
{
    TreeNode *root;
    char *VLR = "ABCDEFGH";
    char *LVR = "CBEDFAGH";
    int length = strlen(VLR);
    createTree(&root, VLR, LVR, length);
    printf("av");
    return 0;
}
