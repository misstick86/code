/*
@File    :   leetcode951.c
@Time    :   2020/03/04 17:54:03
@Author  :   xiaosongsong
@Desc    :   None
我们可以为二叉树 T 定义一个翻转操作，如下所示：选择任意节点，然后交换它的左子树和右子树。

只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转等价于二叉树 Y。

编写一个判断两个二叉树是否是翻转等价的函数。这些树由根节点 root1 和 root2 给出。

 

示例：

输入：root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
输出：true
解释：We flipped at nodes with values 1, 3, and 5.


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
TreeNode *createTree(int *nodelist, int i, int count)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > count)
    {
        return NULL;
    }
    else
    {
        new = (TreeNode *)malloc(sizeof(TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i, count);
        new->right = createTree(nodelist, 2 * i + 1, count);
        return new;
    }
}
bool flipEquiv(struct TreeNode *root1, struct TreeNode *root2)
{
    struct TreeNode *temp;
    bool flag = true;

    if (root2 && root1)
    {
        if (root1->val != root2->val)
            return false;
        if (root1->left && root2->left)
        {
            if (root1->left->val != root2->left->val)
            {
                temp = root1->right;
                root1->right = root1->left;
                root1->left = temp;
            }
        }
        if (root1->left == NULL && root2->left != NULL || root1->left != NULL && root2->left == NULL)
        {
            temp = root1->right;
            root1->right = root1->left;
            root1->left = temp;
        }

        flag = flag && flipEquiv(root1->left, root2->left);
        flag = flag && flipEquiv(root1->right, root2->right);
        return flag;
    }
    if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
        return false;
    return flag;
}
int main()
{
    struct TreeNode *root1, *root2;
    int node1[] = {0, 1, 2, 3, 4, 5, 6, 0, 0, 0, 7, 8};
    int node2[] = {0, 1, 3, 2, 0, 6, 4, 5, 0, 0, 0, 0, 0, 0, 8, 7};
    root1 = createTree(node1, 1, sizeof(node1) / sizeof(int) - 1);
    root2 = createTree(node2, 1, sizeof(node2) / sizeof(int) - 1);
    printf("%d", flipEquiv(root1, root2));
    return 0;
}
