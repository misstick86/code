/*
@File    :   leetcode1325.c
@Time    :   2020/02/29 21:35:17
@Author  :   xiaosongsong
@Desc    :   None

给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。

注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。

也就是说，你需要重复此过程直到不能继续删除。

 

示例 1：



输入：root = [1,2,3,2,null,2,4], target = 2
输出：[1,null,3,null,4]
解释：
上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
示例 2：



输入：root = [1,3,3,3,2], target = 3
输出：[1,3,null,null,2]
示例 3：



输入：root = [1,2,null,2,null,2], target = 2
输出：[1]
解释：每一步都删除一个绿色的叶子节点（值为 2）。
示例 4：

输入：root = [1,1,1], target = 1
输出：[]
示例 5：

输入：root = [1,2,3], target = 1
输出：[1,2,3]

*/

#include <stdio.h>
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

void RemoveNode(struct TreeNode **root, int target)
{
    if ((*root) && (*root)->left)
        RemoveNode(&(*root)->left, target);
    if ((*root) && (*root)->right)
        RemoveNode(&(*root)->right, target);
    if ((*root)->val == target && (*root)->left == NULL && (*root)->right == NULL)
        (*root) = NULL;
}

struct TreeNode *removeLeafNodes(struct TreeNode *root, int target)
{
    RemoveNode(&root, target);
    return root;
}
int main()
{
    TreeNode *root;
    int node[] = {0, 1, 2, 3, 2, 0, 2, 4};
    root = createBtTree(node, 1);
    removeLeafNodes(root, 2);
    return 0;
}
