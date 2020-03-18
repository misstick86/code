/*
@File    :   leetcode198.c
@Time    :   2020/03/17 19:29:44
@Author  :   xiaosongsong
@Desc    :   None

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

*/

#include <stdio.h>

int rob(int *nums, int numsSize)
{
    int i;
    int sum1 = 0, sum2 = 0;
    for (i = 0; i < numsSize - 1; i = i + 2)
    {
        sum1 += nums[i];
        sum2 += nums[i + 1];
    }
    if (i + 1 == numsSize)
        sum1 += nums[i];
    return sum1 > sum2 ? sum1 : sum2;
}
int main()
{
    int node[] = {2, 7, 9, 3, 1, 2, 7, 9, 3, 2, 7, 9, 3, 1};
    printf("%d", rob(node, 14));
    return 0;
}
