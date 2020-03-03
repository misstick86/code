/*
@File    :   leetcode114.c
@Time    :   2020/03/03 20:53:13
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

*/

#include <stdio.h>
#include <malloc.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 6)
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
void switchRoot(struct TreeNode **root)
{
    if ((*root))
    {
        struct TreeNode *p;
        p = (*root)->left;
        if (p)

        {
            while (p->right)
            {
                p = p->right;
            }
            p->right = (*root)->right;
            (*root)->right = (*root)->left;
            (*root)->left = NULL;
        }
        switchRoot(&(*root)->right);
    }
}
void flatten(struct TreeNode *root)
{
    switchRoot(&root);
}
int main()
{
    struct TreeNode *root;
    int node[] = {0, 1, 0, 2, 0, 0, 3};
    root = createTree(node, 1);
    flatten(root);
    return 0;
}
