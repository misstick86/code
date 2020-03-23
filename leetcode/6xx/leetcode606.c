/*
@File    :   leetcode606.c
@Time    :   2020/03/23 17:45:43
@Author  :   xiaosongsong
@Desc    :   None

你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。

空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

示例 1:

输入: 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

输出: "1(2(4))(3)"

解释: 原本将是“1(2(4)())(3())”，
在你省略所有不必要的空括号对之后，
它将是“1(2(4))(3)”。
示例 2:

输入: 二叉树: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

输出: "1(2()(4))(3)"

解释: 和第一个示例相似，
除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。


*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createTree(int *nodelist, int i)
{
    struct TreeNode *new;
    if (nodelist[i] == 0 || i > 4)
        return NULL;
    new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new->val = nodelist[i];
    new->left = createTree(nodelist, 2 * i);
    new->right = createTree(nodelist, 2 * i + 1);
    return new;
}

void *preOrder(struct TreeNode *t)
{
    if (t)
    {
        printf("%d,", t->val);
        preOrder(t->left);
        preOrder(t->right);
    }
}
char *tree2str(struct TreeNode *t)
{
    char *result, *re;
    result = (char *)malloc(sizeof(char) * 1024);
    preOrder(t);
}
int main()
{
    struct TreeNode *root;
    int node[] = {0, 1, 2, 3, 4};
    root = createTree(node, 1);
    tree2str(root);
    return 0;
}
