/*
@File    :   leetcode219.c
@Time    :   2020/04/06 10:02:21
@Author  :   xiaosongsong
@Desc    :   None

给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

 

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-ii

*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
typedef struct HashTable
{
    int key;
    int index;
    struct HashTable *next;
} HashTable;
HashTable *initHashTable()
{
    HashTable *new;
    new = (HashTable *)malloc(sizeof(HashTable));
    new = NULL;
    return new;
}
bool insterHash(HashTable **ht, int key, int index, int k)
{
    HashTable *new, *p, *parnent;
    new = (HashTable *)malloc(sizeof(HashTable));
    new->key = key;
    new->index = index;
    new->next = NULL;
    if (*ht == NULL)
    {
        *ht = new;
        return false;
    }
    p = *ht;
    while (p && p->key != key)
    {
        parnent = p;
        p = p->next;
    }
    if (p == NULL)
    {
        parnent->next = new;
    }
    else
    {
        if (index - p->index <= k)
            return true;
        p->index = index;
    }
    return false;
}
bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    bool flag = false;
    HashTable *ht = initHashTable();
    for (int i = 0; i < numsSize; i++)
    {
        flag = insterHash(&ht, nums[i], i, k);
        if (flag)
            return true;
    }
    return false;
}
int main()
{
    int node[] = {1, 0, 1, 1};
    containsNearbyDuplicate(node, 4, 1);
    return 0;
}
