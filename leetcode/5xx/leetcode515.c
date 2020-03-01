/*
@File    :   leetcode515.c
@Time    :   2020/03/01 10:00:22
@Author  :   xiaosongsong
@Desc    :   None
您需要在二叉树的每一行中找到最大的值。

示例：

输入:

          1
         / \
        3   2
       / \   \
      5   3   9

输出: [1, 3, 9]


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
TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 7)
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

int getMinValue(int *p, int count)
{
    int max = p[0];
    for (int i = 1; i < count; i++)
    {
        if (max < p[i])
            max = p[i];
    }
    return max;
}

int *largestValues(struct TreeNode *root, int *returnSize)
{
    struct TreeNode *p;
    TreeQueue queue;
    int *result, *layernode = NULL;
    int size = 0, depth = 0, count;
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
        count = size;
        layernode = (int *)malloc(sizeof(int) * size);
        while (size--)
        {
            PopQueue(&queue, &p);
            layernode[size] = p->val;
            if (p->left)
                PushQueue(&queue, p->left);
            if (p->right)
                PushQueue(&queue, p->right);
        }
        result[(*returnSize)++] = getMinValue(layernode, count);
    }
    return result;
}
int main()
{
    struct TreeNode *root;
    int size = 0;
    int node[] = {0, 1, 3, 2, 5, 3, 0, 9};
    root = createTree(node, 1);
    largestValues(root, &size);
    return 0;
}
