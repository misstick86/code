/*
https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/description/
*/

package main

func GetPost(arr []int, start int) int {
	pos := 0
	min := arr[start]
	for i := start + 1; i < len(arr); i++ {
		if arr[i] < min {
			pos = i
			min = arr[i]
		}
	}
	return pos
}

func SelectSort(arr []int, k int) []int {
	for i := 0; i < k; i++ {
		pos := GetPost(arr, i)
		if pos != i {
			arr[pos], arr[i] = arr[i], arr[pos]
		}
	}
	return arr[:k]
}

func getLeastNumbers(arr []int, k int) []int {
	return SelectSort(arr, k)
}

func main() {
	n := []int{4, 5, 1, 6, 2, 7, 3, 8}
	getLeastNumbers(n, 4)
}
