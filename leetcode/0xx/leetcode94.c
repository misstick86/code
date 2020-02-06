/*
@File    :   leetcode94.c
@Time    :   2020/01/30 10:48:27
@Author  :   xiaosongsong
@Desc    :   None
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct TreeNodeStack
{
    struct TreeNode *val;
    struct TreeNodeStack *next;
} TreeNodeStack;

TreeNodeStack *InitTreeNodeStack()
{
    TreeNodeStack *stack;
    stack = NULL;
    return stack;
}

// 判断栈是否为空
bool Empty(TreeNodeStack *stack)
{
    return stack == NULL;
}
// 入栈

TreeNodeStack *Push(TreeNodeStack *stack, struct TreeNode *x)
{
    TreeNodeStack *new = (TreeNodeStack *)malloc(sizeof(TreeNodeStack));
    new->val = x;
    if (stack == NULL)
    {
        stack = new;
        stack->next = NULL;
        return stack;
    }
    else
    {
        new->next = stack;
        stack = new;
        return stack;
    }
}

//出栈并获取栈顶元素

TreeNodeStack *Pop(TreeNodeStack *stack, struct TreeNode **x)
{
    if (Empty(stack))
    {
        return NULL;
    }
    else
    {
        TreeNodeStack *s;
        *x = stack->val;
        s = stack;
        stack = stack->next;
        free(s);
        return stack;
    }
}

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

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *number, count = 0;
    number = (int *)malloc(sizeof(int) * 100);
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        TreeNode *s;
        TreeNodeStack *st;
        st = InitTreeNodeStack(st);
        st = Push(st, root);
        while (!Empty(st))
        {
            while (root != NULL && root->left != NULL)
            {
                st = Push(st, root->left);
                root = root->left;
            }
            st = Pop(st, &s);
            number[count++] = s->val;
            // printf("%d", s->val);
            if (s->right != NULL)
            {
                root = s->right;
                if (root != NULL)
                {
                    st = Push(st, root);
                }
            }
        }
        *returnSize = count;
        return number;
    }
}
int main()
{
    int b;
    int node[] = {0, 1, 3, 5, 0, 8, 6, 2};
    TreeNode *mytree;
    mytree = createTree(node, 1);
    inorderTraversal(mytree, &b);
    printf("av");
    return 0;
}
