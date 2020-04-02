/*
@File    :   leetcode1299.c
@Time    :   2020/04/02 09:57:50
@Author  :   xiaosongsong
@Desc    :   None

给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。

完成所有替换操作后，请你返回这个数组。

 

示例：

输入：arr = [17,18,5,4,6,1]
输出：[18,6,6,6,1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side

*/

#include <stdio.h>
int *replaceElements(int *arr, int arrSize, int *returnSize)
{
    *returnSize = arrSize;
    if (arrSize > 0)
    {
        int currentMax = arr[arrSize - 1];

        arr[arrSize - 1] = -1;
        for (int i = arrSize - 2; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = currentMax;
            if (temp > currentMax)
                currentMax = temp;
        }
    }
    return arr;
}
int main()
{
    int size = 0;
    int node[] = {17, 18, 5, 4, 6, 1};
    replaceElements(node, 6, &size);
    return 0;
}
