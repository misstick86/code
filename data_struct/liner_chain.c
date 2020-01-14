/* 单链表的增删查 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 20
typedef struct stu
{
    char name[MaxSize];
    int age;
    struct stu *next;
    /* data */
} student;

// 链表的输出

void print_stu(student *Head)
{
    student *Pointer;
    Pointer = Head;
    while (Pointer != NULL)
    {
        printf("## Output Data:");
        printf("name is %s, age is %d\n", Pointer->name, Pointer->age);
        Pointer = Pointer->next;
        /* code */
    }
}

// 链表的创建

student *create()
{
    student *Head;
    char name[MaxSize];
    int age;
    student *New, *Pointer;
    int i;
    Head = (student *)malloc(sizeof(student));
    if (Head == NULL)
    {
        printf("Memory allocate Failure!!\n");
    }
    else
    {
        /* code */
        printf("开始录入学生信息....\n");
        printf("请输入学生姓名和年龄:");
        scanf("%s %d", name, &age);
        strcpy(Head->name, name);
        Head->age = age;
        Head->next = NULL;
        Pointer = Head;
        // 继续录入学习信息
        while (1)
        {
            /* code */
            printf("请输入学生姓名和年龄:");
            scanf("%s %d", name, &age);
            // gets(name);
            if (name[0] == '0')
            {
                printf("程序退出\n");
                break;
            }
            New = (student *)malloc(sizeof(student));
            // New->name = name;
            strcpy(New->name, name);
            New->age = age;
            New->next = NULL;
            Pointer->next = New;
            Pointer = New;
        }
        return Head;
    }
}
// 链表的删除

int delete_line(student *Head, char *delete_name)
{
    // print_stu(Head);
    student *Pointer;
    student *back;
    Pointer = Head;
    if (Pointer == NULL)
    {
        return 0;
    }

    while (Pointer->next != NULL)
    {
        back = Pointer;
        Pointer = Pointer->next;
        if (!strcmp(Pointer->name, delete_name))
        {
            back->next = Pointer->next;
            free(Pointer);
            break;
        }
    }
    return 0;
}

// 链表的插入

int insert_line(student *Head, char *insert_name, int age)
{
    student *new;
    int i, n = 0;
    printf("please input insert position:");
    scanf("%d", &i);
    student *p;
    p = Head;
    new = (student *)malloc(sizeof(student));
    strcpy(new->name, insert_name);
    new->age = age;

    while (p->next != NULL)
    {
        n++;
        if (n == i)
        {
            new->next = p->next;
            p->next = new;
            break;
        }
    }
}

// 链表的查找

int query_line(student *Head, char *query_name)
{
    // Head 为链表的首地址， query_name 为查询的人名
    student *p;
    p = Head;
    while (p->next != NULL)
    {
        /* code */
        if (!strcmp(p->name, query_name))
        {
            printf("query student name is %s, age is %d\n", p->name, p->age);
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int reverse_line(student *Head)
{
    student *prev;
    student *p, *temp;
    p = Head;
    while (p)
    {
        /* code */
        temp = p->next;
        p->next = prev;
        prev = p;
        p = temp;
    }
    Head = prev;
    print_stu(Head);
}

int main(int argc, char const *argv[])
{
    /* code */
    char query[MaxSize];
    int age;
    student *H;
    // 创建
    H = create();
    // printf("first is %s\n", H->next->name);

    // 反转
    reverse_line(H);
    // 输出
    // if (H != NULL)
    // {
    //     print_stu(H);
    // }
    // // 查找
    // printf("please input query string:");
    // scanf("%s", query);
    // if (!query_line(H, query))
    // {
    //     printf("未查询到\n");
    // }

    // 删除

    // printf("plesase input delete string:");
    // scanf("%s", query);
    // delete_line(H, query);
    // print_stu(H);
    // 链表的插入
    // printf("plesase input insert student name string and age:");
    // scanf("%s", query);
    // scanf("%d", &age);
    // insert_line(H, query, age);
    // print_stu(H);
    return 0;
}
