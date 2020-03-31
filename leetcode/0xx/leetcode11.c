/*
@File    :   leetcode11.c
@Time    :   2020/03/31 20:23:07
@Author  :   xiaosongsong
@Desc    :   None
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water

*/

#include <stdio.h>
int minValue(int a, int b)
{
    return a < b ? a : b;
}
int maxArea(int *height, int heightSize)
{
    int maxValue = 0;
    int first = 0;
    int last = heightSize - 1;
    while (first < last)
    {
        int min = minValue(height[first], height[last]);
        if (maxValue < min * (last - first))
            maxValue = min * (last - first);
        if (height[first] < height[last])
            first++;
        else
            last--;
    }
    return maxValue;
}
int main()
{
    int node[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    maxArea(node, sizeof(node) / sizeof(int));
    return 0;
}
