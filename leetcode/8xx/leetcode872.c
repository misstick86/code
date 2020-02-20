/*
@File    :   leetcode872.c
@Time    :   2020/02/20 10:04:57
@Author  :   xiaosongsong
@Desc    :   None

请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。



举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。

如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

 

提示：

给定的两颗树可能会有 1 到 100 个结点。

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
TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *newnode;
    if (nodelist[i] == 0 || i > 11)
        return NULL;
    else
    {
        newnode = (TreeNode *)malloc(sizeof(TreeNode));
        newnode->val = nodelist[i];
        newnode->left = createTree(nodelist, 2 * i);
        newnode->right = createTree(nodelist, 2 * i + 1);
        return newnode;
    }
}
void getLeafNode(struct TreeNode *root, int *p, int *i)
{
    if (root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            p[*i] = root->val;
            (*i) += 1;
        }
        else
        {
            getLeafNode(root->left, p, i);
            getLeafNode(root->right, p, i);
        }
    }
}
bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    bool flag = true;
    int a = 0, b = 0;
    int p1[100] = {}, p2[100] = {};
    getLeafNode(root1, p1, &a);
    getLeafNode(root2, p2, &b);
    if (a != b)
    {
        flag = false;
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            if (p1[i] != p2[i])
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}
int main()
{
    struct TreeNode *root1;
    struct TreeNode *root2;
    int a[] = {0, 3, 5, 1, 6, 2, 9, 8, 0, 0, 7, 4};
    int b[] = {0, 3, 5, 1, 6, 2, 9, 8, 0, 0, 7, 3};
    root1 = createTree(a, 1);
    root2 = createTree(b, 1);
    printf("%d", leafSimilar(root1, root2));
    return 0;
}
