/*
@File    :   leetcode1305.c
@Time    :   2020/02/28 17:33:30
@Author  :   xiaosongsong
@Desc    :   None
给你 root1 和 root2 这两棵二叉搜索树。

请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.

 

示例 1：



输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]
示例 2：

输入：root1 = [0,-10,10], root2 = [5,1,7,0,2]
输出：[-10,0,0,1,2,5,7,10]
示例 3：

输入：root1 = [], root2 = [5,1,7,0,2]
输出：[0,1,2,5,7]
示例 4：

输入：root1 = [0,-10,10], root2 = []
输出：[-10,0,10]
示例 5：



输入：root1 = [1,null,8], root2 = [8,1]
输出：[1,1,8,8]

*/

#include <stdio.h>
#include <malloc.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
void insertTree(struct TreeNode **t, int x)
{
    if (*t == NULL)
    {
        *t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else
    {
        if ((*t)->val > x)
            insertTree(&(*t)->left, x);
        else
            insertTree(&(*t)->right, x);
    }
}
void getInorder(struct TreeNode *root, int *nums, int *i)
{
    if (root)
    {
        getInorder(root->left, nums, i);
        nums[(*i)++] = root->val;
        getInorder(root->right, nums, i);
    }
}
int *getAllElements(struct TreeNode *root1, struct TreeNode *root2, int *returnSize)
{
    int i = 0, j = 0, k = 0;
    int *result;
    int nums1[1024] = {}, nums2[1024] = {}, size1 = 0, size2 = 0;
    getInorder(root1, nums1, &size1);
    getInorder(root2, nums2, &size2);
    result = (int *)malloc(sizeof(int) * (size1 + size2));
    while (i < size1 && j < size2)
    {
        if (nums1[i] < nums2[j])
            result[k++] = nums1[i++];
        else
            result[k++] = nums2[j++];
    }
    if (i < size1)
    {
        while (i < size1)
            result[k++] = nums1[i++];
    }
    if (j < size2)
    {
        while (j < size2)
            result[k++] = nums2[j++];
    }
    for (int i = 0; i < size2 + size1; i++)
    {
        printf("%d,", result[i]);
    }
    *returnSize = size1 + size2;
    return result;
}
int main()
{
    int size = 0;
    struct TreeNode *root1 = NULL, *root2 = NULL;
    int node1[] = {0, -10, 10}, node2[] = {};
    int len1 = (sizeof(node1) / sizeof(int));
    int len2 = (sizeof(node2) / sizeof(int));
    for (int i = 0; i < len1; i++)
        insertTree(&root1, node1[i]);
    for (int i = 0; i < len2; i++)
        insertTree(&root2, node2[i]);
    getAllElements(root1, root2, &size);
    return 0;
}
