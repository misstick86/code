/*
@File    :   leetcode145.c
@Time    :   2020/02/06 20:19:09
@Author  :   xiaosongsong
@Desc    :   None

定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// 定义一个左右标记的枚举类型
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

// 构造新的树型结构， 例如： A|L B|R, 也是入栈的数据
typedef struct TreeNodeTag
{
    struct TreeNode *ptr;
    Tag tag;
} TreeNodeTag;

// 构造栈结构
typedef struct TreeNodeStack
{
    TreeNodeTag val;
    struct TreeNodeStack *next;
} TreeNodeStack;

// 初始化栈

TreeNodeStack *InitStack()
{
    TreeNodeStack *new;
    new = NULL;
    return new;
}
// 判断栈是否为空
bool Empty(TreeNodeStack *p)
{
    return p == NULL;
}
// 入栈

TreeNodeStack *Push(TreeNodeStack *stack, TreeNodeTag x)
{
    TreeNodeStack *new;
    new = (TreeNodeStack *)malloc(sizeof(TreeNodeStack));
    new->val = x;
    if (stack == NULL)
    {
        new->next = NULL;
        return new;
    }
    else
    {
        new->next = stack;
        stack = new;
        return stack;
    }
}
// 出栈
TreeNodeStack *Pop(TreeNodeStack *stack, TreeNodeTag *x)
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
    if (nodelist[i] == 0 || i > 8)
    {
        return NULL;
    }
    else
    {
        TreeNode *new;
        new = (TreeNode *)malloc(sizeof(TreeNode));
        new->val = nodelist[i];
        new->left = createTree(nodelist, 2 * i);
        new->right = createTree(nodelist, 2 * i + 1);
        return new;
    }
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *number, count = 0;
    number = (int *)malloc(sizeof(int) * 100);

    if (root != NULL)
    {
        TreeNodeStack *st;
        st = InitStack();
        TreeNodeTag treetag, p;
        do
        {
            while (root != NULL)
            {
                treetag.ptr = root;
                treetag.tag = L;
                st = Push(st, treetag);
                root = root->left;
            }
            st = Pop(st, &p);
            switch (p.tag)
            {
            case L:
                p.tag = R;
                st = Push(st, p);
                root = p.ptr->right;
                break;
            case R:
                number[count++] = p.ptr->val;
                break;

            default:
                break;
            }
        } while (!Empty(st));
    }
    *returnSize = count;
    return number;
}
int main()
{
    int node[] = {0, 1, 3, 5, 0, 8, 6, 2};
    int b;
    TreeNode *tree;
    tree = createTree(node, 1);
    postorderTraversal(tree, &b);
    printf("av");
    return 0;
}
