#include <stdio.h>

/*
int main()
{
    char name[30];
    int age;
    scanf("%s", name);
    scanf("%d", &age);
    printf("name is %s, age is %d\n", name, age);

    return 0;
}


*/

void test(char *query)
{
    printf("%s", query);
}

int main(int argc, char const *argv[])
{
    char x[6];
    scanf("%s", x);
    test(x);
    return 0;
}
