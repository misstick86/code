#include <stdio.h>
#include <string.h>
struct Student
{
    /* data */
    char name[20];
    int age;
} p1;

struct Student p1 = {"busyboy", 20};
struct Student *s = &p1;

int main(int argc, char const *argv[])
{
    /* code */
    printf("name is %s, age is %d\n", s->name, s->age);
    return 0;
}
