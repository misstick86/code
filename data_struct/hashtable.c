/*
@File    :   hashtable.c
@Time    :   2020/02/25 08:55:09
@Author  :   xiaosongsong
@Desc    :   None
Hash表 基于 除留余数发和链地址法

*/

#include <stdio.h>
#include <malloc.h>
#define HASH_KEY_SIZE 13
#define HASH_NULL -1
typedef struct HashNode
{
    int val;
    struct HashNode *next;
} HashNode;

typedef HashNode *HashTable[HASH_KEY_SIZE];

void InitHashTable(HashTable *p)
{
    for (int i = 0; i < HASH_KEY_SIZE; i++)
    {
        (*p)[i] = NULL;
    }
}
int Hash(int x)
{
    return x % HASH_KEY_SIZE;
}
void InsertHashTable(HashTable *p, int x)
{

    HashNode *new;
    int index = Hash(x);
    new = (HashNode *)malloc(sizeof(HashNode));
    new->val = x;
    new->next = (*p)[index];
    (*p)[index] = new;
}
int main()
{
    HashTable ht;
    int node[] = {19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79};
    int count = sizeof(node) / sizeof(int);
    InitHashTable(&ht);
    for (int i = 0; i < count; i++)
        InsertHashTable(&ht, node[i]);
    return 0;
}
