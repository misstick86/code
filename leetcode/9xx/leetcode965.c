/*
@File    :   leetcode965.c
@Time    :   2020/01/30 20:12:44
@Author  :   xiaosongsong
@Desc    :   None

如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。

示例 1：

输入：[1,1,1,1,1,null,1]
输出：true
示例 2：



输入：[2,2,2,5,2]
输出：false

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void createTree(struct TreeNode *bt, int *node)
{
    while (*node)
    {

        bt->val = *node;
        node++;
    }
}
bool isUnivalTree(struct TreeNode *root)
{
}
int main()
{
    struct TreeNode mytree;
    int a[] = {1, 1, 1, 1, 1, NULL, 1};
    createTree(&mytree, a);
    return 0;
}
