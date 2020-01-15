/*
@File    :   leetcode1047.c
@Time    :   2020/01/15 08:59:23
@Author  :   xiaosongsong
@Desc    :   None

给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

示例：

输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 

提示：

1 <= S.length <= 20000
S 仅由小写英文字母组成。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct StackNode
{
    char data;
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

StackNode *pushStack(StackNode *s, char x)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = x;
    p->next = s;
    s = p;
    return s;
}

StackNode *popStack(StackNode *s)
{
    StackNode *p;
    // printf("%d\n", s->data);
    if (isEmptyStack(s))
    {
        return NULL;
    }
    else
    {
        // /* code */
        // *x = s->data;
        p = s;
        s = s->next;
        free(p);
    }
    return s;
}

// 获取栈顶的元素

char getStackValue(StackNode *s)
{

    return s->data;
}
void reverse(char *str)
{
    char *p = str + strlen(str) - 1;
    char temp;
    while (str < p)
    {
        temp = *p;
        *p-- = *str;
        *str++ = temp;
    }
}

char *removeDuplicates(char *S)
{
    int i = 0;
    char *str = S;
    StackNode *p;
    p = initStack();
    while (*S != '\0')
    {
        if (p != NULL)
        {
            if (getStackValue(p) == *S)
            {
                p = popStack(p);
            }
            else
            {
                p = pushStack(p, *S);
            }
        }
        else
        {
            p = pushStack(p, *S);
        }
        S++;
    }

    while (!isEmptyStack(p))
    {
        str[i] = getStackValue(p);
        i++;

        p = popStack(p);
    }
    str[i] = '\0';
    reverse(str);
    return str;
}
int main()
{
    char s[] = "abbaca";
    removeDuplicates(s);
    return 0;
}
