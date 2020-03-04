/*
@File    :   leetcode236.c
@Time    :   2020/03/04 09:16:01
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]



 

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createBtTree(int *nodelist, int i)
{
    struct TreeNode *newnode;
    if (nodelist[i] == -1 || i > 11)
        return NULL;
    else
    {
        newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        newnode->val = nodelist[i];
        newnode->left = createBtTree(nodelist, 2 * i);
        newnode->right = createBtTree(nodelist, 2 * i + 1);
        return newnode;
    }
}
struct TreeNode *searchNode(struct TreeNode *root, int x)
{
    struct TreeNode *q = NULL;
    if (root)
    {
        if (root->val == x)
            return root;
        q = searchNode(root->left, x);
        if (q)
            return q;
        return searchNode(root->right, x);
    }
    return NULL;
}

bool isSearch(struct TreeNode *root, struct TreeNode *s)
{
    bool flag = false;
    if (root)
    {
        if (root == s)
            return true;
        flag = flag || isSearch(root->left, s);
        if (flag)
            return flag;
        return isSearch(root->right, s);
    }
    return flag;
}
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    struct TreeNode *s;
    if (root)
    {
        s = lowestCommonAncestor(root->left, p, q);
        if (s)
            return s;
        if (root == p)
        {
            if (isSearch(root, q))
                return root;
        }
        if (root == q)
        {
            if (isSearch(root, p))
                return root;
        }

        s = lowestCommonAncestor(root->right, p, q);
        if (s)
            return s;
        if (isSearch(root, p) && isSearch(root, q))
            return root;
    }
    return NULL;
}
int main()
{
    struct TreeNode *root, *p, *q, *s;
    int node[] = {0, 3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    root = createBtTree(node, 1);
    p = searchNode(root, 1);
    q = searchNode(root, 1);
    s = lowestCommonAncestor(root, q, p);
    return 0;
}
