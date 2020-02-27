/*
@File    :   leetcode102.c
@Time    :   2020/02/13 15:30:09
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MaxSize 1024

typedef struct QueueNode
{
    struct TreeNode *val[MaxSize];
    int first;
    int last;
} QueueNode;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void InitQueue(QueueNode *q)
{
    q->first = q->last = 0;
}

// 入队
void PushQ(QueueNode *q, struct TreeNode *x)
{
    if (q->last < MaxSize)
    {
        q->val[q->last] = x;
        q->last++;
    }
    else
    {
        printf("队满");
    }
}

// 出队
void PopQ(QueueNode *q)
{
    q->first++;
}
bool Empty(QueueNode *q)
{
    return q->first == q->last;
}
// 获取对头元素
struct TreeNode *GetQueueValue(QueueNode *q)
{
    struct TreeNode *x;
    if (q->first < q->last)
    {
        x = q->val[q->first];
    }
    return x;
}

struct TreeNode *createTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 9)
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

int GetTreeDepth(const struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = GetTreeDepth(root->left);
    int right = GetTreeDepth(root->right);

    return left > right ? left + 1 : right + 1;
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    // returnSize 为总共有多少行数据， 也就是数据的最大深度，
    // returnColumnSizes 为每行中数据的个数,也就是树的每一层有多少个。
    int **result; //返回结果
    int depth;    //树的最大深度
    // 获取树的最大深度
    depth = GetTreeDepth(root);
    *returnSize = 0;
    result = (int **)malloc(sizeof(int *) * depth);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * depth);
    if (root != NULL)
    {
        int size = 0;
        struct TreeNode *p;
        QueueNode queue;
        InitQueue(&queue);
        PushQ(&queue, root);
        while (!Empty(&queue))
        {
            int i = 0;
            size = queue.last - queue.first;
            returnColumnSizes[0][*returnSize] = size;
            result[(*returnSize)++] = (int *)malloc(sizeof(int) * size);
            while (size--)
            {
                p = GetQueueValue(&queue);
                PopQ(&queue);
                result[(*returnSize) - 1][i++] = p->val;
                if (p->left)
                    PushQ(&queue, p->left);
                if (p->right)
                {
                    PushQ(&queue, p->right);
                }
            }
        }
    }
    else
    {
        *returnSize = 0;
    }
    return result;
}
int main()
{
    int *p = NULL;
    int size;
    int a[] = {0, 3, 9, 20, 0, 0, 15, 7};
    struct TreeNode *root;
    root = createTree(a, 1);
    levelOrder(root, &size, &p);
    return 0;
}
