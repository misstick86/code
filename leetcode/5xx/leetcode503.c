/*
@File    :   leetcode503.c
@Time    :   2020/04/03 18:09:44
@Author  :   xiaosongsong
@Desc    :   None
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-ii


*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct StackList
{
    int val; //栈中元素存储数组的下表
    struct StackList *next;
} StackList;

bool Empty(StackList *st)
{
    return st == NULL;
}
StackList *initStack()
{
    StackList *new;
    new = (StackList *)malloc(sizeof(StackList));
    new = NULL;
    return new;
}

StackList *Push(StackList *st, int val)
{
    StackList *new;
    new = (StackList *)malloc(sizeof(StackList));
    new->val = val;
    new->next = NULL;
    if (st == NULL)
        st = new;
    else
    {
        new->next = st;
        st = new;
    }
    return st;
}

StackList *Pop(StackList *st)
{
    StackList *p;
    p = st;
    st = st->next;
    free(p);
    p = NULL;
    return st;
}

void getTopValue(StackList *st, int *p)
{
    if (!Empty(st))
        *p = st->val;
}

int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{

    int *result;
    int count = 0, p = 0, i = 0, flag = 2;
    result = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    StackList *st = initStack();
    if (numsSize == 0)
        return result;
    int maxValue = nums[0];
    st = Push(st, 0);
    while (!Empty(st) && flag)
    {
        getTopValue(st, &p);
        while (!Empty(st) && nums[p] < nums[i])
        {
            st = Pop(st);
            result[p] = nums[i];
            getTopValue(st, &p);
        }
        if (i < numsSize)
            st = Push(st, i);
        if (maxValue < nums[i])
            maxValue = nums[i];
        i = (i + 1) % numsSize;
        if (i == 0)
            flag--;
    }
    while (!Empty(st))
    {
        getTopValue(st, &p);
        if (nums[p] == maxValue)
            result[p] = -1;
        st = Pop(st);
    }
    return result;
}
int main()
{
    int size = 0;
    int node[] = {-1};
    nextGreaterElements(node, 1, &size);
    return 0;
}
