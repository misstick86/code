/*
@File    :   leetcode637.c
@Time    :   2020/02/19 11:02:35
@Author  :   xiaosongsong
@Desc    :   None


给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.

示例 1:

输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
注意：

节点值的范围在32位有符号整数范围内。

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MaxSize 20480
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeQueue
{
    struct TreeNode *val[MaxSize];
    int head;
    int tail;
} TreeQueue;

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

// 初始化队列
void initQueue(TreeQueue *q)
{
    q->tail = 0;
    q->head = 0;
}

//  判断队是否为空
bool Empty(TreeQueue *q)
{
    return q->tail == q->head;
}

bool IsFull(TreeQueue *q)
{
    return q->tail == MaxSize;
}
// 入队
void Push(TreeQueue *q, struct TreeNode *p)
{
    if (!IsFull(q))
        q->val[q->tail++] = p;
}

// 出队
void Pop(TreeQueue *q, struct TreeNode **p)
{
    if (!Empty(q))
        *p = q->val[q->head++];
}

double *averageOfLevels(struct TreeNode *root, int *returnSize)
{
    int size = 0, count = 0;
    double sum = 0.0;
    double *result;
    result = (double *)malloc(sizeof(double) * MaxSize);
    struct TreeNode *p;
    TreeQueue queue;
    initQueue(&queue);
    if (root == NULL)
    {
        *returnSize = 0;
    }
    else
    {
        // 此时入栈的是根元素
        Push(&queue, root);
    }
    *returnSize = 0;
    while (!Empty(&queue))
    {
        size = queue.tail - queue.head;
        count = size;
        sum = 0.0;
        while (size)
        {
            Pop(&queue, &p);
            sum += p->val;
            printf("%d,", p->val);
            if (p->left)
                Push(&queue, p->left);
            if (p->right)
                Push(&queue, p->right);
            size--;
        }
        result[(*returnSize)++] = sum / count;
    }
    return result;
}
int main()
{
    int size = 0;
    struct TreeNode *root;
    int node[] = {0, 3, 9, 20, 0, 0, 15, 7};
    root = createTree(node, 1);
    averageOfLevels(root, &size);
    return 0;
}
