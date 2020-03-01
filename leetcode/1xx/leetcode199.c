/*
@File    :   leetcode199.c
@Time    :   2020/02/28 20:51:31
@Author  :   xiaosongsong
@Desc    :   None

给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MaxSize 1024
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

typedef struct TreeQueue
{
    struct TreeNode *val[MaxSize];
    int first;
    int last;
} TreeQueue;
bool Empty(TreeQueue *q)
{
    return q->first == q->last;
}
bool Full(TreeQueue *q)
{
    return q->first > MaxSize;
}
void initQueue(TreeQueue *q)
{
    q->first = q->last = 0;
}
void PushQueue(TreeQueue *q, struct TreeNode *x)
{
    if (!Full(q))
    {
        q->val[q->first++] = x;
    }
}
void PopQueue(TreeQueue *q, struct TreeNode **x)
{
    if (!Empty(q))
    {
        *x = q->val[q->last++];
    }
}

int getDepth(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root)
    {
        left = getDepth(root->left) + 1;
        right = getDepth(root->right) + 1;
    }
    return left > right ? left : right;
}
int *rightSideView(struct TreeNode *root, int *returnSize)
{
    struct TreeNode *p;
    TreeQueue queue;
    int *result;
    int size = 0, depth = 0;
    depth = getDepth(root);
    result = (int *)malloc(sizeof(int) * depth);
    *returnSize = 0;
    initQueue(&queue);
    PushQueue(&queue, root);
    if (root == NULL)
        return result;
    while (!Empty(&queue))
    {
        size = queue.first - queue.last;
        while (size--)
        {
            PopQueue(&queue, &p);
            if (p->left)
                PushQueue(&queue, p->left);
            if (p->right)
                PushQueue(&queue, p->right);
        }
        result[(*returnSize)++] = p->val;
    }
    return result;
}
int main()
{
    int size = 0;
    TreeNode *root;
    int a[] = {0, 1, 2, 3, 0, 5, 0, 4};
    root = createBtTree(a, 1);
    rightSideView(root, &size);
    return 0;
}
