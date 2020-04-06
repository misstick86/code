/*
@File    :   leetcode703.c
@Time    :   2020/04/06 18:20:33
@Author  :   xiaosongsong
@Desc    :   None

设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。

示例:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-a-stream
*/

#include <stdio.h>
#include <malloc.h>
typedef struct
{
    int k;
    int count;
    int *nums;
} KthLargest;

KthLargest *InitKthLargest(int k, int n)
{
    KthLargest *new;
    new = (KthLargest *)malloc(sizeof(KthLargest));
    new->k = k;
    new->count = n;
    new->nums = (int *)malloc(sizeof(int) * n);
    return new;
}

KthLargest *kthLargestCreate(int k, int *nums, int numsSize)
{
    KthLargest *kl = InitKthLargest(k, numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        kl->nums[i] = nums[i];
    }
    return kl;
}

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void adjustHeap(int *nums, int n, int k)
{
    int j = 2 * k + 1;
    while (j < n)
    {
        if (j + 1 < n && nums[j] < nums[j + 1])
            j++;
        if (nums[k] > nums[j])
            break;
        else
        {
            Swap(&nums[k], &nums[j]);
            k = j;
            j = 2 * j + 1;
        }
    }
}
int getMaxValue(int *nums, int n)
{
    int value = nums[0];
    nums[0] = nums[n];
    adjustHeap(nums, n, 0);
    return value;
}
int kthLargestAdd(KthLargest *obj, int val)
{
    int *tempkl;
    tempkl = (int *)malloc(sizeof(int) * obj->count);

    int value = 0;
    int pos = obj->count / 2 - 1;
    for (int i = pos; i >= 0; i--)
        adjustHeap(obj->nums, obj->count, i);
    for (int i = 0; i < obj->count; i++)
        tempkl[i] = obj->nums[i];
    for (int i = 0; i < obj->k; i++)
        value = getMaxValue(tempkl, obj->count - 1);
    printf("%d,", value);
    for (int i = 0; i < obj->count; i++)
    {
        printf("%d,", obj->nums[i]);
    }

    return value;
}

void kthLargestFree(KthLargest *obj)
{
}
int main()
{
    KthLargest *kl;
    int node[] = {4, 5, 8, 2};
    kl = kthLargestCreate(3, node, 4);
    kthLargestAdd(kl, 5);
    return 0;
}
