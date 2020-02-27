/*
@File    :   leetcode103.c
@Time    :   2020/02/27 18:26:38
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct StackNode
{
    struct TreeNode *val;
    int size;
    struct StackNode *next;
} StackNode;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

StackNode *InitQueue(StackNode *st)
{
    st = NULL;
    return st;
}

// 判断栈是否为空
bool Empty(StackNode *st)
{
    return st == NULL;
}

// 入栈
StackNode *Push(StackNode *st, struct TreeNode *x)
{
    StackNode *new;
    new = (StackNode *)malloc(sizeof(StackNode));
    new->val = x;
    if (st == NULL)
    {
        new->next = NULL;
        new->size = 1;
        return new;
    }
    else
    {
        new->next = st;
        new->size = st->size + 1;
        st = new;
        return st;
    }
}

// 出栈
StackNode *Pop(StackNode *st)
{
    StackNode *p;
    p = st;
    st = st->next;
    free(p);
    p = NULL;
    return st;
}

// 获取栈顶元素
void GetTopValue(StackNode *st, struct TreeNode **x)
{
    *x = st->val;
}

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

int GetTreeDepth(const struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = GetTreeDepth(root->left);
    int right = GetTreeDepth(root->right);

    return left > right ? left + 1 : right + 1;
}

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
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
        StackNode *st1, *st2;
        st1 = InitQueue(st1);
        st2 = InitQueue(st2);
        st1 = Push(st1, root);
        struct TreeNode *p;
        while (*returnSize < depth)
        {

            int i = 0;
            if (st1)
            {
                size = st1->size;
                returnColumnSizes[0][*returnSize] = size;
                result[(*returnSize)++] = (int *)malloc(sizeof(int) * size);
                while (!Empty(st1))
                {
                    GetTopValue(st1, &p);
                    st1 = Pop(st1);
                    result[(*returnSize) - 1][i++] = p->val;
                    if (p->left)
                        st2 = Push(st2, p->left);
                    if (p->right)
                        st2 = Push(st2, p->right);
                }
            }
            i = 0;
            if (st2)
            {
                size = st2->size;
                returnColumnSizes[0][*returnSize] = size;
                result[(*returnSize)++] = (int *)malloc(sizeof(int) * size);
                while (!Empty(st2))
                {
                    GetTopValue(st2, &p);
                    st2 = Pop(st2);
                    result[(*returnSize) - 1][i++] = p->val;
                    if (p->right)
                        st1 = Push(st1, p->right);
                    if (p->left)
                        st1 = Push(st1, p->left);
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
    int a[] = {0, 3, 9, 20, 1, 6, 15, 7};
    struct TreeNode *root;
    root = createTree(a, 1);
    zigzagLevelOrder(root, &size, &p);
    return 0;
}
