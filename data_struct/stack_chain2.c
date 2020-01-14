/*
@File    :   stack_chain2.c
@Time    :   2020/01/10 10:30:59
@Author  :   xiaosongsong
@Desc    :   链栈的表示2
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct StackNode
{
    char data;
    struct StackLink *next;
} StackNode;

typedef StackNode *LinkStack;

void InitStack(LinkStack *p)
{
    *p = NULL;
}

void Push(LinkStack *p, char x)
{
    StackNode *t = (StackNode *)malloc(sizeof(StackNode));
    assert(t != NULL);
    t->data = x;
    if (*p == NULL)
    {
        *p = t;
        t->next = NULL;
    }
    else
    {
        t->next = *p;
        *p = t;
    }
}
void PoP(LinkStack *p)
{
    StackNode *t;
    t = *p;
    *p = t->next;
    free(t);
}
void Show(LinkStack *p)
{
    StackNode *s = *p;
    while (s != NULL)
    {
        printf("%c\n", s->data);
        s = s->next;
    }
}
int main()
{
    LinkStack st;
    InitStack(&st);
    Push(&st, 'a');
    Push(&st, 'b');
    Push(&st, 'c');
    Push(&st, 'd');
    Show(&st);
    PoP(&st);
    Show(&st);
    return 0;
}
