/*
@File    :   leetcode575.c
@Time    :   2020/04/06 10:37:03
@Author  :   xiaosongsong
@Desc    :   None

给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。

示例 1:

输入: candies = [1,1,2,2,3,3]
输出: 3
解析: 一共有三种种类的糖果，每一种都有两个。
     最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。
示例 2 :

输入: candies = [1,1,2,3]
输出: 2
解析: 妹妹获得糖果[2,3],弟弟获得糖果[1,1]，妹妹有两种不同的糖果，弟弟只有一种。这样使得妹妹可以获得的糖果种类数最多。
注意:

数组的长度为[2, 10,000]，并且确定为偶数。
数组中数字的大小在范围[-100,000, 100,000]内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-candies
*/

#include <stdio.h>
#include <malloc.h>
typedef struct HashTable
{
    int key;
    struct HashTable *next;
} HashTable;

HashTable *initHashTable()
{
    HashTable *new;
    new = (HashTable *)malloc(sizeof(HashTable));
    new = NULL;
    return new;
}
HashTable *insterHashTable(HashTable *ht, int key, int *size)
{
    HashTable *new, *p, *parnent;
    new = (HashTable *)malloc(sizeof(HashTable));
    new->key = key;
    new->next = NULL;
    if (ht == NULL)
    {
        *size = 1;
        return new;
    }
    p = ht;
    while (p && p->key < key)
    {
        parnent = p;
        p = p->next;
    }
    if (p == NULL)
    {
        (*size)++;
        parnent->next = new;
    }
    else
    {
        if (key != p->key)
        {
            (*size)++;
            parnent->next = new;
            new->next = p;
        }
    }

    return ht;
}
int distributeCandies(int *candies, int candiesSize)
{
    int size = 0;
    HashTable *ht = initHashTable();
    for (int i = 0; i < candiesSize; i++)
    {
        ht = insterHashTable(ht, candies[i], &size);
    }
    if (size <= candiesSize / 2)
        return size;
    else
        return candiesSize / 2;
}
int main()
{
    int node[] = {1, 2, 3, 6, 6, 6, 5, 4};
    distributeCandies(node, 8);
    return 0;
}
