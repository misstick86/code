/*
https://leetcode.cn/problems/rotate-image/
*/

package main

func swap(a *int, b *int) {
	temp := *a
	*a = *b
	*b = temp
}

func rotate(matrix [][]int) {
	n := len(matrix)
	for i := 0; i < n/2; i++ {
		for j := i; j < n-i-1; j++ {
			k, m := i, j
			i, j = m, n-k-1
			swap(&matrix[k][m], &matrix[i][j])
			i, j = j, n-i-1
			swap(&matrix[k][m], &matrix[i][j])
			i, j = j, n-i-1
			swap(&matrix[k][m], &matrix[i][j])
			i, j = k, m
		}
	}
}

func main() {
	matrix := [][]int{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}}
	rotate(matrix)
}
