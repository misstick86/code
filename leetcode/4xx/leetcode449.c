/*
@File    :   leetcode449.c
@Time    :   2020/03/18 10:38:10
@Author  :   xiaosongsong
@Desc    :   None

序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化二叉搜索树。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。


*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void CreateBstTree(struct TreeNode **t, int x)
{
    if ((*t) == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else if ((*t)->val > x)
    {
        CreateBstTree(&(*t)->left, x);
    }
    else
    {
        CreateBstTree(&(*t)->right, x);
    }
}
struct TreeNode *deserialize(char *data)
{
    struct TreeNode *root = NULL;
    char *token;
    char delim[] = ",";
    char *s = strdup(data);
    for (token = strsep(&s, delim); token != NULL; token = strsep(&s, delim))
    {
        if (strlen(token) == 0)
            continue;
        if (strlen(token) == 1)
            CreateBstTree(&root, token[0] - '0');
        else
        {
            int temp = 0;
            for (int i = strlen(token) - 1; i >= 0; i--)
            {
                temp = temp * 10 + (token[i] - '0');
            }
            CreateBstTree(&root, temp);
            // printf("%d", temp);
        }
    }
    return root;
}

void preOrder(struct TreeNode *root, char *p, int *i)
{
    int q;
    if (root)
    {
        q = root->val;
        if (q == 0)
            p[(*i)++] = '0';
        while (q)
        {
            p[(*i)++] = q % 10 + '0';
            q = q / 10;
        }
        p[(*i)++] = ',';
        preOrder(root->left, p, i);
        preOrder(root->right, p, i);
    }
}

char *serialize(struct TreeNode *root)
{
    int count = 0;
    char *p;
    p = (char *)malloc(sizeof(char) * 1204);
    preOrder(root, p, &count);
    p[count] = '\0';
    return p;
}

int main()
{
    char *q;
    q = (char *)malloc(sizeof(char) * 3);
    struct TreeNode *root = NULL, *newroot;
    int p[] = {2, 0, 3};
    for (int i = 0; i < 3; i++)
    {
        CreateBstTree(&root, p[i]);
    }
    q = serialize(root);
    // printf("%s", q);
    newroot = deserialize(q);
    return 0;
}
