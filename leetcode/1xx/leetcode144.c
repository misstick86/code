/*
@File    :   leetcode144.c
@Time    :   2020/02/05 18:29:41
@Author  :   xiaosongsong
@Desc    :   None

给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,2,3]
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

// 初始化栈
TreeNodeStack *InitStack()
{
    TreeNodeStack *stack;
    stack = NULL;
    return stack;
}

// 判断栈是否为空
bool Empty(TreeNodeStack *p)
{
    return p == NULL;
}
// 入栈

TreeNodeStack *Push(TreeNodeStack *p, TreeNode *x)
{
    TreeNodeStack *new;
    new = (TreeNodeStack *)malloc(sizeof(TreeNodeStack));
    new->val = x;
    if (p == NULL)
    {
        p = new;
        p->next = NULL;
        return new;
    }
    else
    {
        new->next = p;
        p = new;
        return p;
    }
}

// 出栈，顺便将栈顶元素获取
TreeNodeStack *Pop(TreeNodeStack *p, TreeNode **x)
{

    TreeNodeStack *s;
    // if (Empty(p))
    // {
    //     return NULL;
    // }
    // else
    // {

    // }
    *x = p->val;
    s = p;
    p = p->next;
    free(s);
    return p;
}

TreeNode *createTree(int *nodelist, int i)
{
    if (nodelist[i] == 0 || i > 9)
    {
        return NULL;
    }
    else
    {
        TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i);
        new->right = createTree(nodelist, 2 * i + 1);
        return new;
    }
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *number, count = 0;
    number = (int *)malloc(sizeof(int) * 100);
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        TreeNodeStack *mystack;
        TreeNode *p;
        mystack = InitStack();

        mystack = Push(mystack, root);
        while (!Empty(mystack))
        {
            mystack = Pop(mystack, &p);
            number[count] = p->val;
            // printf("%d", p->val);
            if (p->right != NULL)
            {
                mystack = Push(mystack, p->right);
            }
            if (p->left != NULL)
            {
                mystack = Push(mystack, p->left);
            }

            count++;
        }
    }
    *returnSize = count;
    printf("%d\n", *returnSize);
    for (int i = 0; i < count; i++)
    {
        printf("%d", number[i]);
    }
    return number;
}
int main()
{
    int size;
    int node[] = {0, 1, 3, 5, 0, 8, 6, 2};
    TreeNode *root;
    root = createTree(node, 1);
    preorderTraversal(root, &size);
    // printf("da");
    return 0;
}
