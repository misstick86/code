
/*
@File    :   leetcode1021.c
@Time    :   2020/01/10 09:00:31
@Author  :   xiaosongsong
@Desc    :

有效括号字符串为空 ("")、"(" + A + ")" 或 A + B，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。

如果有效字符串 S 非空，且不存在将其拆分为 S = A+B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。

给出一个非空有效字符串 S，考虑将其进行原语化分解，使得：S = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。

对 S 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S 。

示例 1：

输入："(()())(())"
输出："()()()"
解释：
输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
示例 2：

输入："(()())(())(()(()))"
输出："()()()()(())"
解释：
输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
删除每隔部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
示例 3：

输入："()()"
输出：""
解释：
输入字符串为 "()()"，原语化分解得到 "()" + "()"，
删除每个部分中的最外层括号后得到 "" + "" = ""。
 

提示：

S.length <= 10000
S[i] 为 "(" 或 ")"
S 是一个有效括号字符串


评价：

leetcode 上使用malloc分配内存总是出现堆溢出， 不知道怎么回事。 只能使用大数组了。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct BracketsStack
{
    char data;
    struct BracketsStack *next;

} BracketsStack;

// 创建栈
BracketsStack *InitStack(BracketsStack *s)
{
    s = NULL;
    return s;
}

// 判断是否为空栈
bool isEmptyStack(BracketsStack *s)
{
    return s == NULL;
}

// 入栈
BracketsStack *BracketsStackPush(BracketsStack *obj, char x)
{
    BracketsStack *s;
    s = (BracketsStack *)malloc(sizeof(BracketsStack));
    assert(s != NULL);
    s->data = x;
    if (obj == NULL)
    {
        obj = s;
        s->next = NULL;
    }
    else
    {
        s->next = obj;
        obj = s;
    }
    return obj;
}

BracketsStack *BracketsStackPop(BracketsStack *obj)
{
    BracketsStack *s;
    s = obj;
    obj = s->next;
    free(s);
    return obj;
}

void StackShow(BracketsStack *obj)
{
    BracketsStack *p;
    p = obj;
    while (p)
    {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}

// 释放栈
void BracketsStackFree(BracketsStack *obj)
{
    free(obj);
    obj = NULL;
}

// 业务函数
char *removeOuterParentheses(char *S)
{
    char p[1024], result[1024];
    int j = 0, i = 0;
    BracketsStack *Pointer;
    Pointer = InitStack(Pointer);
    while (*S != '\0')
    {

        p[j] = *S;
        if (*S == '(')
        {
            Pointer = BracketsStackPush(Pointer, *S);
        }
        else
        {
            Pointer = BracketsStackPop(Pointer);
        }
        S++;
        j++;
        if (isEmptyStack(Pointer))
        {
            p[j] = '\0';
            for (int k = 1; k <= strlen(p) - 2; k++)
            {
                result[i] = p[k];
                i++;
            }
            j = 0;
            memset(p, '\0', strlen(p));
        }
    }
    result[i] = '\0';
    BracketsStackFree(Pointer);

    S = result;
    printf("%s", S);
    return S;
}

int main(int argc, char const *argv[])
{
    /* code */
    // char *result;
    char s[] = "(()())(())(()(()))";
    //
    removeOuterParentheses(s);
    // BracketsStack *p;
    // p = InitStack(p);
    // p = BracketsStackPush(p, 'a');
    // p = BracketsStackPush(p, 'b');
    // p = BracketsStackPush(p, 'c');
    // p = BracketsStackPush(p, 'd');
    // StackShow(p);
    // printf("====\n");
    // p = BracketsStackPop(p);
    // StackShow(p);
    return 0;
}
