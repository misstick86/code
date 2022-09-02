/*
https://leetcode.cn/problems/search-a-2d-matrix-ii/
*/

package main

import "fmt"

func FindHalfPos(matrix [][]int, col int, row int, target int) (int, int) {
	if matrix[col][row] == target {
		return col, row
	} else if matrix[col][row] < target {
		col = col / 2
	} else {

	}
	return 0, 1
}

func searchMatrix(matrix [][]int, target int) bool {
	col := len(matrix)
	row := len(matrix[0])
	posCol, posRow := FindHalfPos(matrix, col, row, target)
	fmt.Println(posCol, posRow)
	return false
}

func main() {
	matrix := [][]int{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}
	target := 5
	searchMatrix(matrix, target)
}
