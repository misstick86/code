/*
@File    :   leetcode817.c
@Time    :   2020/02/12 10:12:07
@Author  :   xiaosongsong
@Desc    :   None

给定一个链表（链表结点包含一个整型值）的头结点 head。

同时给定列表 G，该列表是上述链表中整型值的一个子集。

返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。

示例 1：

输入:
head: 0->1->2->3
G = [0, 1, 3]
输出: 2
解释:
链表中,0 和 1 是相连接的，且 G 中不包含 2，所以 [0, 1] 是 G 的一个组件，同理 [3] 也是一个组件，故返回 2。
示例 2：

输入:
head: 0->1->2->3->4
G = [0, 3, 1, 4]
输出: 2
解释:
链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。
注意:

如果 N 是给定链表 head 的长度，1 <= N <= 10000。
链表中每个结点的值所在范围为 [0, N - 1]。
1 <= G.length <= 10000
G 是链表中所有结点的值的一个子集.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-components
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;
struct ListNode *createList(int *node, int n)
{
    int i = 0;
    ListNode *root, *new, *pointer;
    new = (ListNode *)malloc(sizeof(ListNode));
    new->val = node[i++];
    new->next = NULL;
    root = new;
    pointer = new;

    while (i < n)
    {
        new = (ListNode *)malloc(sizeof(ListNode));
        new->val = node[i++];
        new->next = NULL;
        pointer->next = new;
        pointer = new;
    }
    return root;
}

bool isEsixt(int *G, int GSize, int q)
{
    for (int i = 0; i < GSize; i++)
        if (G[i] == q)
            return true;
    return false;
}

int numComponents(struct ListNode *head, int *G, int GSize)
{
    int count = 0;
    int flag = isEsixt(G, GSize, head->val);
    while (head)
    {
        while (head && isEsixt(G, GSize, head->val))
        {
            head = head->next;
        }
        count++;
        while (head && !isEsixt(G, GSize, head->val))
        {
            head = head->next;
        }
    }
    if (!flag)
        return count - 1;
    return count;
}
int main()
{

    ListNode *p;
    int list[] = {3, 4, 0, 1, 2};
    int G[] = {4};
    p = createList(list, 5);
    printf("%d", numComponents(p, G, 1));
    return 0;
}
