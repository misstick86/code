#include <stdio.h>
struct Student
{
    /* data */
    char name[20];
    int age;
};
struct Student p1 = {"busyboy", 10};
int main(int argc, char const *argv[])
{

    printf("name is %s, age is %d\n", p1.name, p1.age);

    return 0;
}
