#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#define SeqStackMaxSize 10

typedef struct SqeStack
{
    int data[SeqStackMaxSize];
    int top;

} seqStack;

// 栈的基本操作

// 判断栈是否为空
bool isEmptyStack(seqStack *s)
{
    return s->top == 0;
}

// 判断栈是否满

bool isFullStack(seqStack *s)
{
    return s->top == SeqStackMaxSize;
}

// 入栈

void PushStack(seqStack *s, int x)
{
    if (isFullStack(s))
    {
        printf("栈已满，无法入栈！\n");
    }
    else
    {
        /* code */
        s->data[s->top] = x;
        s->top++;
    }
}

// 出栈
void PopStack(seqStack *s)
{
    if (isEmptyStack(s))
    {
        printf("栈已到底，无法出栈！");
    }
    else
    {
        /* code */
        s->top--;
    }
}

// 弹出栈顶元素
int getTopStackValue(seqStack *s)
{
    if (!isEmptyStack(s))
    {
        int value;
        value = s->data[s->top - 1];
        printf("栈顶元素为:%d\n", value);
    }
    else
    {
        /* code */
        return -1;
    }
}

// 初始化栈

void initStack(seqStack *s)
{
    s->top = 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    int number;
    seqStack *ss;
    ss->top = 0;
    initStack(ss);
    printf("init:%d\n", ss->top);
    printf("input a push stack:");
    scanf("%d", &number);
    while (number != -1)
    {
        /* code */
        PushStack(ss, number);
        printf("input a push stack:");
        scanf("%d", &number);
    }
    while (!isEmptyStack(ss))
    {
        /* code */
        getTopStackValue(ss);
        PopStack(ss);
        // printf("top is:%d", ss->top);
        // sleep(1);
    }

    return 0;
}
