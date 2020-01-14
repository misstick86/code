/*
 栈的链式存储
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

StackNode *initStack()
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p = NULL;
    return p;
}

bool isEmptyStack(StackNode *s)
{
    return s == NULL;
}

StackNode *pushStack(StackNode *s, int x)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = x;
    p->next = s;
    s = p;
    return s;
}

StackNode *popStack(StackNode *s, int *x)
{
    StackNode *p;
    // printf("%d\n", s->data);
    if (isEmptyStack(s))
    {
        printf("空栈\n");
    }
    else
    {
        /* code */
        *x = s->data;
        p = s;
        s = s->next;
        free(p);
    }
    return s;
}

int main(int argc, char const *argv[])
{
    /* code */
    StackNode *p = initStack();
    int i, x;

    for (i = 0; i < 6; i++)
    {
        p = pushStack(p, i);
        printf("current: %d\n", p->data);
    }
    for (i = 0; i < 6; i++)
    {
        p = popStack(p, &x);
        printf("出栈：%d\n", x);
    }
    return 0;
}
