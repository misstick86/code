/*
@File    :   leetcode257.c
@Time    :   2020/02/21 18:11:14
@Author  :   xiaosongsong
@Desc    :   None
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
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
    if (nodelist[i] == 0 || i > 8)
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

char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    char **result;
    int i = 0;
    int *re;
    re = (int *)malloc(sizeof(int *) * 1024);
    result = (char **)malloc(sizeof(char *) * 1024);
    TreeNodeTag treetag, p;
    TreeStack *st;
    st = initStack(st);
    do
    {
        while (root)
        {
            treetag.ptr = root;
            treetag.tag = L;
            st = Push(st, treetag);
            re[i++] = root->val;
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
            if (p.ptr->left == NULL && p.ptr->right == NULL)
            {
                int count = 0;
                // printf("%d,", p.ptr->val);
                result[*returnSize] = (char *)malloc(sizeof(char) * (1024));
                char temp[1024];
                for (int j = 0; j < i; j++)
                {
                    sprintf(temp, "%d->", re[j]);
                    printf("%s\n", temp);
                    for (int k = 0; temp[k] != '>'; k++)
                        result[(*returnSize)][count++] = temp[k];
                    // strcat(result[*returnSize], temp);
                    result[(*returnSize)][count++] = '>';
                }
                result[(*returnSize)++][count - 2] = '\0';
            }
            i--;
            break;

        default:
            break;
        }

    } while (!Empty(st));

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%s\n", result[i]);
    // }

    return result;
}
int main()
{
    int size = 0;
    TreeNode *root;
    int node[] = {0, 37, -34, -48, 0, -100, -100, 48};
    root = createTree(node, 1);
    binaryTreePaths(root, &size);
    return 0;
}
