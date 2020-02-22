/*
@File    :   leetcode572.c
@Time    :   2020/02/22 10:39:23
@Author  :   xiaosongsong
@Desc    :   None

给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：

   4
  / \
 1   2

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 9)
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
TreeNode *createTree2(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 3)
    {
        return NULL;
    }
    else
    {
        new = (TreeNode *)malloc(sizeof(TreeNode));
        new->val = nodelist[i];
        new->left = createTree2(nodelist, 2 * i);
        new->right = createTree2(nodelist, 2 * i + 1);
        return new;
    }
}
bool isEquelTree(struct TreeNode *s, struct TreeNode *t)
{
    bool flag = true;
    if (s && t)
    {
        if (s->val != t->val)
            return false;
        flag = flag && isEquelTree(s->left, t->left);
        if (!flag)
            return flag;
        flag = flag && isEquelTree(s->right, t->right);
    }
    else if (s == NULL && t == NULL)
    {
        return true;
    }
    else
    {
        flag = false;
    }
    return flag;
}

bool isSubtree(struct TreeNode *s, struct TreeNode *t)
{
    if (s)
    {
        if (s->val == t->val)
        {
            if (isEquelTree(s, t))
                return true;
        }
        if (isSubtree(s->left, t))
            return true;
        return isSubtree(s->right, t);
    }
    else
    {
        return false;
    }
}

int main()
{
    TreeNode *root1, *root2;
    int node1[] = {0, 3, 4, 5, 4, 0, 0, 0, 1, 2};
    int node2[] = {0, 4, 1, 2};
    root1 = createTree(node1, 1);
    root2 = createTree2(node2, 1);
    printf("%d", isSubtree(root1, root2));
    return 0;
}
