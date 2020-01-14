#include <stdio.h>

char *removeOuterParentheses(char *S)
{
    char s[] = "abc";
    return S;
}
int main(int argc, char const *argv[])
{
    /* code */
    char *result = NULL;
    printf("%p\n", result);
    char s[] = "(()())(())";
    result = removeOuterParentheses(s);
    printf("%p\n", result);
    return 0;
}