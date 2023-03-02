/*
https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
*/

package main

func exchange(nums []int) []int {
	n := len(nums)
	first, last := 0, n-1
	for first < last {
		if nums[first]%2 == 0 && nums[last]%2 != 0 {
			nums[first], nums[last] = nums[last], nums[first]
		}
		if nums[first]%2 != 0 {
			first++
		}
		if nums[last]%2 == 0 {
			last--
		}
	}
	return nums

}

func main() {
	a := []int{1, 2, 3, 4}
	exchange(a)
}
