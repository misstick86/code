#include <stdio.h>
#define MaxLength 20

struct names
{
    char first[MaxLength];
    char last[MaxLength];
};
struct guy
{
    struct names handle;
    char favfood[MaxLength];
    char job[MaxLength];
    float income;
};

int main(int argc, char const *argv[])
{
    /* code */

    struct guy fellow[2] = {
        {{"Ewen", "Villard"},
         "grilled salmon",
         "personality coach",
         61100.9},
        {{"Rodney", "Swillbelly"},
         "tripe",
         "tabloid editor",
         43221.00}};

    struct guy *him;
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf("pointer #1: %p #2: %p\n", him, him + 1);
    printf("him->income is $%.2f:(*him).income is $%.2f\n", him->income, (*him).income);
    him++;
    printf("him->income is $%.2f:(*him).income is $%.2f\n", him->income, (*him).income);
    return 0;
}
