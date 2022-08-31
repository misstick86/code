package main

/*

leetcode: https://leetcode.cn/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
*/

func insertSort(p []int, v int) {
	i := 0
	for i < 3 {
		if p[i+1] > v {
			break
		}
		i++
	}
	for j := 1; j <= i; j++ {
		p[j-1] = p[j]
	}
	p[i] = v
}

func minimumSum(num int) int {
	p := make([]int, 4)
	for num != 0 {
		b := num % 10
		num = num / 10
		insertSort(p, b)
	}
	return p[0]*10 + p[3] + p[1]*10 + p[2]
}
func main() {
	num := 2932
	minimumSum(num)
}
