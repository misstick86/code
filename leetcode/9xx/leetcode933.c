/*
@File    :   leetcode933.c
@Time    :   2020/04/07 10:22:54
@Author  :   xiaosongsong
@Desc    :   None

写一个 RecentCounter 类来计算最近的请求。

它只有一个方法：ping(int t)，其中 t 代表以毫秒为单位的某个时间。

返回从 3000 毫秒前到现在的 ping 数。

任何处于 [t - 3000, t] 时间范围之内的 ping 都将会被计算在内，包括当前（指 t 时刻）的 ping。

保证每次对 ping 的调用都使用比之前更大的 t 值。

 

示例：

输入：inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
输出：[null,1,2,3,3]
 

提示：

每个测试用例最多调用 10000 次 ping。
每个测试用例会使用严格递增的 t 值来调用 ping。
每次调用 ping 都有 1 <= t <= 10^9。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-recent-calls
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MaxSize 10000
typedef struct
{
    int nums[MaxSize];
    int head;
    int tail;
} RecentCounter;

RecentCounter *recentCounterCreate()
{
    RecentCounter *new;
    new = (RecentCounter *)malloc(sizeof(RecentCounter));
    new->head = new->tail = 0;
    return new;
}
bool recentCounterEmpty(RecentCounter *obj)
{
    return obj->tail == obj->head;
}

bool recentCounterFull(RecentCounter *obj)
{
    return obj->tail >= MaxSize;
}
int recentCounterPing(RecentCounter *obj, int t)
{
    while (!recentCounterEmpty(obj))
    {
        if (obj->nums[obj->head] < t - 3000)
            obj->head++;
        else
            break;
    }
    obj->nums[obj->tail++] = t;
    return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter *obj)
{
    free(obj);
    obj = NULL;
}

int main()
{
    RecentCounter *queue;
    queue = recentCounterCreate();
    printf("%d,", recentCounterPing(queue, 1));
    printf("%d,", recentCounterPing(queue, 100));
    printf("%d,", recentCounterPing(queue, 3001));
    printf("%d,", recentCounterPing(queue, 3002));
    printf("%d,", recentCounterPing(queue, 3003));
    return 0;
}
