package main

import "fmt"

func runningSum(nums []int) []int {
	var result []int
	k := 0
	for _, val := range nums {
		k += val
		result = append(result, k)
	}
	return result
}
func main() {
	n := []int{3, 1, 2, 10, 1}
	p := runningSum(n)
	fmt.Println(p)
}
