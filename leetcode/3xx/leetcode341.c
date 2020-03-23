/*
@File    :   leetcode341.c
@Time    :   2020/03/23 09:29:32
@Author  :   xiaosongsong
@Desc    :   None


给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

 

示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。


*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <ctype.h>
struct NestedIterator
{
    int *val;
    int top;
};

struct NestedIterator *nestedIterCreate(struct NestedInteger **nestedList, int nestedListSize)
{
}

bool nestedIterHasNext(struct NestedIterator *iter)
{
}

int nestedIterNext(struct NestedIterator *iter)
{
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter)
{
}
int main()
{

    return 0;
}
