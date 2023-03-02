/*
https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
*/

package main

func majorityElement(nums []int) int {
	n := len(nums) - 1
	m := make(map[int]int, 0)
	for n >= 0 {
		if _, ok := m[nums[n]]; ok {
			m[nums[n]]++
			if m[nums[n]] > len(nums)/2 {
				return nums[n]
			}
		} else {
			m[nums[n]] = 1
		}

		n--

	}
	return -1
}

func main() {
	n := []int{6, 6, 6, 7, 7}
	majorityElement(n)
}
