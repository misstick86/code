/*
@File    :   leetcode437.c
@Time    :   2020/02/15 11:18:10
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *CreateTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 11)
    {
        return NULL;
    }
    else
    {
        new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new->val = nodelist[i];
        new->left = CreateTree(nodelist, 2 * i);
        new->right = CreateTree(nodelist, 2 * i + 1);
        return new;
    }
}

// 判断当前节点有几个

int pathSum(struct TreeNode *root, int sum)
{
    int result = 0;
    result += sumNode(root, sum);
    result += sumNode(root->left, sum);
    result += sumNode(root->right, sum);
    return result;
}
int main()
{
    struct TreeNode *root;
    int a[] = {0, 10, 5, -3, 3, 2, 0, 11, 3, -2, 0, 1};
    root = CreateTree(a, 1);
    printf("%d", pathSum(root, 8));
    return 0;
}
