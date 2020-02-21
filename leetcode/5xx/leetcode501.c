/*
@File    :   leetcode501.c
@Time    :   2020/02/21 16:04:29
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#include <malloc.h>
#define MaxSize 1024
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void insertNode(struct TreeNode **t, int x)
{
    if ((*t) == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else if ((*t)->val >= x)
    {
        insertNode(&(*t)->left, x);
    }
    else if ((*t)->val < x)
    {
        insertNode(&(*t)->right, x);
    }
}

void Inorder(struct TreeNode *root, int *node, int *i)
{
    if (root)
    {
        Inorder(root->left, node, i);
        node[(*i)++] = root->val;
        Inorder(root->right, node, i);
    }
}

int *findMode(struct TreeNode *root, int *returnSize)
{
    int *result;
    result = (int *)malloc(sizeof(int) * MaxSize);
    int node[MaxSize] = {};
    int *p;
    p = node;
    p++;
    int count = 0, i = 0, size = 1, MaxCount = 1;
    *returnSize = 0;
    if (root == NULL)
    {
        return result;
    }
    Inorder(root, node, &count);
    // 双指针找出出现最多元素。
    while (i < count)
    {
        size = 1;
        while (node[i] == *p)
        {
            if (i == count - 1)
                break;
            size++;
            p++;
            i++;
        }
        if (size > MaxCount)
        {
            *returnSize = 0;
            result[(*returnSize)++] = node[i];
            MaxCount = size;
        }
        else if (size == MaxCount)
        {
            result[(*returnSize)++] = node[i];
        }
        p++;
        i++;
    }
    return result;
}

int main()
{
    int size = 0, *p;
    struct TreeNode *root = NULL;
    int node[] = {0};
    for (int i = 0; i < 1; i++)
        insertNode(&root, node[i]);
    p = findMode(root, &size);
    for (int i = 0; i < size; i++)
        printf("%d,", p[i]);
    return 0;
}
