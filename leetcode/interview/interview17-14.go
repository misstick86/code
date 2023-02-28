/*

	https://leetcode.cn/problems/smallest-k-lcci/

堆排序

*/

package main

func smallestK(arr []int, k int) []int {
	var temp int
	var j int
	for i := 1; i < len(arr); i++ {
		temp = arr[i]
		for j = i; j-1 >= 0 && temp < arr[j-1]; j-- {
			arr[j] = arr[j-1]
		}
		arr[j] = temp
	}
	return arr[:k]
}
func main() {
	node := []int{3, 5, 7, 2, 4, 1, 6, 8}
	smallestK(node, 4)
}
