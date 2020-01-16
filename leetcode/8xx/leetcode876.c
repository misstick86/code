/*
@File    :   leetcode876.c
@Time    :   2020/01/16 10:03:27
@Author  :   xiaosongsong
@Desc    :   None

给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

 

示例 1：

输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
示例 2：

输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
 

提示：

给定链表的结点数介于 1 和 100 之间。

*/

#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *create()
{
    ListNode *Head, *Pointer, *New;
    Head = (ListNode *)malloc(sizeof(struct ListNode));
    if (Head == NULL)
    {
        printf("内存分配失败");
    }
    else
    {
        int data = 1;
        Head->val = data;
        Head->next = NULL;
        Pointer = Head;
        int initdata[4] = {2, 3, 4, 5};
        for (int i = 0; i < 4; i++)
        {
            New = (ListNode *)malloc(sizeof(struct ListNode));
            New->val = initdata[i];
            Pointer->next = New;
            Pointer = New;
        }
    }
    return Head;
}

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *p;
    p = head;
    int i = 0;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    i = i / 2;
    while (i)
    {
        head = head->next;
        i--;
    }
    // while (head)
    // {
    //     printf("%d\n", head->val);
    //     head = head->next;
    // }

    return head;
}
int main()
{
    ListNode *head;
    head = create();
    middleNode(head);
    return 0;
}
