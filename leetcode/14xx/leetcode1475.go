/*
	leetcode: https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/
*/

package main

func findMin(item int, p []int) int {
	for _, v := range p {
		if v <= item {
			return v
		}
	}
	return 0
}

func finalPrices(prices []int) []int {
	for k, v := range prices {
		n := findMin(v, prices[k+1:])
		prices[k] = v - n
	}
	return prices
}
func main() {
	prices := []int{8, 4, 6, 2, 3}
	finalPrices(prices)
}
