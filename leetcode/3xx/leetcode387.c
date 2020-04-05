/*
@File    :   leetcode387.c
@Time    :   2020/03/22 20:10:49
@Author  :   xiaosongsong
@Desc    :   None
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.

*/

#include <stdio.h>
#include <malloc.h>
typedef struct HashTable
{
    char val;
    int count;
    int index;
    struct HashTable *next;
} HashTable;
HashTable *initHask()
{
    HashTable *new;
    new = (HashTable *)malloc(sizeof(HashTable));
    new = NULL;
    return new;
}
HashTable *addValue(HashTable *ht, char val, int index)
{
    HashTable *new;
    HashTable *p = ht;
    HashTable *parent = p;
    new = (HashTable *)malloc(sizeof(HashTable));
    new->val = val;
    new->count = 1;
    new->index = index;
    new->next = NULL;
    if (ht == NULL)
        return new;
    while (p && p->val != val)
    {
        parent = p;
        p = p->next;
    }
    if (p == NULL)
    {
        parent->next = new;
        return ht;
    }
    if (p->val == val)
    {
        p->count++;
    }
    return ht;
}

int firstUniqChar(char *s)
{
    int i = 0;
    HashTable *ht = initHask();
    while (*s != '\0')
    {
        ht = addValue(ht, *s, i++);
        s++;
    }
    while (ht)
    {
        if (ht->count == 1)
            return ht->index;
        ht = ht->next;
    }
    return -1;
}
int main()
{
    char *s = "looveleetcde";
    firstUniqChar(s);
    return 0;
}
