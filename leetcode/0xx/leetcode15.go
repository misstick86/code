/*
15. 三数之和
15. 三数之和
提示
中等
5.7K
相关企业
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

提示：

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
package main

import "fmt"

func threeSum(nums []int) [][]int {
	sort(nums)
	n := len(nums)
	var result [][]int
	for first := 0; first < len(nums); first++ {
		if first > 0 && nums[first] == nums[first-1] {
			continue
		}
		last := n - 1
		target := -1 * nums[first]
		for mid := first + 1; mid < n; mid++ {
			if mid > first+1 && nums[mid] == nums[mid-1] {
				continue
			}
			for mid < last && nums[mid]+nums[last] > target {
				last--
			}
			if mid == last {
				break
			}
			if nums[mid]+nums[last] == target {
				result = append(result, []int{nums[first], nums[mid], nums[last]})
			}
		}
	}
	return result
}
func sort(s []int) {
	for i := 1; i < len(s); i++ {
		temp := s[i]
		if temp < s[i-1] {
			var j int
			for j = i - 1; s[j] > temp; j-- {
				s[j+1] = s[j]
				if j == 0 {
					j--
					break
				}
			}
			s[j+1] = temp
		}

	}
}
func main() {
	s := []int{0, 0, 0}
	p := threeSum(s)
	fmt.Println(p)
}
