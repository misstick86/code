/*
@File    :   leetcode1261.c
@Time    :   2020/03/23 20:15:53
@Author  :   xiaosongsong
@Desc    :   None
给出一个满足下述规则的二叉树：

root.val == 0
如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 1
如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x + 2
现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 -1。

请你先还原二叉树，然后实现 FindElements 类：

FindElements(TreeNode* root) 用受污染的二叉树初始化对象，你需要先把它还原。
bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。
 

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

struct TreeNode *createTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 5)
    {
        return NULL;
    }
    else
    {
        new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i);
        new->right = createTree(nodelist, 2 * i + 1);
        return new;
    }
}
typedef struct TreeNode FindElements;

FindElements *createElements(struct TreeNode *root, int i)
{
    FindElements *new;
    if (root)
    {
        new = (FindElements *)malloc(sizeof(FindElements));
        new->val = i;
        new->left = createElements(root->left, 2 * i + 1);
        new->right = createElements(root->right, 2 * i + 2);
        return new;
    }
    return NULL;
}
FindElements *findElementsCreate(struct TreeNode *root)
{
    FindElements *ele;
    ele = createElements(root, 0);
    return ele;
}

bool findElementsFind(FindElements *obj, int target)
{
    bool flag = false;
    if (obj)
    {
        if (obj->val == target)
        {
            return true;
        }
        else
        {
            flag = findElementsFind(obj->left, target);
            if (flag)
                return flag;
            return findElementsFind(obj->right, target);
        }
    }
    return flag;
}

void findElementsFree(FindElements *obj)
{
    if (obj)
    {
        findElementsFree(obj->right);
        findElementsFree(obj->left);
        free(obj);
        obj = NULL;
    }
}

int main()
{
    FindElements *p;
    struct TreeNode *root;
    int node[] = {0, -1, -1, -1, -1, -1};
    root = createTree(node, 1);
    p = findElementsCreate(root);
    printf("%d", findElementsFind(p, 2));
    return 0;
}
