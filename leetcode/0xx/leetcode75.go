/*
https://leetcode.cn/problems/sort-colors/
 插入排序
*/

package main

func Swap(a *int, b *int) {
	temp := *a
	*a = *b
	*b = temp
}

func sortColors(nums []int) {
	n := len(nums)
	for i := 1; i < n; i++ {
		temp := nums[i]
		var k int
		for k = i - 1; k >= 0; k-- {
			if nums[k] <= temp {
				break
			}
			Swap(&nums[k], &nums[k+1])
		}
	}
}
func main() {
	nums := []int{2, 0, 2, 1, 1, 0}
	sortColors(nums)
}
