#include <stdio.h>
#define StackMaxSize 10240

typedef struct BracketsStack
{
    char data[StackMaxSize];
    int top;

} BracketsStack;

// 入栈
void BracketsStackPush(BracketsStack *obj, char x)
{
    if (obj->top < StackMaxSize)
    {
        obj->data[obj->top] = x;
        obj->top++;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
