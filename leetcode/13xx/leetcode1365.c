/*
@File    :   leetcode1365.c
@Time    :   2020/04/05 13:28:01
@Author  :   xiaosongsong
@Desc    :   None
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。

 

示例 1：

输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释：
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。
对于 nums[3]=2 存在一个比它小的数字：（1）。
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
示例 2：

输入：nums = [6,5,4,8]
输出：[2,1,0,3]
示例 3：

输入：nums = [7,7,7,7]
输出：[0,0,0,0]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number
*/

#include <stdio.h>
#include <malloc.h>
typedef struct HaskTable
{
    int key;
    int count;
    struct HaskTable *next;
} HaskTable;
HaskTable *InitHash()
{
    HaskTable *new;
    new = (HaskTable *)malloc(sizeof(HaskTable));
    new = NULL;
    return new;
}

HaskTable *addHash(HaskTable *tb, int key)
{
    HaskTable *new;
    if (tb == NULL)
    {
        new = (HaskTable *)malloc(sizeof(HaskTable));
        new->key = key;
        new->count = 1;
        new->next = NULL;
        return new;
    }
    else
    {
        HaskTable *p, *parent;
        p = tb;
        parent = p;
        while (p && p->key < key)
        {
            parent = p;
            p = p->next;
        }
        if (p == NULL)
        {
            new = (HaskTable *)malloc(sizeof(HaskTable));
            new->key = key;
            new->count = 1;
            new->next = NULL;
            parent->next = new;
            return tb;
        }
        if (p->key == key)
        {
            p->count++;
            return tb;
        }

        if (key < p->key)
        {
            new = (HaskTable *)malloc(sizeof(HaskTable));
            new->key = key;
            new->count = 1;
            new->next = NULL;
            if (parent == p)
            {
                new->next = p;
                return new;
            }
            else
            {
                parent->next = new;
                new->next = p;
            }
        }
    }
    return tb;
}
int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    int count = 0;
    HaskTable *p = NULL, *tb = InitHash();
    *returnSize = numsSize;
    int *result;
    result = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
        tb = addHash(tb, nums[i]);
    for (int i = 0; i < numsSize; i++)
    {
        p = tb;
        count = 0;
        while (p && nums[i] > p->key)
        {
            count += p->count;
            p = p->next;
        }
        result[i] = count;
    }
    return result;
}
int main()
{
    int size = 0;
    int node[] = {8, 1, 2, 2, 3, 9};
    smallerNumbersThanCurrent(node, 6, &size);
    return 0;
}
