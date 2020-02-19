/*
@File    :   leetcode993.c
@Time    :   2020/02/19 11:46:23
@Author  :   xiaosongsong
@Desc    :   None
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。

 

示例 1：
                    1
                2       3
            4


输入：root = [1,2,3,4], x = 4, y = 3
输出：false
示例 2：
                1
            2       3
              4       5

输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
输出：true
示例 3：

            1
        2       3
          4         5

输入：root = [1,2,3,null,4], x = 2, y = 3
输出：false

*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode *createBtTree(int *nodelist, int i)
{
    TreeNode *newnode;
    if (nodelist[i] == 0 || i > 7)
        return NULL;
    else
    {
        newnode = (TreeNode *)malloc(sizeof(TreeNode));
        newnode->val = nodelist[i];
        newnode->left = createBtTree(nodelist, 2 * i);
        newnode->right = createBtTree(nodelist, 2 * i + 1);
        return newnode;
    }
}

bool search(struct TreeNode *root, struct TreeNode **p, int x, int depth, int *pdepth)
{
    bool ret = false;
    if (root != NULL)
    {
        if (*p == NULL)
        {
            if (root->left && root->left->val == x || root->right && root->right->val == x)
            {
                *p = root;
                *pdepth = depth + 1;
                return true;
            }
            if (root->left)
                ret = search(root->left, &*p, x, depth + 1, pdepth);
            if (ret)
                return ret;
            if (root->right)
            {
                ret = search(root->right, &*p, x, depth + 1, pdepth);
            }
            return ret;
        }
    }
    else
    {
        return false;
    }
}

bool isCousins(struct TreeNode *root, int x, int y)
{

    struct TreeNode *parentx = NULL, *parenty = NULL;
    int highx = 0, highy = 0;
    bool retx, rety;
    retx = search(root, &parentx, x, 0, &highx);
    rety = search(root, &parenty, y, 0, &highy);
    if (parenty != parentx && retx && rety && highy == highx)
    {
        return true;
    }
    return false;
}
int main()
{
    TreeNode *root;
    int node[] = {0, 1, 2, 3, 0, 4, 0, 5};
    root = createBtTree(node, 1);
    printf("%d", isCousins(root, 2, 3));
    return 0;
}
