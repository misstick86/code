/*
@File    :   leetcode107.c
@Time    :   2020/02/27 10:48:08
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MaxSize 1024
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 7)
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

typedef struct NodeQueue
{
    struct TreeNode *node[MaxSize];
    int first;
    int last;
} NodeQueue;

// 初始化队列
void InitQueue(NodeQueue *q)
{
    q->first = q->last = 0;
}

// 判断队列是否为空
bool Empty(NodeQueue *q)
{
    return q->first == q->last;
}
//  入队
NodeQueue *Push(NodeQueue *q, struct TreeNode *x)
{
    q->node[q->first++] = x;
    return q;
}
// 出队
NodeQueue *Pop(NodeQueue *q, struct TreeNode **x)
{
    if (!Empty(q))
    {
        *x = q->node[q->last++];
    }
    return q;
}
int getMaxDepth(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        left = getMaxDepth(root->left) + 1;
        right = getMaxDepth(root->right) + 1;
        return left > right ? left : right;
    }
}
int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    int depth = getMaxDepth(root);
    *returnSize = depth;
    int **result;
    int size = 0;
    struct TreeNode *p;
    NodeQueue queue;
    if (root == NULL)
    {
        return result;
    }
    result = (int **)malloc(sizeof(int *) * depth);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * depth);
    InitQueue(&queue);
    Push(&queue, root);

    while (!Empty(&queue))
    {
        int i = 0;
        size = queue.first - queue.last;
        returnColumnSizes[0][--depth] = size;
        result[depth] = (int *)malloc(sizeof(int) * size);
        while (size--)
        {
            Pop(&queue, &p);
            result[depth][size] = p->val;
            if (p->right)
                Push(&queue, p->right);
            if (p->left)
                Push(&queue, p->left);
        }
    }
    return result;
}
int main()
{
    int size = 0, *p = NULL;
    struct TreeNode *root;
    int node[] = {0, 3, 9, 20, 0, 0, 15, 7};
    root = createTree(node, 1);
    levelOrderBottom(root, &size, &p);
    return 0;
}
