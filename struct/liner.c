#include <stdio.h>
#define Maxsize 10
typedef struct
{
    /* data */
    int v[Maxsize];
    int len;
} sqlist;

int length(sqlist *L)
{
    int length;
    length = L->len;
    return length;
}

int main(int argc, char const *argv[])
{
    /* code */
    int l, i, b = 4, c = 6, d;
    sqlist a;
    a.len = 5;
    for (i = 0; i < 5; i++)
        a.v[i] = i + 2;
    l = length(&a);
    printf("the length is %d\n", l);
    return 0;
}
