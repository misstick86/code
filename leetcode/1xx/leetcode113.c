/*
@File    :   leetcode113.c
@Time    :   2020/02/28 10:59:04
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef enum
{
    L,
    R
} Tag;
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct TreeNodeTag
{
    struct TreeNode *ptr;
    Tag tag;
} TreeNodeTag;

typedef struct TreeStack
{
    TreeNodeTag val;
    struct TreeStack *next;
} TreeStack;
TreeNode *createTree(int *nodelist, int i)
{
    TreeNode *new;
    if (nodelist[i] == 0 || i > 15)
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
TreeStack *initStack(TreeStack *p)
{
    p = NULL;
    return p;
}
bool Empty(TreeStack *p)
{
    return p == NULL;
}

TreeStack *Push(TreeStack *st, TreeNodeTag val)
{
    TreeStack *new;
    new = (TreeStack *)malloc(sizeof(TreeStack));
    new->val = val;
    if (st == NULL)
    {
        new->next = NULL;
        return new;
    }
    else
    {
        new->next = st;
        st = new;
        return st;
    }
}
TreeStack *Pop(TreeStack *st)
{
    TreeStack *p;
    p = st;
    st = st->next;
    free(p);
    p = NULL;
    return st;
}

void getTopValue(TreeStack *st, TreeNodeTag *val)
{
    *val = st->val;
}
int **pathSum(struct TreeNode *root, int sum, int *returnSize, int **returnColumnSizes)
{
    int **result;
    *returnSize = 0;
    result = (int **)malloc(sizeof(int *) * 1024);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * 1024);
    if (root)
    {
        TreeNodeTag nodetag, p;
        int temp[1024] = {};
        TreeStack *st;
        st = initStack(st);
        int i = 0;
        do
        {
            while (root)
            {
                nodetag.ptr = root;
                nodetag.tag = L;
                st = Push(st, nodetag);
                temp[i++] = root->val;
                sum -= root->val;
                root = root->left;
            }
            getTopValue(st, &p);
            st = Pop(st);
            switch (p.tag)
            {
            case L:
                p.tag = R;
                st = Push(st, p);
                root = p.ptr->right;
                break;
            case R:
                /* code */
                if (p.ptr->left == NULL && p.ptr->right == NULL && sum == 0)
                {
                    result[(*returnSize)++] = (int *)malloc(sizeof(int) * i);
                    returnColumnSizes[0][(*returnSize) - 1] = i;
                    for (int j = 0; j < i; j++)
                        result[(*returnSize) - 1][j] = temp[j];
                }
                sum += p.ptr->val;
                i--;
                break;

            default:
                break;
            }

        } while (!Empty(st));
    }
    for (int i = 0; i < 3; i++)
    {
        /* code */
        printf("%d,", returnColumnSizes[0][i]);
    }

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d,", result[i][j]);
    //     }
    //     printf("\n");
    // }

    return result;
}
int main()
{
    int size = 0, *p;
    struct TreeNode *root;
    int node[] = {0, 5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 0, 0, 5, 1};
    root = createTree(node, 1);
    pathSum(root, 22, &size, &p);
    return 0;
}
